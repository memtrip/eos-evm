#include <algorithm>
#include <evm/vm.h>
#include <evm/opcode.h>
#include <evm/instruction.h>
#include <evm/jumps.h>
#include <evm/big_int.h>
#include <evm/hash.h>
#include <evm/overflow.h>
#include <evm/hex.h>
#include <evm/utils.h>
#include <evm/gas_calculation.h>

exec_result_t VM::execute(
  std::shared_ptr<Memory> memory,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Call> call
) {

  exec_result_t result;

  jump_set_t jumps = Jumps::findDestinations(context->code);
  std::shared_ptr<ByteReader> reader = std::make_shared<ByteReader>(0, context->code);
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();

  do {
    result = VM::step(
      jumps, 
      gasCalculation,
      memory, 
      reader, 
      accountState, 
      external, 
      call
    );
  } while(result.first == ExecResult::CONTINUE);

  return result;
}

exec_result_t VM::step(
  jump_set_t& jumps, 
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<ByteReader> reader, 
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Call> call
) {
  // TODO: done check required?

  if (gasometer.currentGas == 0) {
    return std::make_pair(ExecResult::VM_OUT_OF_GAS, 0);
  } else if (reader->len() == 0) {
    return std::make_pair(
      ExecResult::DONE, 
      std::make_pair(GasType::KNOWN, uint256_t(gasometer.currentGas))
    );
  } else {
    return VM::stepInner(
      jumps, 
      gasCalculation,
      memory, 
      reader, 
      accountState, 
      external, 
      call
    );
  }
}

exec_result_t VM::stepInner(
  jump_set_t& jumps,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<ByteReader> reader, 
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Call> call
) {
  uint8_t opcode = reader->bytes->at(reader->position);
  unsigned int instruction = Instruction::values[opcode];
  reader->position += 1;

  if (instruction == 0x000000FF) return std::make_pair(ExecResult::STOPPED, 0); // TODO: handle error

  instruction_verify_t verifyResult = Instruction::verify(instruction, stack->size());
  switch (verifyResult) {
    case InstructionVerifyResult::INSTRUCTION_ERROR_UNDER_FLOW:
    case InstructionVerifyResult::INSTRUCTION_ERROR_OUT_OF_STACK:
      return std::make_pair(ExecResult::STOPPED, 0); // TODO: handle error
    case InstructionVerifyResult::INSTRUCTION_VALID:
      break;
  }

  // Calculate gas cost requirements
  uint64_t memoryLength = memory->length();
  instruction_requirements_t calculateRequirements = gasometer.requirements(
    opcode,
    instruction, 
    memoryLength,
    gasCalculation,
    stack, 
    external
  );

  InstructionRequirements requirements;
  switch (calculateRequirements.first) {
    case InstructionRequirementsResult::INSTRUCTION_RESULT_OK:
      requirements = std::get<InstructionRequirements>(calculateRequirements.second);
      //Utils::printInstructionRequirements(requirements);
      break;
    case InstructionRequirementsResult::INSTRUCTION_RESULT_OUT_OF_GAS:
      return std::make_pair(ExecResult::VM_OUT_OF_GAS, 0);
    case InstructionRequirementsResult::INSTRUCTION_RESULT_ERROR:
      return std::make_pair(ExecResult::STOPPED, 0); // TODO: handle error
  }

  // expand memory
  gas_t memoryRequiredSize = requirements.memoryRequiredSize;
  memory->expand(memoryRequiredSize);
  
  gas_t currentGas = Overflow::sub(gasometer.currentGas, requirements.gasCost).first;
  gasometer.currentGas = currentGas;

  //printf(">> currentGas{%llu}\n", currentGas);

  gas_t memoryTotalGas = requirements.memoryTotalGas;
  gasometer.currentMemGas = memoryTotalGas;

  gas_t provideGas = requirements.provideGas;

  instruction_result_t result;
  switch (opcode) {
    case Opcode::RETURNDATASIZE:
      {
        printf("(RETURNDATASIZE ");
        result = std::make_pair(InstructionResult::OK, 0);
        break;
      }
    case Opcode::RETURNDATACOPY:
      {
        printf("(RETURNDATACOPY ");
        result = std::make_pair(InstructionResult::OK, 0);
        break;
      }
    case Opcode::CREATE:
    case Opcode::CREATE2:
      {
        printf("(CREATE / CREATE2 ");
        result = executeCreateInstruction(
          opcode,
          provideGas,
          memory,
          accountState,
          external,
          call
        );
        break;
      }
    case Opcode::CALL:
    case Opcode::CALLCODE:
    case Opcode::DELEGATECALL:
    case Opcode::STATICCALL:
      {
        printf("(CALL / CALLCODE / DELEGATECALL / STATICCALL ");
        result = executeCallInstruction(
          opcode,
          provideGas,
          memory,
          accountState,
          external,
          call
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
        uint256_t gasLeft = std::get<uint256_t>(result.second);
        gasometer.currentGas = gasometer.currentGas + static_cast<gas_t>(gasLeft);
        break;
      }
    case InstructionResult::JUMP_POSITION:
      {
        uint256_t position = std::get<uint256_t>(result.second);

        if (jumps.size() == 0) {
          // TODO: check jump position for child contracts?
          // i.e; resolve the jumps from the code attached to the VM
        }

        unsigned long pos = Jumps::verifyJump(position, jumps);
        if (pos == INVALID_ARGUMENT) return std::make_pair(ExecResult::STOPPED, 0); // TODO: handle error
        reader->position = pos;
        break;
      }
    case InstructionResult::STOP_EXEC_RETURN:
      {
        // TODO: clear memory
        StopExecutionResult stop = std::get<StopExecutionResult>(result.second);

        ReturnData returnData;
        bytes_t returnDataBytes = memory->readSlice(stop.initOff, stop.initSize);
        if (returnDataBytes.size() > 0) {
          returnData = {
            returnDataBytes,
            UINT256_ZERO,
            stop.initSize
          };
        } else {
          bytes_t empty = bytes_t();
          returnData = {
            empty,
            UINT256_ZERO,
            UINT256_ZERO
          };
        }
        
        NeedsReturn needsReturn {
          uint256_t(stop.gas),
          returnData,
          stop.apply
        };
        
        return std::make_pair(
          ExecResult::DONE, 
          std::make_pair(GasType::NEEDS_RETURN, needsReturn)
        );
      }
    case InstructionResult::STOP_EXEC:
      return std::make_pair(
        ExecResult::DONE, 
        std::make_pair(GasType::KNOWN, uint256_t(gasometer.currentGas))
      );
    case InstructionResult::INSTRUCTION_TRAP:
      break;
  }
  
  if (reader->position >= reader->len()) {
    return std::make_pair(
      ExecResult::DONE, 
      std::make_pair(GasType::KNOWN, uint256_t(gasometer.currentGas))
    );
  }

  return std::make_pair(ExecResult::CONTINUE, 0);
}

instruction_result_t VM::executeCreateInstruction(
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Call> call
) {
  uint256_t endowment = stack->peek(0);
  uint256_t initOff = stack->peek(1);
  uint256_t initSize = stack->peek(2);
  size_t outSize = static_cast<size_t>(initSize);
  stack->pop(3);

  uint256_t address;
  action_type_t callType; 

  switch (opcode) {
    case Opcode::CREATE:
      {
        address = context->address;
        callType = ActionType::ACTION_CREATE;
        break;
      }
    case Opcode::CREATE2:
      {
        address = stack->peek(0);
        callType = ActionType::ACTION_CREATE2;
        stack->pop(1);
        break;
      }
  }

  // TODO: check there is a high enough balance to perform create

  bytes_t contractCode = memory->readSlice(initOff, initSize);

  // TODO: create a new context for this child call
  // call_result_t callResult = call->create(
  //   providedGas,
  //   address, 
  //   uint256_t(endowment), 
  //   contractCode, 
  //   callType, 
  //   true, 
  //   context,
  //   external,
  //   accountState
  // );

  call_result_t callResult = call->create(
    true, 
    context,
    external,
    accountState
  );
  
  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        printf("MESSAGE_CALL_SUCCESS");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        uint256_t gasLeft = callReturn.gasLeft;

        // TODO: Address should come from cal_result_t
        stack->push(address);

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          gasLeft
        );
      }
    case MESSAGE_CALL_REVERTED:
      {
        printf("MESSAGE_CALL_REVERTED");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        uint256_t gasLeft = callReturn.gasLeft;

        stack->push(UINT256_ZERO);

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          gasLeft
        );
      }
    case MESSAGE_CALL_OUT_OF_GAS:
    case MESSAGE_CALL_FAILED:
    case MESSAGE_CALL_TRACE:
      {
        printf("MESSAGE_CALL_FAILED");
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);
      }
  }

  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t VM::executeCallInstruction(
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Call> call
) {
  uint256_t codeAddress = stack->peek(0);

  size_t stackOffset = 0;
  uint64_t value;

  switch (opcode) {
    case Opcode::DELEGATECALL:
      {
        value = 0;
        break;
      }
    case Opcode::STATICCALL:
      {
        value = 0;
        break;
      }
    default:
      {
        value = static_cast<uint64_t>(stack->peek(1));
        stackOffset += 1;
        break;
      }
  }

  uint256_t inOffset = stack->peek(1 + stackOffset);
  uint256_t inSize = stack->peek(2 + stackOffset);
  uint256_t outOffset = stack->peek(3 + stackOffset);
  size_t outSize = static_cast<size_t>(stack->peek(4 + stackOffset));

  stack->pop(5 + stackOffset);

  // TODO: stipend

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

  // TODO: if there is not enough balance, or the stack depth is reached, return 0

  bytes_t input = memory->readSlice(inOffset, inSize);
  // TODO: external call with result

  // TODO: create a new context for this child call
  // call_result_t callResult = call->call(
  //   providedGas,
  //   senderAddress, 
  //   receiveAddress, 
  //   uint256_t(value), 
  //   input, 
  //   codeAddress, 
  //   callType, 
  //   true, 
  //   env,
  //   external,
  //   accountState
  // );

  call_result_t callResult = call->call(
    true, 
    context,
    external,
    accountState
  );

  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        printf("MESSAGE_CALL_SUCCESS");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        uint256_t gasLeft = callReturn.gasLeft;
    
        bytes_t outBytes(
          callReturn.returnData.mem.begin(), 
          callReturn.returnData.mem.begin() + outSize
        );
        memory->writeSlice(outOffset, outBytes);

        stack->push(UINT256_ONE);

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          gasLeft
        );
      }
    case MESSAGE_CALL_REVERTED:
      {
        printf("MESSAGE_CALL_REVERTED");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
        uint256_t gasLeft = callReturn.gasLeft;

        bytes_t outBytes(
          callReturn.returnData.mem.begin(), 
          callReturn.returnData.mem.begin() + outSize
        );
        memory->writeSlice(outOffset, outBytes);

        stack->push(UINT256_ZERO);

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          gasLeft
        );
      }
    case MESSAGE_CALL_OUT_OF_GAS:
    case MESSAGE_CALL_FAILED:
    case MESSAGE_CALL_TRACE:
      {
        printf("MESSAGE_CALL_FAILED");
        stack->push(UINT256_ZERO);
        return std::make_pair(InstructionResult::OK, 0);
      }
  }

  return std::make_pair(InstructionResult::OK, 0);
}