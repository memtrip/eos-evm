#include <algorithm>
#include <evm/vm.h>
#include <evm/opcode.h>
#include <evm/instruction.hpp>
#include <evm/jumps.hpp>
#include <evm/big_int.hpp>
#include <evm/hash.hpp>
#include <evm/overflow.hpp>
#include <evm/hex.hpp>
#include <evm/utils.hpp>
#include <evm/gas_calculation.hpp>

exec_result_t VM::execute(
  Operation& operation,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external
) {

  exec_result_t result;

  jump_set_t jumps = Jumps::findDestinations(context->code);
  std::shared_ptr<ByteReader> reader = std::make_shared<ByteReader>(0);
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  do {
    result = VM::step(
      operation,
      jumps, 
      context,
      gasCalculation,
      memory, 
      reader, 
      accountState, 
      external
    );
  } while(result.first == ExecResult::CONTINUE);

  return result;
}

exec_result_t VM::step(
  Operation& operation,
  jump_set_t& jumps, 
  std::shared_ptr<Context> context,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<ByteReader> reader, 
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external
) {
  // TODO: done check required?

  if (gasometer->currentGas == 0) {
    return std::make_pair(ExecResult::VM_OUT_OF_GAS, 0);
  } else if (context->code->size() == 0) {
    return std::make_pair(ExecResult::DONE_VOID, gasometer->currentGas);
  } else {
    return VM::stepInner(
      operation,
      jumps, 
      context,
      gasCalculation,
      memory, 
      reader, 
      accountState, 
      external
    );
  }
}

exec_result_t VM::stepInner(
  Operation& operation,
  jump_set_t& jumps,
  std::shared_ptr<Context> context,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<ByteReader> reader, 
  std::shared_ptr<AccountState> accountState,
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

  // Calculate gas cost requirements
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

  //printf(">> currentGas{%llu}\n", currentGas);

  gas_t memoryTotalGas = requirements.memoryTotalGas;
  gasometer->currentMemGas = memoryTotalGas;

  gas_t provideGas = requirements.provideGas;

  instruction_result_t result;
  switch (opcode) {
    case Opcode::RETURNDATASIZE:
      {
        stack->push(uint256_t(0));
        result = std::make_pair(InstructionResult::OK, 0);
        break;
      }
    case Opcode::RETURNDATACOPY:
      {
        result = std::make_pair(InstructionResult::OK, 0);
        break;
      }
    case Opcode::CREATE:
    case Opcode::CREATE2:
      {
        result = executeCreateInstruction(
          operation,
          opcode,
          provideGas,
          context,
          memory,
          accountState,
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
          operation,
          opcode,
          provideGas,
          context,
          memory,
          accountState,
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
        accountState,
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
  Operation& operation,
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external
) {
  uint64_t endowment = Overflow::uint256Cast(stack->peek(0)).first;
  uint256_t initOff = stack->peek(1);
  uint256_t initSize = stack->peek(2);
  stack->pop(3);

  uint256_t address;
  AddressScheme addressScheme; 

  switch (opcode) {
    case Opcode::CREATE:
      {
        address = context->sender;
        addressScheme = AddressScheme::LEGACY;
        break;
      }
    case Opcode::CREATE2:
      {
        address = stack->peek(0);
        addressScheme = AddressScheme::EIP_1014;
        stack->pop(1);
        break;
      }
  }

  std::shared_ptr<bytes_t> code = memory->readSlice(
    Overflow::uint256Cast(initOff).first, 
    Overflow::uint256Cast(initSize).first
  );
  
  emplace_t emplaceResult = external->emplaceCode(address, endowment, code, addressScheme);
  switch (emplaceResult.first) {
    case EmplaceResult::EMPLACE_SUCCESS:
      {
        address_t address = std::get<address_t>(emplaceResult.second);
        stack->push(BigInt::fromFixed32(address));

        // TODO: minus the gasLeft from the above gasCalcuation,
        // or perform the gasCalculation within call / execute and return in "gasLeft"

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          providedGas // TODO: calculate gas
        );
      }
    case EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND:
      {
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_INVALID_CODE_ADDRESS);
      }
    case EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS:
      {
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_INSUFFICIENT_FUNDS);
      }
  }

  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t VM::executeCallInstruction(
  Operation& operation,
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<AccountState> accountState,
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
  ActionType callType;

  switch (opcode) {
    case Opcode::CALL:
      {
        senderAddress = context->address;
        receiveAddress = codeAddress;
        hasBalance = external->balance(context->address) >= value;
        callType = ActionType::ACTION_CALL_CODE;
        break;
      }
    case Opcode::CALLCODE:
      {
        senderAddress = context->address;
        receiveAddress = context->address;
        hasBalance = external->balance(context->address) >= value;
        callType = ActionType::ACTION_CALL_CODE;
        break;
      }
    case Opcode::DELEGATECALL:
      {
        senderAddress = context->sender;
        receiveAddress = context->address;
        hasBalance = true;
        callType = ActionType::ACTION_DELEGATE_CALL;
        break;
      }
    case Opcode::STATICCALL:
      {
        senderAddress = context->address;
        receiveAddress = context->address;
        hasBalance = true;
        callType = ActionType::ACTION_STATIC_CALL;
        break;
      }
  }

  // TODO: stipend
  gas_t callGas = providedGas;

  if (!hasBalance) {
    // TODO: return unused gas
    stack->push(UINT256_ZERO);
    return std::make_pair(InstructionResult::OK, 0);
  }

  // TODO: check stack depth, err if too deep

  printf("inOffset{%llu}\n", inOffset);
  printf("inSize{%llu}\n", inSize);

  std::shared_ptr<bytes_t> callCode = memory->readSlice(inOffset, inSize);

  printf("callCode{%s}\n", Hex::bytesToHex(callCode).c_str());

  std::shared_ptr<Context> callContext = Context::makeInnerCall(
    context->chainId,
    context->blockNumber,
    context->timestamp,
    context->gasLimit,
    context->coinbase,
    context->difficulty,
    context->blockHash,
    codeAddress, 
    receiveAddress, 
    senderAddress, 
    callGas, 
    context->gasPrice, 
    value, 
    callCode
  );

  std::shared_ptr<bytes_t> callMemoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> callMemory = std::make_shared<Memory>(callMemoryBytes);

  // TODO: pass stack depth through the VM
  Call call = Call(0);

  call_result_t callResult = call.call(
    callMemory,
    callContext,
    external,
    accountState
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
    
        std::shared_ptr<bytes_t> returnDataBytes = callMemory->readSlice(callReturn.offset, callReturn.size);

        memory->writeSlice(outOffset, outSize, returnDataBytes);

        stack->push(UINT256_ONE);

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          callReturn.gasLeft
        );
      }
    case MESSAGE_CALL_REVERTED:
      {
        printf("MESSAGE_CALL_REVERTED");
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);
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