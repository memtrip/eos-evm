#include <algorithm>
#include <evm/vm.h>
#include <evm/opcode.h>
#include <evm/instruction.hpp>
#include <evm/jumps.hpp>
#include <evm/big_int.hpp>
#include <evm/hash.hpp>
#include <evm/overflow.hpp>
#include <evm/hex.hpp>
#include <evm/utils.h>
#include <evm/gas_calculation.hpp>

exec_result_t VM::execute(
  Operation& operation,
  std::shared_ptr<Context> context,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Call> call
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
      external, 
      call
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
  std::shared_ptr<External> external,
  std::shared_ptr<Call> call
) {
  // TODO: done check required?

  if (gasometer->currentGas == 0) {
    return std::make_pair(ExecResult::VM_OUT_OF_GAS, 0);
  } else if (context->code->size() == 0) {
    return std::make_pair(
      ExecResult::DONE, 
      std::make_pair(GasType::KNOWN, gasometer->currentGas)
    );
  } else {
    return VM::stepInner(
      operation,
      jumps, 
      context,
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
  Operation& operation,
  jump_set_t& jumps,
  std::shared_ptr<Context> context,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<Memory> memory,
  std::shared_ptr<ByteReader> reader, 
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Call> call
) {
  uint8_t opcode = reader->currentOp(context->code);
  unsigned int instruction = Instruction::values[opcode];
  reader->next();

  // Utils::printInstruction(instruction);

  instruction_verify_t verifyResult = Instruction::verify(instruction, stack->size());
  switch (verifyResult) {
    case InstructionVerifyResult::INSTRUCTION_ERROR_UNDER_FLOW:
      return std::make_pair(ExecResult::STOPPED, Trap::create(TrapKind::TRAP_STACK_UNDERFLOW, 0)); // TODO: handle error
    case InstructionVerifyResult::INSTRUCTION_ERROR_OUT_OF_STACK:
      return std::make_pair(ExecResult::STOPPED, Trap::create(TrapKind::TRAP_OUT_OF_STACK, 0)); // TODO: handle error
    case InstructionVerifyResult::INSTRUCTION_NOT_DEFINED:
      return std::make_pair(ExecResult::STOPPED, Trap::create(TrapKind::TRAP_INVALID_INSTRUCTION, 0)); // TODO: handle error
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
        printf("(CREATE / CREATE2 \n");
        result = executeCreateInstruction(
          operation,
          opcode,
          provideGas,
          context,
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
          operation,
          opcode,
          provideGas,
          context,
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
        gas_t gasLeft = std::get<gas_t>(result.second);
        gasometer->currentGas = gasometer->currentGas + gasLeft;
        printf("\n>> currentGas{%llu}\n", gasometer->currentGas);
        break;
      }
    case InstructionResult::JUMP_POSITION:
      {
        uint64_t position = std::get<uint64_t>(result.second);

        if (jumps.size() == 0) {
          // TODO: check jump position for child contracts?
          // i.e; resolve the jumps from the code attached to the VM
        }

        uint64_t pos = Jumps::verifyJump(position, jumps);
        if (pos == INVALID_ARGUMENT) return std::make_pair(ExecResult::STOPPED, Trap::jump(pos));
        reader->move(pos);
        break;
      }
    case InstructionResult::STOP_EXEC_RETURN:
      {
        // TODO: clear memory
        StopExecutionResult stop = std::get<StopExecutionResult>(result.second);

        SlicePosition slicePosition = {
          stop.initOff,
          stop.initSize
        };
        
        NeedsReturn needsReturn {
          stop.gas,
          slicePosition,
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
        std::make_pair(GasType::KNOWN, gasometer->currentGas)
      );
    case InstructionResult::INSTRUCTION_TRAP:
      break;
  }
  
  if (reader->atEnd(context->code)) {
    return std::make_pair(
      ExecResult::DONE, 
      std::make_pair(GasType::KNOWN, gasometer->currentGas)
    );
  }

  return std::make_pair(ExecResult::CONTINUE, 0);
}

instruction_result_t VM::executeCreateInstruction(
  Operation& operation,
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Context> context,
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
        printf("CREATE\n");
        address = context->sender;
        callType = ActionType::ACTION_CREATE;
        break;
      }
    case Opcode::CREATE2:
      {
        printf("CREATE2\n");
        address = stack->peek(0);
        callType = ActionType::ACTION_CREATE2;
        stack->pop(1);
        break;
      }
  }

  // TODO: check there is a high enough balance to perform create
  std::shared_ptr<bytes_t> contractCode = memory->readSlice(
    Overflow::uint256Cast(initOff).first, 
    Overflow::uint256Cast(initSize).first
  );

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

  // TODO: make create gas calculation

  std::shared_ptr<Context> innerContext = std::make_shared<Context>(
    context->chainId,
    context->blockNumber,
    context->timestamp,
    context->gasLimit,
    context->coinbase,
    context->difficulty,
    context->blockHash,
    address, /* codeAddress */
    context->codeHash,
    context->codeVersion,
    address, /* address */
    context->sender,
    context->origin,
    providedGas, /* gas */
    context->gasPrice,
    endowment, /* value */
    contractCode, /* code */
    std::shared_ptr<bytes_t>()
  );

  std::shared_ptr<bytes_t> callMemoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> callMemory = std::make_shared<Memory>(callMemoryBytes);

  call_result_t callResult = call->create(
    true, 
    callMemory,
    innerContext,
    external,
    accountState
  );
  
  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        printf("MESSAGE_CALL_SUCCESS");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);

        // TODO: Address should come from cal_result_t
        stack->push(address);

        // TODO: minus the gasLeft from the above gasCalcuation,
        // or perform the gasCalculation within call / execute and return in "gasLeft"

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          callReturn.gasLeft
        );
      }
    case MESSAGE_CALL_REVERTED:
      {
        printf("MESSAGE_CALL_REVERTED");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);

        stack->push(UINT256_ZERO);

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          callReturn.gasLeft
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
  Operation& operation,
  uint8_t opcode,
  gas_t providedGas,
  std::shared_ptr<Context> context,
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
  std::shared_ptr<bytes_t> input = memory->readSlice(
    Overflow::uint256Cast(inOffset).first, 
    Overflow::uint256Cast(inSize).first
  );
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

  std::shared_ptr<bytes_t> callMemoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> callMemory = std::make_shared<Memory>(callMemoryBytes);

  call_result_t callResult = call->call(
    true, 
    callMemory,
    context,
    external,
    accountState
  );

  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
      {
        printf("MESSAGE_CALL_SUCCESS");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);
    
        std::shared_ptr<bytes_t> returnDataBytes = callMemory->readSlice(callReturn.slicePosition.offset, callReturn.slicePosition.size);

        memory->writeSlice(Overflow::uint256Cast(outOffset).first, returnDataBytes);

        stack->push(UINT256_ONE);

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          callReturn.gasLeft
        );
      }
    case MESSAGE_CALL_REVERTED:
      {
        printf("MESSAGE_CALL_REVERTED");
        MessageCallReturn callReturn = std::get<MessageCallReturn>(callResult.second);

        std::shared_ptr<bytes_t> returnDataBytes = callMemory->readSlice(callReturn.slicePosition.offset, callReturn.slicePosition.size);

        memory->writeSlice(Overflow::uint256Cast(outOffset).first, returnDataBytes);

        stack->push(UINT256_ZERO);

        return std::make_pair(
          InstructionResult::UNUSED_GAS,
          callReturn.gasLeft
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