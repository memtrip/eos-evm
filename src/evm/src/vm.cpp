#include <evm/vm.h>
#include <evm/opcode.h>
#include <evm/instruction.h>
#include <evm/jumps.h>
#include <evm/big_int.h>
#include <evm/hash.h>
#include <evm/overflow.h>
#include <evm/hex.h>
#include <evm/utils.h>

VM::VM() {
  returnData = ReturnData::empty();
}

exec_result_t VM::execute(
  Memory& memory,
  StackMachine& stack, 
  AccountState& accountState,
  Gasometer& gasometer,
  params_t& params,
  External& external,
  Call& call,
  env_t env
) {

  exec_result_t result;

  jump_set_t jumps = Jumps::findDestinations(params.code);
  ByteReader reader(0, params.code);

  do {
    result = VM::step(
      jumps, 
      memory, 
      stack, 
      reader, 
      accountState, 
      gasometer, 
      params,
      external, 
      call, 
      env
    );
  } while(result.first == ExecResult::CONTINUE);

  return result;
}

exec_result_t VM::step(
  jump_set_t& jumps, 
  Memory& memory,
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState,
  Gasometer& gasometer,
  params_t& params,
  External& external,
  Call& call,
  env_t env
) {
  return VM::stepInner(
    jumps, 
    memory, 
    stack, 
    reader, 
    accountState, 
    gasometer, 
    params, 
    external, 
    call, 
    env
  );
}

exec_result_t VM::stepInner(
  jump_set_t& jumps,
  Memory& memory,
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState,
  Gasometer& gasometer,
  params_t& params,
  External& external,
  Call& call,
  env_t env
) {
  uint8_t opcode = reader.bytes[reader.position];
  unsigned int instruction = Instruction::values[opcode];
  reader.position += 1;

  if (instruction == 0x000000FF) return std::make_pair(ExecResult::STOPPED, 0); // TODO: handle error

  last_stack_ret_len = Instruction::ret(instruction);

  instruction_verify_t verifyResult = Instruction::verify(instruction, stack);
  switch (verifyResult) {
    case InstructionVerifyResult::INSTRUCTION_ERROR_UNDER_FLOW:
    case InstructionVerifyResult::INSTRUCTION_ERROR_OUT_OF_STACK:
      return std::make_pair(ExecResult::STOPPED, 0); // TODO: handle error
    case InstructionVerifyResult::INSTRUCTION_VALID:
      break;
  }

  // Calculate gas cost requirements
  instruction_requirements_t calculateRequirements = gasometer.requirements(external, instruction, stack, memory.length());

  InstructionRequirements requirements;
  switch (calculateRequirements.first) {
    case InstructionRequirementsResult::INSTRUCTION_RESULT_OK:
      requirements = std::get<InstructionRequirements>(calculateRequirements.second);
      break;
    case InstructionRequirementsResult::INSTRUCTION_RESULT_ERROR:
      return std::make_pair(ExecResult::STOPPED, 0); // TODO: handle error
  }

  // expand memory
  gas_t memoryRequiredSize = requirements.memoryRequiredSize;
  memory.expand(memoryRequiredSize);

  gas_t currentGas = gasometer.currentGas - requirements.gasCost;
  gasometer.currentGas = currentGas;

  gas_t memoryTotalGas = requirements.memoryTotalGas;
  gasometer.currentMemGas = memoryTotalGas;

  gas_t provideGas = requirements.provideGas;

  instruction_result_t result = VM::executeInstruction(
    currentGas,
    provideGas,
    instruction, 
    memory,
    stack,
    reader, 
    accountState,
    params,
    external,
    call,
    env
  );

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
        reader.position = pos;
        break;
      }
    case InstructionResult::STOP_EXEC_RETURN:
      {
        // TODO: clear memory
        // TODO: return actual GAS value
        StopExecutionResult stop = std::get<StopExecutionResult>(result.second);

        ReturnData intoReturnData = memory.intoReturnData(stop.initOff, stop.initSize);

        NeedsReturn needsReturn {
          uint256_t(stop.gas),
          intoReturnData,
          stop.apply
        };
        
        return std::make_pair(
          ExecResult::DONE, 
          std::make_pair(GasType::NEEDS_RETURN, needsReturn)
        );
      }
    case InstructionResult::STOP_EXEC:
      // TODO: return the amount of gas left, before execution was stopped
      return std::make_pair(ExecResult::DONE, 0);
    case InstructionResult::INSTRUCTION_TRAP:
      break;
  }
  
  if (reader.position >= reader.len()) {
    // TODO: return value from gasometer
    return std::make_pair(
      ExecResult::DONE, 
      std::make_pair(GasType::KNOWN, uint256_t(gasometer.currentGas))
    );
  }

  return std::make_pair(ExecResult::CONTINUE, 0);
}

instruction_result_t VM::executeInstruction(
  gas_t gas,
  gas_t providedGas,
  instruct_t instruction,
  Memory& memory,
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState,
  params_t& params,
  External& external,
  Call& call,
  env_t env
) {
  switch (Instruction::opcode(instruction)) {
    case Opcode::STOP: {
      return std::make_pair(InstructionResult::STOP_EXEC, 0);
    }
    case Opcode::ADD:
      {
        uint256_t result = stack.peek(0) + stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::MUL:
      {
        uint256_t result = stack.peek(0) * stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::SUB:
      {
        uint256_t result = stack.peek(0) - stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::DIV:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);

        if (b == 0) {
          stack.pop(2);
          stack.push(uint256_t(0));
        } else {
          stack.pop(2);
          stack.push(a / b);
        }
        break;
      }
    case Opcode::SDIV:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        stack.pop(2);
        stack.push(b != 0 ? intx::sdivrem(a, b).quot : 0);
        break;
      }
    case Opcode::MOD:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        if (b == 0) {
          stack.pop(2);
          stack.push(uint256_t(0));
        } else {
          stack.pop(2);
          stack.push(a % b);
        }
        break;
      }
    case Opcode::SMOD:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        stack.pop(2);
        stack.push(b != 0 ? intx::sdivrem(a, b).rem : 0);
        break;
      }
    case Opcode::ADDMOD:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        uint256_t c = stack.peek(2);
        stack.pop(3);
        stack.push(c != 0 ? intx::addmod(a, b, c) : 0);
        break;
      }
    case Opcode::MULMOD:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        uint256_t c = stack.peek(2);
        stack.pop(3);
        stack.push(c != 0 ? intx::mulmod(a, b, c) : 0);
        break;
      }
    case Opcode::EXP:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        stack.pop(2);

        stack.push(intx::exp(a, b));
        break;
      }
    case Opcode::SIGNEXTEND:
      {
        uint256_t ext = stack.peek(0);
        uint256_t x = stack.peek(1);
        stack.pop(1);
        if (ext < 31) {
          stack.pop(1);
          auto sign_bit = static_cast<int>(ext) * 8 + 7;
          auto sign_mask = uint256_t{1} << sign_bit;
          auto value_mask = sign_mask - 1;
          auto is_neg = (x & sign_mask) != 0;
          stack.push(is_neg ? x | ~value_mask : x & value_mask);
        }
        break;
      }
    case Opcode::LT:
      {
        bool result = stack.peek(0) < stack.peek(1);
        stack.pop(2);
        stack.pushBool(result);
        break;
      }
    case Opcode::GT:
      {
        bool result = stack.peek(0) > stack.peek(1);
        stack.pop(2);
        stack.pushBool(result);
        break;
      }
    case Opcode::SLT:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        stack.pop(2);

        bool x_neg = static_cast<bool>(a >> 255);
        bool y_neg = static_cast<bool>(b >> 255);

        stack.pushBool((x_neg ^ y_neg) ? x_neg : a < b);
        break;
      }
    case Opcode::SGT:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        stack.pop(2);

        bool x_neg = static_cast<bool>(a >> 255);
        bool y_neg = static_cast<bool>(b >> 255);

        stack.pushBool((x_neg ^ y_neg) ? y_neg : a < b);
        break;
      }
    case Opcode::EQ:
      {
        bool result = stack.peek(0) == stack.peek(1);
        stack.pop(2);
        stack.pushBool(result);
        break;
      }
    case Opcode::ISZERO:
      {
        bool result = stack.peek(0) == 0;
        stack.pop(1);
        stack.pushBool(result);
        break;
      }
    case Opcode::AND:
      {
        uint256_t result = stack.peek(0) & stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::OR:
      {
        uint256_t result = stack.peek(0) | stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::XOR:
      {
        uint256_t result = stack.peek(0) ^ stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::NOT:
      {
        uint256_t item = stack.peek(0);
        stack.pop(1);
        stack.push(~item);
        break;
      }
    case Opcode::BYTE:
      {
        uint256_t word = stack.peek(0);
        uint256_t val = stack.peek(1);
        stack.pop(2);
        if (word < uint256_t(32)) {
          uint64_t word64 = static_cast<uint64_t>(word);
          stack.push(val >> (8 * (31 - word64)) & uint256_t(0xff));
        } else {
          stack.push(uint256_t(0));
        }
        break;
      }
    case Opcode::SHL:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        stack.pop(2);
        stack.push(b <<= a);
        break;
      }
    case Opcode::SHR:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        stack.pop(2);
        stack.push(b >>= a);
        break;
      }
    case Opcode::SAR:
      {
        uint256_t a = stack.peek(0);
        uint256_t b = stack.peek(1);
        
        if ((b & (uint256_t{1} << 255)) == 0) {
          stack.push(b >>= a);
        } else {
          constexpr auto allones = ~uint256_t{};
          if (a >= 256) {
            stack.push(allones);
          } else {
            const auto shift = static_cast<unsigned>(a);
            stack.push((b >> shift) | (allones << (256 - shift)));
          }
        }

        break;
      }
    case Opcode::SHA3:
      {
        uint256_t offset = stack.peek(0);
        uint256_t size = stack.peek(1);
        stack.pop(2);
        bytes_t bytes = memory.readSlice(offset, size);
        stack.push(BigInt::fromBigEndianBytes(Hash::keccak256(bytes)));
        break;
      }
    case Opcode::ADDRESS:
      stack.push(params.address);
      break;
    case Opcode::BALANCE:
      printf("(BALANCE ");
      break;
    case Opcode::ORIGIN:
      stack.push(params.origin);
      break;
    case Opcode::CALLER:
      stack.push(params.sender);
      break;
    case Opcode::CALLVALUE:
      stack.push(params.value);
      break;
    case Opcode::CALLDATALOAD:
      {
        uint256_t index = stack.peek(0);
        if (params.data.size() < index) {
          stack.push(StackMachine::FALSE);
        } else {
          size_t begin = static_cast<size_t>(index);
          stack.push(BigInt::load32(begin, params.data));
        }
        break;
      }
    case Opcode::CALLDATASIZE:
      stack.push(uint256_t(params.data.size()));
      break;
    case Opcode::CALLDATACOPY:
      {
        uint256_t destOffset = stack.peek(0);
        uint256_t sourceOffset = stack.peek(1);
        uint256_t sizeItem = stack.peek(2);
        stack.pop(3);

        bytes_t dataBytes = params.data;

        memory.copyData(
          destOffset, 
          sourceOffset, 
          sizeItem, 
          dataBytes
        );
        break;
      }
    case Opcode::CODESIZE:
      stack.push(uint256_t(reader.bytes.size()));
      break;
    case Opcode::CODECOPY:
      {
        uint256_t destOffset = stack.peek(0);
        uint256_t sourceOffset = stack.peek(1);
        uint256_t sizeItem = stack.peek(2);
        stack.pop(3);

        bytes_t codeBytes = reader.bytes;

        memory.copyData(
          destOffset, 
          sourceOffset, 
          sizeItem, 
          codeBytes
        );
        break;
      }
    case Opcode::GASPRICE:
      stack.push(uint256_t(params.gasPrice));
      break;
    case Opcode::EXTCODESIZE:
      {
        uint256_t address = stack.peek(0);
        stack.pop(1);
        size_t codeSize = external.code(address).size();
        stack.push(uint256_t(codeSize));
        break;
      }
    case Opcode::EXTCODECOPY:
      {
        uint256_t address = stack.peek(0);
        stack.pop(1);
        bytes_t code = external.code(address);

        uint256_t destOffset = stack.peek(0);
        uint256_t sourceOffset = stack.peek(1);
        uint256_t sizeItem = stack.peek(2);
        stack.pop(3);

        memory.copyData(
          destOffset, 
          sourceOffset, 
          sizeItem, 
          code
        );
        break;
      }
    case Opcode::RETURNDATASIZE:
      printf("(RETURNDATASIZE ");
      break;
    case Opcode::RETURNDATACOPY:
      printf("(RETURNDATACOPY ");
      break;
    case Opcode::EXTCODEHASH:
      printf("(EXTCODEHASH ");
      break;

    case Opcode::BLOCKHASH:
      {
        stack.pop(1);
        stack.push(env.blockHash);
      }
      break;
    case Opcode::COINBASE:
      stack.push(env.coinbase);
      break;
    case Opcode::TIMESTAMP:
      stack.push(env.timestamp);
      break;
    case Opcode::NUMBER:
      stack.push(env.blockNumber);
      break;
    case Opcode::DIFFICULTY:
      stack.push(env.difficulty);
      break;
    case Opcode::GASLIMIT:
      stack.push(env.gasLimit);
      break;
    case Opcode::CHAINID:
      stack.push(env.chainId);
      break;
    case Opcode::SELFBALANCE:
      stack.push(external.balance(params.address));
      break;
    case Opcode::POP:
      stack.pop(1);
      break;
    case Opcode::MLOAD:
      {
        uint256_t offset = stack.peek(0);
        stack.pop(1);
        uint256_t word = memory.read(offset);
        stack.push(word);
        break;
      }
    case Opcode::MSTORE:
      {
        uint256_t offset = stack.peek(0);
        uint256_t word = stack.peek(1);
        stack.pop(2);
        memory.write(offset, word);
        break;
      }
    case Opcode::MSTORE8:
      {
        uint256_t offset = stack.peek(0);
        uint256_t byte = stack.peek(1);
        stack.pop(2);
        memory.writeByte(offset, byte);
        break;
      }
    case Opcode::SLOAD:
      {
        uint256_t key = stack.peek(0);
        uint256_t word = accountState.get(key);
        stack.pop(1);
        stack.push(word);
        break;
      }
    case Opcode::SSTORE:
      {
        // TODO: support clear by index
        // TODO: gas calculations
        accountState.putTopPair(stack.stack);
        stack.pop(2);
        break;
      }
    case Opcode::JUMP:
      {
        uint256_t position = stack.peek(0);
        stack.pop(1);
        return std::make_pair(
          InstructionResult::JUMP_POSITION, 
          position
        );
      }
    case Opcode::JUMPI:
      {
        uint256_t condition = stack.peek(1);
        if (condition == StackMachine::TRUE) {
          uint256_t position = stack.peek(0);
          stack.pop(2);
          return std::make_pair(
            InstructionResult::JUMP_POSITION, 
            position
          );
        }
        break;
      }
    case Opcode::PC:
      stack.push(uint256_t(reader.position - 1));
      break;
    case Opcode::MSIZE:
      {
        size_t length = memory.length();
        stack.push(uint256_t(length));
        break;
      }
    case Opcode::GAS:
      stack.push(uint256_t(params.gas));
      break;
    case Opcode::JUMPDEST:
      // resolved in Jumps::findDestinations
      break;
    case Opcode::PUSH1:
    case Opcode::PUSH2:
    case Opcode::PUSH3:
    case Opcode::PUSH4:
    case Opcode::PUSH5:
    case Opcode::PUSH6:
    case Opcode::PUSH7:
    case Opcode::PUSH8:
    case Opcode::PUSH9:
    case Opcode::PUSH10:
    case Opcode::PUSH11:
    case Opcode::PUSH12:
    case Opcode::PUSH13:
    case Opcode::PUSH14:
    case Opcode::PUSH15:
    case Opcode::PUSH16:
    case Opcode::PUSH17:
    case Opcode::PUSH18:
    case Opcode::PUSH19:
    case Opcode::PUSH20:
    case Opcode::PUSH21:
    case Opcode::PUSH22:
    case Opcode::PUSH23:
    case Opcode::PUSH24:
    case Opcode::PUSH25:
    case Opcode::PUSH26:
    case Opcode::PUSH27:
    case Opcode::PUSH28:
    case Opcode::PUSH29:
    case Opcode::PUSH30:
    case Opcode::PUSH31:
    case Opcode::PUSH32:
      stack.push(reader.read(Instruction::pushBytes(instruction)));
      break;
    case Opcode::DUP1:
    case Opcode::DUP2:
    case Opcode::DUP3:
    case Opcode::DUP4:
    case Opcode::DUP5:
    case Opcode::DUP6:
    case Opcode::DUP7:
    case Opcode::DUP8:
    case Opcode::DUP9:
    case Opcode::DUP10:
    case Opcode::DUP11:
    case Opcode::DUP12:
    case Opcode::DUP13:
    case Opcode::DUP14:
    case Opcode::DUP15:
    case Opcode::DUP16:
      stack.push(stack.peek(Instruction::dupPosition(instruction)));
      break;
    case Opcode::SWAP1:
    case Opcode::SWAP2:
    case Opcode::SWAP3:
    case Opcode::SWAP4:
    case Opcode::SWAP5:
    case Opcode::SWAP6:
    case Opcode::SWAP7:
    case Opcode::SWAP8:
    case Opcode::SWAP9:
    case Opcode::SWAP10:
    case Opcode::SWAP11:
    case Opcode::SWAP12:
    case Opcode::SWAP13:
    case Opcode::SWAP14:
    case Opcode::SWAP15:
    case Opcode::SWAP16:
      stack.swapWithTop(Instruction::swapPosition(instruction));
      break;

    case Opcode::LOG0:
    case Opcode::LOG1:
    case Opcode::LOG2:
    case Opcode::LOG3:
    case Opcode::LOG4:
    {
      uint8_t numberOfTopics = Instruction::logTopics(instruction);
      uint256_t offset = stack.peek(0);
      uint256_t size = stack.peek(1);

      std::vector<uint256_t> topics = stack.peekMany(2, numberOfTopics); 

      stack.pop(2 + numberOfTopics);

      bytes_t bytes = memory.readSlice(offset, size);

      external.log(topics, bytes);
      
      break;
    }
    case Opcode::CREATE:
    case Opcode::CREATE2:
      {
        uint256_t endowment = stack.peek(0);
        uint256_t initOff = stack.peek(1);
        uint256_t initSize = stack.peek(2);
        size_t outSize = static_cast<size_t>(initSize);
        stack.pop(3);

        uint8_t createOpcode = Instruction::opcode(instruction);
        uint256_t address;
        action_type_t callType; 

        switch (createOpcode) {
          case Opcode::CREATE:
            address = params.address;
            callType = ActionType::ACTION_CREATE;
            break;
          case Opcode::CREATE2:
            {
              address = stack.peek(0);
              callType = ActionType::ACTION_CREATE2;
              stack.pop(1);
              break;
            }
        }

        this->returnData = ReturnData::empty();

        // TODO: check there is a high enough balance to perform create

        bytes_t contractCode = memory.readSlice(initOff, initSize);

        call_result_t callResult = call.create(
          providedGas,
          address, 
          uint256_t(endowment), 
          contractCode, 
          callType, 
          true, 
          env,
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
              stack.push(address);

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

              stack.push(UINT256_ZERO);

              this->returnData = callReturn.returnData.copy();

              return std::make_pair(
                InstructionResult::UNUSED_GAS,
                gasLeft
              );
            }
          case MESSAGE_CALL_FAILED:
            printf("MESSAGE_CALL_FAILED");
            stack.push(UINT256_ZERO);
            break;
        }

        break;
      }
    case Opcode::RETURN:
      {
        uint256_t initOff = stack.peek(0);
        uint256_t initSize = stack.peek(1);
        stack.pop(2);

        StopExecutionResult result {
          gas,
          initOff,
          initSize,
          true
        };
        
        return std::make_pair(
          InstructionResult::STOP_EXEC_RETURN,
          result
        );
      }
    case Opcode::CALL:
    case Opcode::CALLCODE:
    case Opcode::DELEGATECALL:
    case Opcode::STATICCALL:
      {
        uint256_t codeAddress = stack.peek(0);

        size_t stackOffset = 0;
        uint64_t value;

        uint8_t callOpcode = Instruction::opcode(instruction);

        switch (callOpcode) {
          case Opcode::DELEGATECALL:
            value = 0;
            break;
          case Opcode::STATICCALL:
            value = 0;
            break;
          default:
            {
              value = static_cast<uint64_t>(stack.peek(1));
              stackOffset += 1;
              break;
            }
        }

        uint256_t inOffset = stack.peek(1 + stackOffset);
        uint256_t inSize = stack.peek(2 + stackOffset);
        uint256_t outOffset = stack.peek(3 + stackOffset);
        size_t outSize = static_cast<size_t>(stack.peek(4 + stackOffset));

        stack.pop(5 + stackOffset);

        // TODO: stipend

        uint256_t senderAddress;
        uint256_t receiveAddress;
        bool hasBalance;
        ActionType callType;

        switch (callOpcode) {
          case Opcode::CALL:
            senderAddress = params.address;
            receiveAddress = codeAddress;
            hasBalance = external.balance(params.address) >= value;
            callType = ActionType::ACTION_CALL_CODE;
            break;
          case Opcode::CALLCODE:
            senderAddress = params.address;
            receiveAddress = params.address;
            hasBalance = external.balance(params.address) >= value;
            callType = ActionType::ACTION_CALL_CODE;
            break;
          case Opcode::DELEGATECALL:
            {
              senderAddress = params.sender;
              receiveAddress = params.address;
              hasBalance = true;
              callType = ActionType::ACTION_DELEGATE_CALL;
              break;
            }
          case Opcode::STATICCALL:
            {
              senderAddress = params.address;
              receiveAddress = params.address;
              hasBalance = true;
              callType = ActionType::ACTION_STATIC_CALL;
              break;
            }
        }

        this->returnData = ReturnData::empty();
        // TODO: if there is not enough balance, or the stack depth is reached, return 0

        bytes_t input = memory.readSlice(inOffset, inSize);
        // TODO: external call with result

        call_result_t callResult = call.call(
          providedGas,
          senderAddress, 
          receiveAddress, 
          uint256_t(value), 
          input, 
          codeAddress, 
          callType, 
          true, 
          env,
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
              memory.writeSlice(outOffset, outBytes);

              this->returnData = callReturn.returnData.copy();

              stack.push(UINT256_ONE);

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
              memory.writeSlice(outOffset, outBytes);

              this->returnData = callReturn.returnData.copy();

              stack.push(UINT256_ZERO);

              return std::make_pair(
                InstructionResult::UNUSED_GAS,
                gasLeft
              );
            }
          case MESSAGE_CALL_FAILED:
            printf("MESSAGE_CALL_FAILED");
            stack.push(UINT256_ZERO);
            break;
        }

        break;
      }
    case Opcode::REVERT:
      {
        uint256_t initOff = stack.peek(0);
        uint256_t initSize = stack.peek(1);
        stack.pop(2);

        StopExecutionResult result {
          gas,
          initOff,
          initSize,
          false
        };
        
        return std::make_pair(
          InstructionResult::STOP_EXEC_RETURN,
          result
        );
      }
    case Opcode::SELFDESTRUCT:
      printf("(SELFDESTRUCT ");
      break;
  }

  return std::make_pair(InstructionResult::OK, 0);
}