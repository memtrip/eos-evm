#include <algorithm>
#include <evm/vm.h>
#include <evm/opcode.h>
#include <evm/address.hpp>
#include <evm/instruction.hpp>
#include <evm/jumps.hpp>
#include <evm/big_int.hpp>
#include <evm/hash.hpp>
#include <evm/overflow.hpp>
#include <evm/hex.hpp>
#include <evm/utils.hpp>
#include <evm/gas_calculation.hpp>
#include <evm/gas_types.h>
#include <evm/call.hpp>

exec_result_t VM::execute(
  uint16_t stackDepth,
  Operation& operation,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {

  exec_result_t result;

  jump_set_t jumps = Jumps::findDestinations(context->code);
  std::shared_ptr<ByteReader> reader = std::make_shared<ByteReader>(0);
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  do {
    result = VM::step(
      stackDepth,
      operation,
      jumps, 
      context,
      gasCalculation,
      memory, 
      reader, 
      pendingState, 
      external
    );
  } while(result.first == ExecResult::CONTINUE);

  return result;
}

exec_result_t VM::step(
  uint16_t stackDepth,
  Operation& operation,
  jump_set_t& jumps, 
  std::shared_ptr<Context> context,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<ByteReader> reader, 
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {
  // TODO: done check required?

  if (gasometer->currentGas == 0) {
    return std::make_pair(ExecResult::VM_OUT_OF_GAS, 0);
  } else if (context->code->size() == 0) {
    return std::make_pair(ExecResult::DONE_VOID, gasometer->currentGas);
  } else {
    return VM::stepInner(
      stackDepth,
      operation,
      jumps, 
      context,
      gasCalculation,
      memory, 
      reader, 
      pendingState, 
      external
    );
  }
}

exec_result_t VM::stepInner(
  uint16_t stackDepth,
  Operation& operation,
  jump_set_t& jumps,
  std::shared_ptr<Context> context,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<ByteReader> reader, 
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {
  uint8_t opcode = reader->currentOp(context->code);
  unsigned int instruction = Instruction::values[opcode];
  reader->next();

  // Utils::printInstruction(instruction);

  instruction_verify_t verifyResult = Instruction::verify(instruction, stack->size());
  switch (verifyResult) {
    case InstructionVerifyResult::INSTRUCTION_ERROR_UNDER_FLOW:
      return std::make_pair(ExecResult::VM_TRAP, TrapKind::TRAP_STACK_UNDERFLOW);
    case InstructionVerifyResult::INSTRUCTION_ERROR_OUT_OF_STACK:
      return std::make_pair(ExecResult::VM_TRAP, TrapKind::TRAP_OUT_OF_STACK);
    case InstructionVerifyResult::INSTRUCTION_NOT_DEFINED:
      return std::make_pair(ExecResult::VM_TRAP, TrapKind::TRAP_INVALID_INSTRUCTION);
    case InstructionVerifyResult::INSTRUCTION_VALID:
      break;
  }

  uint64_t memoryLength = memory->length();
  instruction_requirements_t calculateRequirements = gasometer->requirements(
    opcode,
    instruction, 
    memoryLength,
    gasCalculation,
    context,
    stack, 
    external
  );

  GasRequirements requirements;
  switch (calculateRequirements.first) {
    case GasometerResult::GASOMETER_RESULT_OK:
      requirements = std::get<GasRequirements>(calculateRequirements.second);
      //Utils::printInstructionRequirements(requirements);
      break;
    case GasometerResult::GASOMETER_RESULT_OUT_OF_GAS:
      return std::make_pair(ExecResult::VM_OUT_OF_GAS, 0);
  }

  // expand memory
  gas_t memoryRequiredSize = requirements.memoryRequiredSize;
  memory->expand(memoryRequiredSize);
  
  gas_t currentGas = Overflow::sub(gasometer->currentGas, requirements.gasCost).first;
  gasometer->currentGas = currentGas;

  gas_t memoryTotalGas = requirements.memoryTotalGas;
  gasometer->currentMemGas = memoryTotalGas;

  gas_t provideGas = requirements.provideGas;

  instruction_result_t result;
  switch (opcode) {
    case Opcode::RETURNDATASIZE:
      {
        stack->push(uint256_t(returnData->size()));
        result = std::make_pair(InstructionResult::OK, 0);
        break;
      }
    case Opcode::RETURNDATACOPY:
      {
        uint64_t sourceOffset = Overflow::uint256Cast(stack->peek(1)).first;
        uint64_t sizeItem = Overflow::uint256Cast(stack->peek(2)).first;

        uint64_t returnDataLength = returnData->size();

        if (Overflow::add(sourceOffset, sizeItem).first > returnDataLength) {
          result = std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_OVERFLOW);
        } else {
          memory->copyData(
            Overflow::uint256Cast(stack->peek(0)).first, 
            sourceOffset, 
            sizeItem, 
            returnData
          );
          result = std::make_pair(InstructionResult::OK, 0);
        }
        break;
      }
    case Opcode::CREATE:
    case Opcode::CREATE2:
      {
        result = executeCreateInstruction(
          stackDepth,
          operation,
          opcode,
          requirements.provideGas,
          context,
          memory,
          pendingState,
          external
        );
        break;
      }
    case Opcode::CALL:
    case Opcode::CALLCODE:
    case Opcode::DELEGATECALL:
    case Opcode::STATICCALL:
      {
        result = executeCallInstruction(
          stackDepth,
          operation,
          opcode,
          requirements.provideGas,
          context,
          memory,
          pendingState,
          external
        );
        break;
      }
    default:
      result = std::invoke(
        operation.values[opcode], 
        operation, 
        currentGas,
        instruction, 
        context, 
        reader, 
        pendingState,
        external, 
        memory, 
        stack
      );
  }

  switch (result.first) {
    case InstructionResult::OK:
      break;
    case InstructionResult::UNUSED_GAS:
      {
        gas_t gasLeft = std::get<gas_t>(result.second);
        gasometer->currentGas = gasometer->currentGas + gasLeft;
        // printf("\n>> currentGas{%llu}\n", gasometer->currentGas);
        break;
      }
    case InstructionResult::JUMP_POSITION:
      {
        uint64_t position = std::get<uint64_t>(result.second);
        uint64_t pos = Jumps::verifyJump(position, jumps);
        if (pos == INVALID_ARGUMENT) return std::make_pair(ExecResult::VM_TRAP, TrapKind::TRAP_INVALID_JUMP);
        reader->move(pos);
        break;
      }
    case InstructionResult::STOP_EXEC_RETURN:
      {
        // TODO: clear memory
        StopExecutionResult stop = std::get<StopExecutionResult>(result.second);
        
        NeedsReturn needsReturn {
          stop.gas,
          stop.initOff,
          stop.initSize,
          stop.apply
        };
        
        return std::make_pair(ExecResult::DONE_RETURN, needsReturn);
      }
    case InstructionResult::STOP_EXEC:
      return std::make_pair(ExecResult::DONE_VOID, gasometer->currentGas);
    case InstructionResult::INSTRUCTION_TRAP:
      {
        trap_t trap = std::get<trap_t>(result.second);
        return std::make_pair(ExecResult::VM_TRAP, trap);
      }
  }
  
  if (reader->atEnd(context->code))
    return std::make_pair(ExecResult::DONE_VOID, gasometer->currentGas);

  return std::make_pair(ExecResult::CONTINUE, 0);
}

instruction_result_t VM::executeCreateInstruction(
  uint16_t stackDepth,
  Operation& operation,
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {
  uint256_t endowment;
  uint64_t initOff;
  uint64_t initSize;

  AddressScheme addressScheme; 
  uint256_t salt;

  switch (opcode) {
    case Opcode::CREATE:
      {
        addressScheme = AddressScheme::LEGACY;
        endowment = stack->peek(0);
        initOff = Overflow::uint256Cast(stack->peek(1)).first;
        initSize = Overflow::uint256Cast(stack->peek(2)).first;
        salt = external->incrementNonce();
        stack->pop(3);
        break;
      }
    case Opcode::CREATE2:
      {
        endowment = stack->peek(0);
        initOff = Overflow::uint256Cast(stack->peek(1)).first;
        initSize = Overflow::uint256Cast(stack->peek(2)).first;
        salt = stack->peek(3); 
        addressScheme = AddressScheme::EIP_1014;
        stack->pop(4);
        break;
      }
  }

  gas_t createGas = providedGas;

  returnData->clear();

  if (stackDepth > STACK_LIMIT) {
    stack->push(UINT256_ZERO);
    return std::make_pair(InstructionResult::UNUSED_GAS, createGas);
  }

  std::shared_ptr<bytes_t> createCode = memory->readSlice(initOff, initSize);

  uint256_t codeAddress = Address::makeCreateAddress(
    addressScheme,
    context->sender,
    salt,
    createCode
  );

  std::shared_ptr<Context> createContext = Context::makeInnerCreate(
    context,
    codeAddress, 
    createGas, 
    endowment,  
    createCode
  );

  std::shared_ptr<bytes_t> createMemoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> createMemory = std::make_shared<Memory>(createMemoryBytes);

  call_result_t callResult = Call::call(
    stackDepth,
    CallType::ACTION_CREATE,
    createMemory,
    createContext,
    external,
    pendingState
  );

  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        printf("MESSAGE_CALL_SUCCESS");
        stack->push(UINT256_ONE);
        gas_t gasLeft = std::get<gas_t>(callResult.second);
        return std::make_pair(InstructionResult::UNUSED_GAS, gasLeft);
      }
    case MESSAGE_CALL_RETURN:
      {
        printf("MESSAGE_CALL_RETURN");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
    
        std::shared_ptr<bytes_t> returnDataBytes = createMemory->readSlice(callReturn.offset, callReturn.size);

        emplace_t emplaceResult = external->emplaceCode(
          context->origin, 
          codeAddress,
          Overflow::uint256Cast(endowment).first, 
          returnDataBytes
        );

        switch (emplaceResult.first) {
          case EmplaceResult::EMPLACE_SUCCESS:
            {
              address_t address = std::get<address_t>(emplaceResult.second);
              stack->push(BigInt::fromFixed32(address));
              return std::make_pair(
                InstructionResult::UNUSED_GAS,
                callReturn.gasLeft
              );
            }
          case EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND:
            return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_INVALID_CODE_ADDRESS);
          case EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS:
            {
              stack->push(UINT256_ZERO);
              return std::make_pair(InstructionResult::UNUSED_GAS, createGas);
            }
        }
      }
    case MESSAGE_CALL_REVERTED:
      {
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        stack->push(UINT256_ZERO);
        returnData = createMemory->readSlice(callReturn.offset, callReturn.size);
        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          callReturn.gasLeft
        );
      }
    case MESSAGE_CALL_OUT_OF_GAS:
    {
        printf("MESSAGE_CALL_OUT_OF_GAS");
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);      
    }
    case MESSAGE_CALL_FAILED:
      {
        printf("MESSAGE_CALL_FAILED");
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);
      }
  }

  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t VM::executeCallInstruction(
  uint16_t stackDepth,
  Operation& operation,
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {
  uint256_t codeAddress = stack->peek(1);
  uint256_t value = 0; /* TODO: clarify, context->value */
  uint64_t inOffset;
  uint64_t inSize;
  uint64_t outOffset;
  uint64_t outSize;

  switch (opcode) {
    case Opcode::DELEGATECALL:
      {
        inOffset = Overflow::uint256Cast(stack->peek(2)).first;
        inSize = Overflow::uint256Cast(stack->peek(3)).first;
        outOffset = Overflow::uint256Cast(stack->peek(4)).first;
        outSize = Overflow::uint256Cast(stack->peek(5)).first;
        stack->pop(6);
        break;
      }
    case Opcode::STATICCALL:
      {
        inOffset = Overflow::uint256Cast(stack->peek(2)).first;
        inSize = Overflow::uint256Cast(stack->peek(3)).first;
        outOffset = Overflow::uint256Cast(stack->peek(4)).first;
        outSize = Overflow::uint256Cast(stack->peek(5)).first;
        stack->pop(6);
        break;
      }
    default:
      {
        value = stack->peek(2);
        inOffset = Overflow::uint256Cast(stack->peek(3)).first;
        inSize = Overflow::uint256Cast(stack->peek(4)).first;
        outOffset = Overflow::uint256Cast(stack->peek(5)).first;
        outSize = Overflow::uint256Cast(stack->peek(6)).first;
        stack->pop(7);
        break;
      }
  }

  uint256_t senderAddress;
  uint256_t receiveAddress;
  bool hasBalance;
  CallType callType;

  switch (opcode) {
    case Opcode::CALL:
      {
        senderAddress = context->address;
        receiveAddress = codeAddress;
        hasBalance = external->balance(context->address) >= value;
        callType = CallType::ACTION_CALL;
        break;
      }
    case Opcode::CALLCODE:
      {
        senderAddress = context->address;
        receiveAddress = context->address;
        hasBalance = external->balance(context->address) >= value;
        callType = CallType::ACTION_CALL;
        break;
      }
    case Opcode::DELEGATECALL:
      {
        senderAddress = context->sender;
        receiveAddress = context->address;
        hasBalance = true;
        callType = CallType::ACTION_CALL;
        break;
      }
    case Opcode::STATICCALL:
      {
        senderAddress = context->address;
        receiveAddress = context->address;
        hasBalance = true;
        callType = CallType::ACTION_STATIC_CALL;
        break;
      }
  }

  returnData->clear();

  uint64_t stipend = (value > 0) ? CALL_STIPEND : 0;
  gas_t callGas = providedGas;
  callGas = Overflow::add(callGas, stipend).first;

  if (!hasBalance || stackDepth > STACK_LIMIT) {
    stack->push(UINT256_ZERO);
    return std::make_pair(InstructionResult::UNUSED_GAS, callGas);
  }

  std::shared_ptr<bytes_t> callData = memory->readSlice(inOffset, inSize);
  printf("callData{%s}\n", Hex::bytesToHex(callData).c_str());

  std::shared_ptr<Context> callContext = Context::makeInnerCall(
    context,
    codeAddress, 
    receiveAddress, 
    senderAddress, 
    callGas, 
    context->gasPrice, 
    value, 
    callData,
    external
  ); 

  std::shared_ptr<bytes_t> callMemoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> callMemory = std::make_shared<Memory>(callMemoryBytes);

  call_result_t callResult = Call::call(
    stackDepth,
    callType,
    callMemory,
    callContext,
    external,
    pendingState
  );

  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        printf("MESSAGE_CALL_SUCCESS\n");
        stack->push(UINT256_ONE);
        gas_t gasLeft = std::get<gas_t>(callResult.second);
        return std::make_pair(InstructionResult::UNUSED_GAS, gasLeft);
      }
    case MESSAGE_CALL_RETURN:
      {
        printf("MESSAGE_CALL_RETURN\n");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        stack->push(UINT256_ONE);
        returnData = callMemory->readSlice(callReturn.offset, callReturn.size);
        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          callReturn.gasLeft
        );
      }
    case MESSAGE_CALL_REVERTED:
      {
        printf("MESSAGE_CALL_REVERTED\n");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        stack->push(UINT256_ZERO);
        returnData = callMemory->readSlice(callReturn.offset, callReturn.size);
        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          callReturn.gasLeft
        );
      }
    case MESSAGE_CALL_OUT_OF_GAS:
    {
        printf("MESSAGE_CALL_OUT_OF_GAS");
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);      
    }
    case MESSAGE_CALL_FAILED:
      {
        printf("MESSAGE_CALL_FAILED\n");
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);
      }
  }

  return std::make_pair(InstructionResult::OK, 0);
}