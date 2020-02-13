#include "vm.h"
#include "opcode.h"
#include "instruction.h"
#include "jumps.h"
#include "big_int.h"
#include "utils.h" // TODO: remove this

ExecResult VM::execute(std::vector<uint8_t> bytes, StackMachine& stack, AccountState& accountState) {
  ExecResult result;

  jump_set_t jumps = Jumps::findDestinations(bytes);
  ByteReader reader(0, bytes);

  do {
    result = VM::step(jumps, stack, reader, accountState);
  } while(result == ExecResult::CONTINUE);

  return result;
}

ExecResult VM::step(
  jump_set_t& jumps, 
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState
) {
  return VM::stepInner(jumps, stack, reader, accountState);
}

ExecResult VM::stepInner(
  jump_set_t& jumps,
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState
) {
  unsigned char opcode = reader.bytes[reader.position];
  unsigned int instruction = Instruction::values[opcode];
  reader.position += 1;

  // TODO: handle this properly with an invalid instruction error 
  if (instruction == 0x000000FF) return ExecResult::DONE;

  last_stack_ret_len = Instruction::ret(instruction);

  // TODO: verify instruction

  // TODO: calculate gas cost

  InstructionResult result = VM::executeInstruction(
    instruction, 
    stack,
    reader, 
    accountState
  );

  switch (result) {
    case InstructionResult::OK:
      break;
    case InstructionResult::UNUSED_GAS:
      break;
    case InstructionResult::JUMP_POSITION:
      {
        uint256_t position = stack.peek(0);
        stack.pop(1);

        if (jumps.size() == 0) {
          // TODO: check jump position for child contracts?
          // i.e; resolve the jumps from the code attached to the VM
        }

        unsigned long pos = Jumps::verifyJump(position, jumps);
        if (pos == INVALID_ARGUMENT) return ExecResult::STOPPED; // TODO: handle error
        reader.position = pos;
        break;
      }
      case InstructionResult::JUMP_CONDITIONAL_POSITION:
      {
        uint256_t position = stack.peek(0);
        stack.pop(2);

        if (jumps.size() == 0) {
          // TODO: check jump position for child contracts?
          // i.e; resolve the jumps from the code attached to the VM
        }

        unsigned long pos = Jumps::verifyJump(position, jumps);
        if (pos == INVALID_ARGUMENT) return ExecResult::STOPPED; // TODO: handle error
        reader.position = pos;
        break;
      }
    case InstructionResult::STOP_EXEC_RETURN:
      break;
    case InstructionResult::STOP_EXEC:
      // TODO: return the amount of gas left, before execution was stopped
      return ExecResult::STOPPED;
    case InstructionResult::INSTRUCTION_TRAP:
      break;
  }
  
  if (reader.position >= reader.len()) {
    return ExecResult::DONE;
  }

  return ExecResult::CONTINUE;
}

InstructionResult VM::executeInstruction(
  instruct_t instruction,
  StackMachine& stack,
  ByteReader& reader, 
  AccountState& accountState
) {
  //Utils::printInstruction(instruction);
  switch (Instruction::opcode(instruction)) {
    case Opcode::STOP: {
      return InstructionResult::STOP_EXEC;
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
      printf("(SDIV ");
      break;
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
      printf("(SMOD ");
      break;
    case Opcode::ADDMOD:
      printf("(ADDMOD ");
      break;
    case Opcode::MULMOD:
      printf("(MULMOD ");
      break;
    case Opcode::EXP:
      printf("(EXP ");
      break;
    case Opcode::SIGNEXTEND:
      printf("(SIGNEXTEND ");
      break;

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
      printf("(SLT ");
      break;
    case Opcode::SGT:
      printf("(SGT ");
      break;
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
    // TODO: write a test for this
    case Opcode::NOT:
      {
        uint256_t item = stack.peek(0);
        stack.pop(1);
        stack.push(~item);
        break;
      }
    case Opcode::BYTE:
      printf("(BYTE ");
      break;
    case Opcode::SHL:
      printf("(SHL ");
      break;
    case Opcode::SHR:
      printf("(SHR ");
      break;
    case Opcode::SAR:
      printf("(SAR ");
      break;
    case Opcode::SHA3:
      printf("(SHA3 ");
      break;

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
      printf("(CALLVALUE ");
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

    case Opcode::POP:
      printf("(POP ");
      break;
    case Opcode::MLOAD:
      printf("(MLOAD ");
      break;
    case Opcode::MSTORE:
      printf("(MSTORE ");
      break;
    case Opcode::MSTORE8:
      printf("(MSTORE8 ");
      break;
    case Opcode::SLOAD:
      printf("(SLOAD ");
      break;
    case Opcode::SSTORE:
      {
        // TODO: support clear by index
        // TODO: gas calculations
        accountState.putTopPair(stack.stack);
        stack.pop(2);
        break;
      }
    case Opcode::JUMP:
      return InstructionResult::JUMP_POSITION;
    case Opcode::JUMPI:
      {
        uint256_t condition = stack.peek(1);
        if (condition == StackMachine::TRUE) return InstructionResult::JUMP_CONDITIONAL_POSITION;
        stack.pop(2);
        break;
      }
    case Opcode::PC:
      printf("(PC ");
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
    case Opcode::CALL:
      printf("(CALL ");
      break;
    case Opcode::CALLCODE:
      printf("(CALLCODE ");
      break;
    case Opcode::RETURN:
      printf("(RETURN ");
      break;
    case Opcode::DELEGATECALL:
      printf("(DELEGATECALL ");
      break;
    case Opcode::CREATE2:
      printf("(CREATE2 ");
      break;
    case Opcode::STATICCALL:
      printf("(STATICCALL ");
      break;
    case Opcode::REVERT:
      printf("(REVERT ");
      break;
    case Opcode::SELFDESTRUCT:
      printf("(SELFDESTRUCT ");
      break;
  }

  return InstructionResult::OK;
}