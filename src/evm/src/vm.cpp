#include <evm/vm.h>
#include <evm/opcode.h>
#include <evm/instruction.h>
#include <evm/jumps.h>
#include <evm/big_int.h>
#include <evm/hash.h>
#include <evm/overflow.h>
#include <evm/hex.h>
#include <evm/utils.h>

exec_result_t VM::execute(
  Memory& memory,
  StackMachine& stack, 
  AccountState& accountState,
  params_t& params,
  env_t env
) {

  exec_result_t result;

  jump_set_t jumps = Jumps::findDestinations(params.data);
  ByteReader reader(0, params.data);

  do {
    result = VM::step(jumps, memory, stack, reader, accountState, params, env);
  } while(result.first == ExecResult::CONTINUE);

  return result;
}

exec_result_t VM::step(
  jump_set_t& jumps, 
  Memory& memory,
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState,
  params_t& params,
  env_t env
) {
  return VM::stepInner(jumps, memory, stack, reader, accountState, params, env);
}

exec_result_t VM::stepInner(
  jump_set_t& jumps,
  Memory& memory,
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState,
  params_t& params,
  env_t env
) {
  unsigned char opcode = reader.bytes[reader.position];
  unsigned int instruction = Instruction::values[opcode];
  reader.position += 1;

  // TODO: handle this properly with an invalid instruction error 
  if (instruction == 0x000000FF) return std::make_pair(ExecResult::DONE, 0);

  last_stack_ret_len = Instruction::ret(instruction);

  // TODO: verify instruction

  // TODO: calculate gas cost

  instruction_result_t result = VM::executeInstruction(
    instruction, 
    memory,
    stack,
    reader, 
    accountState,
    params,
    env
  );

  switch (result.first) {
    case InstructionResult::OK:
      break;
    case InstructionResult::UNUSED_GAS:
      break;
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

        NeedsReturn needsReturn {
          uint256_t(0),
          memory.intoReturnData(stop.initOff, stop.initSize),
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
      std::make_pair(GasType::KNOWN, uint256_t(0))
    );
  }

  return std::make_pair(ExecResult::CONTINUE, 0);
}

instruction_result_t VM::executeInstruction(
  instruct_t instruction,
  Memory& memory,
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState,
  params_t& params,
  env_t env
) {
  switch (Instruction::opcode(instruction)) {
    case Opcode::STOP: {
      return std::make_pair(InstructionResult::STOP_EXEC, 0);
    }
    case Opcode::ADD:
      {
        // TODO: handle arthemetic overflows
        uint256_t result = stack.peek(0) + stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::MUL:
      {
        // TODO: handle arthemetic overflows
        uint256_t result = stack.peek(0) * stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::SUB:
      {
        // TODO: handle arthemetic overflows
        uint256_t result = stack.peek(0) - stack.peek(1);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::DIV:
      {
        // TODO: handle arthemetic overflows
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
        // TODO: handle arthemetic overflows
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
      printf("(ADDRESS ");
      break;
    case Opcode::BALANCE:
      printf("(BALANCE ");
      break;
    case Opcode::ORIGIN:
      printf("(ORIGIN ");
      break;
    case Opcode::CALLER:
      printf("(CALLER ");
      break;
    case Opcode::CALLVALUE:
      stack.push(params.value);
      break;
    case Opcode::CALLDATALOAD:
      printf("(CALLDATALOAD ");
      break;
    case Opcode::CALLDATASIZE:
      printf("(CALLDATASIZE ");
      break;
    case Opcode::CALLDATACOPY:
      printf("(CALLDATACOPY ");
      break;
    case Opcode::CODESIZE:
      printf("(CODESIZE ");
      break;
    case Opcode::CODECOPY:
      printf("(CODECOPY ");
      break;
    case Opcode::GASPRICE:
      printf("(GASPRICE ");
      break;
    case Opcode::EXTCODESIZE:
      printf("(EXTCODESIZE ");
      break;
    case Opcode::EXTCODECOPY:
      printf("(EXTCODECOPY ");
      break;
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
        stack.push(StackMachine::STUB);
      }
      break;
    case Opcode::COINBASE:
      stack.push(StackMachine::STUB);
      break;
    case Opcode::TIMESTAMP:
      stack.push(env.timestamp);
      break;
    case Opcode::NUMBER:
      stack.push(env.blockNumber);
      break;
    case Opcode::DIFFICULTY:
      stack.push(StackMachine::STUB);
      break;
    case Opcode::GASLIMIT:
      stack.push(env.gasLimit);
      break;
    case Opcode::CHAINID:
      stack.push(env.chainId);
      break;
    case Opcode::SELFBALANCE:
      printf("(SELFBALANCE ");
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
      stack.push(uint256_t(memory.length()));
      break;
    case Opcode::GAS:
      printf("(GAS ");
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
      printf("(LOG0 ");
      break;
    case Opcode::LOG1:
      printf("(LOG1 ");
      break;
    case Opcode::LOG2:
      printf("(LOG2 ");
      break;
    case Opcode::LOG3:
      printf("(LOG3 ");
      break;
    case Opcode::LOG4:
      printf("(LOG4 ");
      break;

    case Opcode::CREATE:
      printf("(CREATE ");
      break;
    case Opcode::RETURN:
      {
        uint256_t initOff = stack.peek(0);
        uint256_t initSize = stack.peek(1);
        stack.pop(2);

        StopExecutionResult result {
          initOff,
          initSize,
          true
        };
        
        return std::make_pair(
          InstructionResult::STOP_EXEC_RETURN,
          result
        );
      }
    case Opcode::CREATE2:
      printf("(CREATE2 ");
      break;
    case Opcode::CALL:
      printf("(CALL ");
      break;
    case Opcode::CALLCODE:
      printf("(CALLCODE ");
      break;
    case Opcode::DELEGATECALL:
      {
        uint256_t codeAddress = stack.peek(0);
        uint256_t inOffset = stack.peek(1);
        uint256_t inSize = stack.peek(2);
        uint256_t outOffset = stack.peek(3);
        uint256_t outSize = stack.peek(4);
        stack.pop(5);

        // TODO: if there is not enough balance, or the stack depth is reached, return 0

        bytes_t input = memory.readSlice(inOffset, inSize);
        // TODO: external call with result

        break;
      }
    case Opcode::STATICCALL:
      printf("(STATICCALL ");
      break;
    case Opcode::REVERT:
      {
        uint256_t initOff = stack.peek(0);
        uint256_t initSize = stack.peek(1);
        stack.pop(2);

        StopExecutionResult result {
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