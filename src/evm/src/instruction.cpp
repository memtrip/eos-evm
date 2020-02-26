#include <evm/instruction.h>
#include <evm/opcode.h>

/*
  A 4 byte representation of an EVM instruction; [opcode][args][return][tier]
*/
const instruct_t Instruction::values[] = {
  0x00000000, // ((STOP (0x00)), 0, 0, ZERO)
  0x01020102, // ((ADD (0x01)), 2, 1, VERY_LOW)
  0x02020103, // ((MUL (0x02)), 2, 1, LOW)
  0x03020102, // ((SUB (0x03)), 2, 1, VERY_LOW)
  0x04020103, // ((DIV (0x04)), 2, 1, LOW)
  0x05020103, // ((SDIV (0x05)), 2, 1, LOW)
  0x06020103, // ((MOD (0x06)), 2, 1, LOW)
  0x07020103, // ((SMOD (0x07)), 2, 1, LOW)
  0x08030104, // ((ADDMOD (0x08)), 3, 1, MID)
  0x09030104, // ((MULMOD (0x09)), 3, 1, MID)
  0x0A020107, // ((EXP (0x0A)), 2, 1, SPECIAL)
  0x0B020107, // ((SIGNEXTEND (0x0B)), 2, 1, SPECIAL)
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x10020102, // ((LT (0x10)), 2, 1, VERY_LOW)
  0x11020102, // ((GT (0x11)), 2, 1, VERY_LOW)
  0x12020102, // ((SLT (0x12)), 2, 1, VERY_LOW)
  0x13020102, // ((SGT (0x13)), 2, 1, VERY_LOW)
  0x14020102, // ((EQ (0x14)), 2, 1, VERY_LOW)
  0x15010102, // ((ISZERO (0x15)), 1, 1, VERY_LOW)
  0x16020102, // ((AND (0x16)), 2, 1, VERY_LOW)
  0x17020102, // ((OR (0x17)), 2, 1, VERY_LOW)
  0x18020102, // ((XOR (0x18)), 2, 1, VERY_LOW)
  0x19010102, // ((NOT (0x19)), 1, 1, VERY_LOW)
  0x1A020102, // ((BYTE (0x1A)), 2, 1, VERY_LOW)
  0x1B020102, // ((SHL (0x1B)), 2, 1, VERY_LOW)
  0x1C020102, // ((SHR (0x1C)), 2, 1, VERY_LOW)
  0x1D020102, // ((SAR (0x1D)), 2, 1, VERY_LOW)
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x20020107, // ((SHA3 (0x20)), 2, 1, SPECIAL)
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x30000101, // ((ADDRESS (0x20)), 0, 1, BASE)
  0x31010107, // ((BALANCE (0x31)), 1, 1, SPECIAL)
  0x32000101, // ((ORIGIN (0x32)), 0, 1, BASE)
  0x33000101, // ((CALLER (0x33)), 0, 1, BASE)
  0x34000101, // ((CALLVALUE (0x34)), 0, 1, BASE)
  0x35010102, // ((CALLDATALOAD (0x35)), 1, 1, VERY_LOW)
  0x36000101, // ((CALLDATASIZE (0x36)), 0, 1, BASE)
  0x37030002, // ((CALLDATACOPY (0x37)), 3, 0, VERY_LOW)
  0x38000101, // ((CODESIZE (0x38)), 0, 1, BASE)
  0x39030002, // ((CODECOPY (0x39)), 3, 0, VERY_LOW)
  0x3A000101, // ((GASPRICE (0x3A)), 0, 1, BASE)
  0x3B010107, // ((EXTCODESIZE (0x3B)), 1, 1, SPECIAL)
  0x3C040007, // ((EXTCODECOPY (0x3C)), 4, 0, SPECIAL)
  0x3D000101, // ((RETURNDATASIZE (0x3D)), 0, 1, BASE)
  0x3E030002, // ((RETURNDATACOPY (0x3E)), 3, 0, VERY_LOW)
  0x3F010107, // ((EXTCODEHASH (0x3F)), 1, 1, SPECIAL)
  0x40010106, // ((BLOCKHASH (0x40)), 1, 1, EXT)
  0x41000101, // ((COINBASE (0x41)), 0, 1, BASE)
  0x42000101, // ((TIMESTAMP (0x42)), 0, 1, BASE)
  0x43000101, // ((NUMBER (0x43)), 0, 1, BASE)
  0x44000101, // ((DIFFICULTY (0x44)), 0, 1, BASE)
  0x45000101, // ((GASLIMIT (0x45)), 0, 1, BASE)
  0x46000101, // ((CHAINID (0x46)), 0, 1, BASE)
  0x47000103, // ((SELFBALANCE (0x47)), 0, 1, LOW)
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x50010001, // ((POP (0x50)), 1, 0, BASE)
  0x51010102, // ((MLOAD (0x51)), 1, 1, VERY_LOW)
  0x52020002, // ((MSTORE (0x52)), 2, 0, VERY_LOW)
  0x53020002, // ((MSTORE8 (0x53)), 2, 0, VERY_LOW)
  0x54010107, // ((SLOAD (0x54)), 1, 1, SPECIAL)
  0x55020007, // ((SSTORE (0x55)), 2, 0, SPECIAL)
  0x56010004, // ((JUMP (0x56)), 1, 0, MID)
  0x57020005, // ((JUMPI (0x57)), 2, 0, HIGH))
  0x58000101, // ((PC (0x58)), 0, 1, BASE)
  0x59000101, // ((MSIZE (0x59)), 0, 1, BASE)
  0x5A000105, // ((GAS (0x5A)), 0, 1, BASE)
  0x5B000007, // ((JUMPDEST (0x5B)), 0, 0, SPECIAL)
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x60000102, // ((PUSH1 (0x60)), 0, 1, VERY_LOW)
  0x61000102, // ((PUSH2 (0x61)), 0, 1, VERY_LOW)
  0x62000102, // ((PUSH3 (0x62)), 0, 1, VERY_LOW)
  0x63000102, // ((PUSH4 (0x63)), 0, 1, VERY_LOW)
  0x64000102, // ((PUSH5 (0x64)), 0, 1, VERY_LOW)
  0x65000102, // ((PUSH6 (0x65)), 0, 1, VERY_LOW)
  0x66000102, // ((PUSH7 (0x66)), 0, 1, VERY_LOW)
  0x67000102, // ((PUSH8 (0x67)), 0, 1, VERY_LOW)
  0x68000102, // ((PUSH9 (0x68)), 0, 1, VERY_LOW)
  0x69000102, // ((PUSH10 (0x69)), 0, 1, VERY_LOW)
  0x6A000102, // ((PUSH11 (0x6A)), 0, 1, VERY_LOW)
  0x6B000102, // ((PUSH12 (0x6B)), 0, 1, VERY_LOW)
  0x6C000102, // ((PUSH13 (0x6C)), 0, 1, VERY_LOW)
  0x6D000102, // ((PUSH14 (0x6D)), 0, 1, VERY_LOW)
  0x6E000102, // ((PUSH15 (0x6E)), 0, 1, VERY_LOW)
  0x6F000102, // ((PUSH16 (0x6F)), 0, 1, VERY_LOW)
  0x70000102, // ((PUSH17 (0x70)), 0, 1, VERY_LOW)
  0x71000102, // ((PUSH18 (0x71)), 0, 1, VERY_LOW)
  0x72000102, // ((PUSH19 (0x72)), 0, 1, VERY_LOW)
  0x73000102, // ((PUSH20 (0x73)), 0, 1, VERY_LOW)
  0x74000102, // ((PUSH21 (0x74)), 0, 1, VERY_LOW)
  0x75000102, // ((PUSH22 (0x75)), 0, 1, VERY_LOW)
  0x76000102, // ((PUSH23 (0x76)), 0, 1, VERY_LOW)
  0x77000102, // ((PUSH24 (0x77)), 0, 1, VERY_LOW)
  0x78000102, // ((PUSH25 (0x78)), 0, 1, VERY_LOW)
  0x79000102, // ((PUSH26 (0x79)), 0, 1, VERY_LOW)
  0x7A000102, // ((PUSH27 (0x7A)), 0, 1, VERY_LOW)
  0x7B000102, // ((PUSH28 (0x7B)), 0, 1, VERY_LOW)
  0x7C000102, // ((PUSH29 (0x7C)), 0, 1, VERY_LOW)
  0x7D000102, // ((PUSH30 (0x7D)), 0, 1, VERY_LOW)
  0x7E000102, // ((PUSH31 (0x7E)), 0, 1, VERY_LOW)
  0x7F000102, // ((PUSH32 (0x7F)), 0, 1, VERY_LOW)
  0x80010202, // ((DUP1 (0x80)), 1, 2, VERY_LOW)
  0x81020302, // ((DUP2 (0x81)), 2, 3, VERY_LOW)
  0x82030402, // ((DUP3 (0x82)), 3, 4, VERY_LOW)
  0x83040502, // ((DUP4 (0x83)), 4, 5, VERY_LOW)
  0x84050602, // ((DUP5 (0x84)), 5, 6, VERY_LOW)
  0x85060702, // ((DUP6 (0x85)), 6, 7, VERY_LOW)
  0x86070802, // ((DUP7 (0x86)), 7, 8, VERY_LOW)
  0x87080902, // ((DUP8 (0x87)), 8, 9, VERY_LOW)
  0x88091002, // ((DUP9 (0x88)), 9, 10, VERY_LOW)
  0x89101102, // ((DUP10 (0x89)), 10, 11, VERY_LOW)
  0x8A111202, // ((DUP11 (0x8A)), 11, 12, VERY_LOW)
  0x8B121302, // ((DUP12 (0x8B)), 12, 13, VERY_LOW)
  0x8C131402, // ((DUP13 (0x8C)), 13, 14, VERY_LOW)
  0x8D141502, // ((DUP14 (0x8D)), 14, 15, VERY_LOW)
  0x8E151602, // ((DUP15 (0x8E)), 15, 16, VERY_LOW)
  0x8F161702, // ((DUP16 (0x8F)), 16, 17, VERY_LOW)
  0x90020202, // ((SWAP1 (0x90)), 2, 2, VERY_LOW)
  0x91030302, // ((SWAP2 (0x91)), 3, 3, VERY_LOW)
  0x92040402, // ((SWAP3 (0x92)), 4, 4, VERY_LOW)
  0x93050502, // ((SWAP4 (0x93)), 5, 5, VERY_LOW)
  0x94060602, // ((SWAP5 (0x94)), 6, 6, VERY_LOW)
  0x95070702, // ((SWAP6 (0x95)), 7, 7, VERY_LOW)
  0x96080802, // ((SWAP7 (0x96)), 8, 8, VERY_LOW)
  0x97090902, // ((SWAP8 (0x97)), 9, 9, VERY_LOW)
  0x98101002, // ((SWAP9 (0x98)), 10, 10, VERY_LOW)
  0x99111102, // ((SWAP10 (0x99)), 11, 11, VERY_LOW)
  0x9A121202, // ((SWAP11 (0x9A)), 12, 12, VERY_LOW)
  0x9B131302, // ((SWAP12 (0x9B)), 13, 13, VERY_LOW)
  0x9C141402, // ((SWAP13 (0x9C)), 14, 14, VERY_LOW)
  0x9D151502, // ((SWAP14 (0x9D)), 15, 15, VERY_LOW)
  0x9E161602, // ((SWAP15 (0x9E)), 16, 16, VERY_LOW)
  0x9F171702, // ((SWAP16 (0x9F)), 17, 17, VERY_LOW)
  0xA0020007, // ((LOG0 (0xA0)), 2, 0, SPECIAL)
  0xA1030007, // ((LOG1 (0xA1)), 3, 0, SPECIAL)
  0xA2040007, // ((LOG2 (0xA2)), 4, 0, SPECIAL)
  0xA3050007, // ((LOG3 (0xA3)), 5, 0, SPECIAL)
  0xA4060007, // ((LOG4 (0xA4)), 6, 0, SPECIAL)
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0xF0030107, // ((CREATE (0xF0)), 3, 1, SPECIAL)
  0xF1070107, // ((CALL (0xF1)), 7, 1, SPECIAL)
  0xF2070107, // ((CALLCODE (0xF2)), 7, 1, SPECIAL)
  0xF3020000, // ((RETURN (0xF3)), 2, 0, ZERO))
  0xF4060107, // ((DELEGATECALL (0xF4)), 6, 1, SPECIAL)
  0xF5040107, // ((CREATE2 (0xF5)), 4, 1, SPECIAL)
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0xFA060107, // ((STATICCALL (0xFA)), 6, 1, SPECIAL)
  0x000000FF, // Unassigned
  0x000000FF, // Unassigned
  0xFD020000, // ((REVERT (0xFD)), 2, 0, ZERO))
  0x000000FF, // Unassigned
  0xFF010007, // ((SELFDESTRUCT (0xFF)), 1, 0, SPECIAL)
};

unsigned char Instruction::byteAt(instruct_t instruction, int pos) {
  return (instruction >> (8 * pos)) & 0xff;
}

unsigned char Instruction::opcode(instruct_t instruction) {
  return Instruction::byteAt(instruction, 3);
}

unsigned char Instruction::args(instruct_t instruction) {
  return Instruction::byteAt(instruction, 2);
} 

unsigned char Instruction::ret(instruct_t instruction) {
  return Instruction::byteAt(instruction, 1);
} 

unsigned char Instruction::tier(instruct_t instruction) {
  return Instruction::byteAt(instruction, 0);
}

bool Instruction::isPush(instruct_t instruction) {
  unsigned char op = Instruction::opcode(instruction);
  return op >= Opcode::PUSH1 && op <= Opcode::PUSH32;
}

unsigned char Instruction::pushBytes(instruct_t instruction) {
  if (Instruction::isPush(instruction)) {
    return Instruction::opcode(instruction) - Opcode::PUSH1 + 1;
  } 
  return 0;
}

unsigned char Instruction::dupPosition(instruct_t instruction) {
  unsigned char op = Instruction::opcode(instruction);
  if (op >= Opcode::DUP1 && op <= Opcode::DUP16) {
    return op - Opcode::DUP1;
  }
  return 0;
}

unsigned char Instruction::swapPosition(instruct_t instruction) {
  unsigned char op = Instruction::opcode(instruction);
  if (op >= Opcode::SWAP1 && op <= Opcode::SWAP16) {
    return op - Opcode::SWAP1 + 1;
  }
  return 0;
}

unsigned char Instruction::logBytes(instruct_t instruction) {
  unsigned char op = Instruction::opcode(instruction);
  if (op >= Opcode::LOG0 && op <= Opcode::LOG4) {
    return op - Opcode::LOG0;
  }
  return 0;
}