#include "vm.h"
#include "opcode.h"
#include "instruction.h"
#include "jumps.h"
#include "big_int.h"
#include "utils.h" // TODO: remove this

ExecResult VM::execute(char* bytes, unsigned int size) {
  ExecResult result;

  jump_set_t jumps = Jumps::find_destinations(bytes, size);
  ByteReader reader(0, bytes, size);

  do {
    result = VM::step(jumps, reader);
  } while(result == ExecResult::CONTINUE);

  return result;
}

ExecResult VM::step(jump_set_t jumps, ByteReader& reader) {
  return VM::stepInner(reader);
}

ExecResult VM::stepInner(ByteReader& reader) {
  unsigned char opcode = reader.bytes[reader.position];
  unsigned int instruction = Instruction::values[opcode];
  reader.position += 1;

  // TODO: handle this properly
  if (instruction == 0x000000FF) return ExecResult::DONE;

  last_stack_ret_len = Instruction::ret(instruction);

  // TODO: verify instruction

  // TODO: calculate gas cost

  InstructionResult result = VM::executeInstruction(instruction, reader);

  switch (result) {
    case InstructionResult::OK:
      break;
    case InstructionResult::UNUSED_GAS:
      break;
    case InstructionResult::JUMP_POSITION:
      break;
    case InstructionResult::STOP_EXEC_RETURN:
      break;
    case InstructionResult::STOP_EXEC:
      break;
    case InstructionResult::INSTRUCTION_TRAP:
      break;
  }
  
  if (reader.position >= reader.len) {
    return ExecResult::DONE;
  }

  return ExecResult::CONTINUE;
}

InstructionResult VM::executeInstruction(instruct_t instruction, ByteReader& reader) {
  Utils::printInstruction(instruction);
  switch (Instruction::opcode(instruction)) {
    case Opcode::STOP:
      printf("(STOP ");
      break;
    case Opcode::ADD:
      {
        // TODO: handle arthemetic overflows
        uint256_t result = stack.peek(1) + stack.peek(0);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::MUL:
      printf("(MUL ");
      break;
    case Opcode::SUB:
      {
        // TODO: handle arthemetic overflows
        uint256_t result = stack.peek(1) - stack.peek(0);
        stack.pop(2);
        stack.push(result);
        break;
      }
    case Opcode::DIV:
      printf("(DIV ");
      break;
    case Opcode::SDIV:
      printf("(SDIV ");
      break;
    case Opcode::MOD:
      printf("(MOD ");
      break;
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
      printf("(LT ");
      break;
    case Opcode::GT:
      printf("(GT ");
      break;
    case Opcode::SLT:
      printf("(SLT ");
      break;
    case Opcode::SGT:
      printf("(SGT ");
      break;
    case Opcode::EQ:
      printf("(EQ ");
      break;
    case Opcode::ISZERO:
      printf("(ISZERO ");
      break;
    case Opcode::AND:
      printf("(AND ");
      break;
    case Opcode::OR:
      printf("(OR ");
      break;
    case Opcode::XOR:
      printf("(XOR ");
      break;
    case Opcode::NOT:
      printf("(NOT ");
      break;
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
      printf("(SSTORE ");
      break;
    case Opcode::JUMP:
      printf("(JUMP ");
      break;
    case Opcode::JUMPI:
      printf("(JUMPI ");
      break;
    case Opcode::PC:
      printf("(PC ");
      break;
    case Opcode::GAS:
      printf("(GAS ");
      break;
    case Opcode::JUMPDEST:
      printf("(JUMPDEST ");
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
      printf("(DUP1 ");
      break;
    case Opcode::DUP2:
      printf("(DUP2 ");
      break;
    case Opcode::DUP3:
      printf("(DUP3 ");
      break;
    case Opcode::DUP4:
      printf("(DUP4 ");
      break;
    case Opcode::DUP5:
      printf("(DUP5 ");
      break;
    case Opcode::DUP6:
      printf("(DUP6 ");
      break;
    case Opcode::DUP7:
      printf("(DUP7 ");
      break;
    case Opcode::DUP8:
      printf("(DUP8 ");
      break;
    case Opcode::DUP9:
      printf("(DUP9 ");
      break;
    case Opcode::DUP10:
      printf("(DUP10 ");
      break;
    case Opcode::DUP11:
      printf("(DUP11 ");
      break;
    case Opcode::DUP12:
      printf("(DUP12 ");
      break;
    case Opcode::DUP13:
      printf("(DUP13 ");
      break;
    case Opcode::DUP14:
      printf("(DUP14 ");
      break;
    case Opcode::DUP15:
      printf("(DUP15 ");
      break;
    case Opcode::DUP16:
      printf("(DUP16 ");
      break;

    case Opcode::SWAP1:
      printf("(SWAP1 ");
      break;
    case Opcode::SWAP2:
      printf("(SWAP2 ");
      break;
    case Opcode::SWAP3:
      printf("(SWAP3 ");
      break;
    case Opcode::SWAP4:
      printf("(SWAP4 ");
      break;
    case Opcode::SWAP5:
      printf("(SWAP5 ");
      break;
    case Opcode::SWAP6:
      printf("(SWAP6 ");
      break;
    case Opcode::SWAP7:
      printf("(SWAP7 ");
      break;
    case Opcode::SWAP8:
      printf("(SWAP8 ");
      break;
    case Opcode::SWAP9:
      printf("(SWAP9 ");
      break;
    case Opcode::SWAP10:
      printf("(SWAP10 ");
      break;
    case Opcode::SWAP11:
      printf("(SWAP11 ");
      break;
    case Opcode::SWAP12:
      printf("(SWAP12 ");
      break;
    case Opcode::SWAP13:
      printf("(SWAP13 ");
      break;
    case Opcode::SWAP14:
      printf("(SWAP14 ");
      break;
    case Opcode::SWAP15:
      printf("(SWAP15 ");
      break;
    case Opcode::SWAP16:
      printf("(SWAP16 ");
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

    case Opcode::PUSH:
      printf("(PUSH ");
      break;
    case Opcode::DUP:
      printf("(DUP ");
      break;
    case Opcode::SWAP:
      printf("(SWAP ");
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

uint256_t VM::stackTop() {
  return stack.peek(0);
}