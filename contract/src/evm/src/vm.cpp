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
#include <evm/gas_calculation.hpp>
#include <evm/gas_types.h>
#include <evm/call.hpp>
#include <evm/utils.hpp>

exec_result_t VM::execute(
  uint16_t stackDepth,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Operation> operation,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {

  exec_result_t result;

  jump_set_t jumps = Jumps::findDestinations(context->code);
  std::shared_ptr<ByteReader> reader = std::make_shared<ByteReader>(0);

  do {
    result = VM::step(
      stackDepth,
      jumps, 
      context,
      memory, 
      reader, 
      operation,
      gasCalculation,
      pendingState, 
      external
    );
  } while(result.first == ExecResult::CONTINUE);

  return result;
}

exec_result_t VM::step(
  uint16_t stackDepth,
  jump_set_t& jumps, 
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<ByteReader> reader, 
  std::shared_ptr<Operation> operation,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {

  if (gasometer->currentGas == 0) {
    return std::make_pair(ExecResult::VM_OUT_OF_GAS, 0);
  } else if (context->code->size() == 0) {
    return std::make_pair(ExecResult::DONE_VOID, gasometer->currentGas);
  } else {
    uint8_t opcode = reader->currentOp(context->code);
    instruct_t instruction = Instruction::values[opcode];
    reader->next();

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
          uint256_t returnDataSize = uint256_t(returnData.size());
          stack->push(returnDataSize);
          result = std::make_pair(InstructionResult::OK, 0);
          break;
        }
      case Opcode::RETURNDATACOPY:
        {
          uint64_t sourceOffset = Overflow::uint256Cast(stack->peek(1)).first;
          uint64_t sizeItem = Overflow::uint256Cast(stack->peek(2)).first;

          uint64_t returnDataLength = returnData.size();

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
          stack->pop(3);
          break;
        }
      case Opcode::CREATE:
      case Opcode::CREATE2:
        {
          result = executeCreateInstruction(
            stackDepth,
            opcode,
            requirements.provideGas,
            context,
            memory,
            operation,
            gasCalculation,
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
            opcode,
            requirements.provideGas,
            context,
            memory,
            operation,
            gasCalculation,
            pendingState,
            external
          );
          break;
        }
      default:
        result = std::invoke(
          operation->values[opcode], 
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
      case InstructionResult::OUT_OF_GAS:
        return std::make_pair(ExecResult::VM_OUT_OF_GAS, 0);
      case InstructionResult::UNUSED_GAS:
        {
          gas_t gasLeft = std::get<gas_t>(result.second);
          gasometer->currentGas = gasometer->currentGas + gasLeft;
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
    
    if (reader->atEnd(context->code)) return std::make_pair(ExecResult::DONE_VOID, gasometer->currentGas);

    return std::make_pair(ExecResult::CONTINUE, 0);
  }
}

instruction_result_t VM::executeCreateInstruction(
  uint16_t stackDepth,
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Operation> operation,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {
  uint256_t endowment;
  uint64_t initOff;
  uint64_t initSize;

  AddressScheme addressScheme; 
  uint256_t salt;
  uint256_t parentNonce = external->incrementContractNonce(context->address);

  switch (opcode) {
    case Opcode::CREATE:
      {
        addressScheme = AddressScheme::LEGACY;
        endowment = stack->peek(0);
        initOff = Overflow::uint256Cast(stack->peek(1)).first;
        initSize = Overflow::uint256Cast(stack->peek(2)).first;
        salt = parentNonce;
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

  returnData.clear();

  if (stackDepth > STACK_LIMIT) {
    stack->push(UINT256_ZERO);
    return std::make_pair(InstructionResult::UNUSED_GAS, createGas);
  }

  if (context->isStatic) return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_MUTATE_STATIC);

  std::shared_ptr<bytes_t> createCode = std::make_shared<bytes_t>(memory->readSlice(initOff, initSize));

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

  std::shared_ptr<Memory> createMemory = std::make_shared<Memory>();

  call_result_t callResult = Call::call(
    stackDepth,
    CallType::ACTION_CREATE,
    createMemory,
    createContext,
    operation,
    gasCalculation,
    external,
    pendingState
  );

  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        stack->push(UINT256_ONE);
        gas_t gasLeft = std::get<gas_t>(callResult.second);
        return std::make_pair(InstructionResult::UNUSED_GAS, gasLeft);
      }
    case MESSAGE_CALL_RETURN:
      {
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        bytes_t returnDataBytes = createMemory->readSlice(callReturn.offset, callReturn.size);

        uint256_t returnDataCost = uint256_t(returnDataBytes.size()) * uint256_t(CREATE_DATA_GAS);
        if (returnDataCost > callReturn.gasLeft || returnDataBytes.size() > MAX_CONTRACT_SIZE) {
          return std::make_pair(InstructionResult::OUT_OF_GAS, 0);
        }

        emplace_t emplaceResult = external->emplaceCode(
          context->address, 
          codeAddress,
          endowment, 
          returnDataBytes,
          pendingState
        );

        switch (emplaceResult.first) {
          case EmplaceResult::EMPLACE_SUCCESS:
            {
              stack->push(codeAddress);
              return std::make_pair(
                InstructionResult::UNUSED_GAS, 
                callReturn.gasLeft - Overflow::uint256Cast(returnDataCost).first
              );
            }
          case EmplaceResult::EMPLACE_CODE_ALREADY_EXISTS:
          case EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND:
            return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_INVALID_CODE_ADDRESS);
          case EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS:
            {
              stack->push(UINT256_ZERO);
              return std::make_pair(InstructionResult::UNUSED_GAS, callReturn.gasLeft);
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
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);      
    }
    case MESSAGE_CALL_FAILED:
      {
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);
      }
  }

  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t VM::executeCallInstruction(
  uint16_t stackDepth,
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<Operation> operation,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<PendingState> pendingState,
  std::shared_ptr<External> external
) {
  uint256_t codeAddress = stack->peek(1);
  uint256_t value = 0; 
  bool isStatic = context->isStatic;
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
        isStatic = true;
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
  uint256_t codeExecutionAddress;
  bool hasBalance;
  CallType callType;

  switch (opcode) {
    case Opcode::CALL:
      {
        if (isStatic && value > 0) return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_MUTATE_STATIC);
        senderAddress = context->address;
        receiveAddress = codeAddress;
        codeExecutionAddress = codeAddress;
        hasBalance = external->balance(context->address, pendingState) >= value;
        callType = CallType::ACTION_CALL;
        break;
      }
    case Opcode::CALLCODE:
      {
        senderAddress = context->address;
        receiveAddress = context->address;
        codeExecutionAddress = context->address;
        hasBalance = external->balance(context->address, pendingState) >= value;
        callType = CallType::ACTION_CALL;
        break;
      }
    case Opcode::DELEGATECALL:
      {
        senderAddress = context->sender;
        receiveAddress = context->address;
        codeExecutionAddress = context->codeAddress;
        hasBalance = true;
        callType = CallType::ACTION_CALL;
        break;
      }
    case Opcode::STATICCALL:
      {
        senderAddress = context->address;
        receiveAddress = codeAddress;
        codeExecutionAddress = codeAddress;
        hasBalance = true;
        callType = CallType::ACTION_STATIC_CALL;
        break;
      }
  }

  returnData.clear();

  uint64_t stipend = (value > 0) ? CALL_STIPEND : 0;
  gas_t callGas = providedGas;
  callGas = Overflow::add(callGas, stipend).first;

  if (!hasBalance || stackDepth > STACK_LIMIT) {
    stack->push(UINT256_ZERO);
    return std::make_pair(InstructionResult::UNUSED_GAS, callGas);
  }

  std::shared_ptr<bytes_t> callData = std::make_shared<bytes_t>(memory->readSlice(inOffset, inSize));
  std::shared_ptr<bytes_t> code = std::make_shared<bytes_t>(external->code(codeAddress, pendingState));

  std::shared_ptr<Context> callContext = Context::makeInnerCall(
    context,
    codeExecutionAddress,
    codeAddress, 
    receiveAddress, 
    senderAddress, 
    callGas, 
    context->gasPrice, 
    value, 
    isStatic,
    code,
    callData
  ); 

  std::shared_ptr<Memory> callMemory = std::make_shared<Memory>();

  call_result_t callResult = Call::call(
    stackDepth,
    callType,
    callMemory,
    callContext,
    operation,
    gasCalculation,
    external,
    pendingState
  );

  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        stack->push(UINT256_ONE);
        gas_t gasLeft = std::get<gas_t>(callResult.second);
        return std::make_pair(InstructionResult::UNUSED_GAS, gasLeft);
      }
    case MESSAGE_CALL_RETURN:
      {
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        returnData = callMemory->readSlice(callReturn.offset, callReturn.size);
        memory->writeSlice(outOffset, outSize, returnData);
        stack->push(UINT256_ONE);
        return std::make_pair(InstructionResult::UNUSED_GAS, callReturn.gasLeft);
      }
    case MESSAGE_CALL_REVERTED:
      {
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        stack->push(UINT256_ZERO);
        returnData = callMemory->readSlice(callReturn.offset, callReturn.size);
        memory->writeSlice(outOffset, outSize, returnData);
        return std::make_pair(InstructionResult::UNUSED_GAS, callReturn.gasLeft);
      }
    case MESSAGE_CALL_OUT_OF_GAS:
    {
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);      
    }
    case MESSAGE_CALL_FAILED:
      {
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);
      }
  }

  return std::make_pair(InstructionResult::OK, 0);
}