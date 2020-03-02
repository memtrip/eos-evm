#include <sstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include <evm/opcode.h>
#include <evm/instruction.h>
#include <evm/gas_tier_price.h>
#include <evm/utils.h>
#include <evm/big_int.h>
#include <evm/hex.h>

void Utils::printOpcode(uint8_t value) {
  switch (value) {
    case Opcode::STOP:
      printf("(STOP ");
      break;
    case Opcode::ADD:
      printf("(ADD ");
      break;
    case Opcode::MUL:
      printf("(MUL ");
      break;
    case Opcode::SUB:
      printf("(SUB ");
      break;
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

    case Opcode::BLOCKHASH:
      printf("(BLOCKHASH ");
      break;
    case Opcode::COINBASE:
      printf("(COINBASE ");
      break;
    case Opcode::TIMESTAMP:
      printf("(TIMESTAMP ");
      break;
    case Opcode::NUMBER:
      printf("(NUMBER ");
      break;
    case Opcode::DIFFICULTY:
      printf("(DIFFICULTY ");
      break;
    case Opcode::GASLIMIT:
      printf("(GASLIMIT ");
      break;
    case Opcode::CHAINID:
      printf("(CHAINID ");
      break;
    case Opcode::SELFBALANCE:
      printf("(SELFBALANCE ");
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
    case Opcode::MSIZE:
      printf("(MSIZE ");
      break;
    case Opcode::GAS:
      printf("(GAS ");
      break;
    case Opcode::JUMPDEST:
      printf("(JUMPDEST ");
      break;
    
    case Opcode::PUSH1:
      printf("(PUSH1 ");
      break;
    case Opcode::PUSH2:
      printf("(PUSH2 ");
      break;
    case Opcode::PUSH3:
      printf("(PUSH3 ");
      break;
    case Opcode::PUSH4:
      printf("(PUSH4 ");
      break;
    case Opcode::PUSH5:
      printf("(PUSH5 ");
      break;
    case Opcode::PUSH6:
      printf("(PUSH6 ");
      break;
    case Opcode::PUSH7:
      printf("(PUSH7 ");
      break;
    case Opcode::PUSH8:
      printf("(PUSH8 ");
      break;
    case Opcode::PUSH9:
      printf("(PUSH9 ");
      break;
    case Opcode::PUSH10:
      printf("(PUSH10 ");
      break;
    case Opcode::PUSH11:
      printf("(PUSH11 ");
      break;
    case Opcode::PUSH12:
      printf("(PUSH12 ");
      break;
    case Opcode::PUSH13:
      printf("(PUSH13 ");
      break;
    case Opcode::PUSH14:
      printf("(PUSH14 ");
      break;
    case Opcode::PUSH15:
      printf("(PUSH15 ");
      break;
    case Opcode::PUSH16:
      printf("(PUSH16 ");
      break;
    case Opcode::PUSH17:
      printf("(PUSH17 ");
      break;
    case Opcode::PUSH18:
      printf("(PUSH18 ");
      break;
    case Opcode::PUSH19:
      printf("(PUSH19 ");
      break;
    case Opcode::PUSH20:
      printf("(PUSH20 ");
      break;
    case Opcode::PUSH21:
      printf("(PUSH21 ");
      break;
    case Opcode::PUSH22:
      printf("(PUSH22 ");
      break;
    case Opcode::PUSH23:
      printf("(PUSH23 ");
      break;
    case Opcode::PUSH24:
      printf("(PUSH24 ");
      break;
    case Opcode::PUSH25:
      printf("(PUSH25 ");
      break;
    case Opcode::PUSH26:
      printf("(PUSH26 ");
      break;
    case Opcode::PUSH27:
      printf("(PUSH27 ");
      break;
    case Opcode::PUSH28:
      printf("(PUSH28 ");
      break;
    case Opcode::PUSH29:
      printf("(PUSH29 ");
      break;
    case Opcode::PUSH30:
      printf("(PUSH30 ");
      break;
    case Opcode::PUSH31:
      printf("(PUSH31 ");
      break;
    case Opcode::PUSH32:
      printf("(PUSH32 ");
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
}

void Utils::printTier(uint8_t value) {
  switch (value) {
    case GasTierPrice::ZERO:
      printf("ZERO");
      break;
    case GasTierPrice::BASE:
      printf("BASE");
      break;
    case GasTierPrice::VERY_LOW:
      printf("VERY_LOW");
      break;
    case GasTierPrice::LOW:
      printf("LOW");
      break;
    case GasTierPrice::MID:
      printf("MID");
      break;
    case GasTierPrice::HIGH:
      printf("HIGH");
      break;
    case GasTierPrice::EXT:
      printf("EXT");
      break;
    case GasTierPrice::SPECIAL:
      printf("SPECIAL");
      break;
  }
}

void Utils::printOpcodeHex(uint8_t value) {
  printf("(0x%02X)", (unsigned int)(value & 0xFF));
}

void Utils::printInstruction(unsigned int value) {
  if (value == 255) return;
  printf("(");
  printOpcode(Instruction::byteAt(value, 3));
  printOpcodeHex(Instruction::byteAt(value, 3));
  printf(")");
  printf(", %d, %d, ", Instruction::byteAt(value, 2), Instruction::byteAt(value, 1));
  printTier(Instruction::byteAt(value, 0));
  printf(")");
  printf(" ");
  printf("\n");
}

void Utils::printInstructionList() {
  for (int i = 0; i < 255; i++) {
    unsigned int instruction = Instruction::values[i];
    printInstruction(instruction);
  }
}

std::string Utils::uint256_2str(uint256_t value) {
  bytes_t bytes = BigInt::toBytes(value);
  return Hex::bytesToHex(bytes);
}

void Utils::print_uint256(uint256_t value) {
  printf("{");
  std::cout << Utils::uint256_2str(value);
  printf("}\n");
}

uint256_t Utils::bigIntFromBigEndianBytes(std::string bytecode_str) {
  return BigInt::fromBigEndianBytes(Hex::hexToBytes(bytecode_str));
}

store_item_t Utils::accountStoreValue(size_t index, account_store_t* store) {
  return store->at(index);
}

env_t Utils::env() {
  return {
    16339169, /* blockNumber */
    1581632422128, /* timestamp */
    100000, /* gasLimit */
    1 /* chainId */
  };
};

params_t Utils::params(bytes_t code, bytes_t data) {
  return {
    uint256_t(0xea0e9f), /* codeAddress*/
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xea0e9e), /* sender */
    uint256_t(0x1283fe), /* origin */
    uint256_t(34), /* value */
    code, /* code */
    data /* data */
  };
};

void Utils::printBytes(bytes_t& bytes) {
  std::cout << Hex::bytesToHex(bytes);
}

bytes_t Utils::returnDataSlice(ReturnData returnData) {
  size_t offset = static_cast<size_t>(returnData.offset);
  size_t size = static_cast<size_t>(returnData.size);
  bytes_t returnDataSlice(
    returnData.mem.begin() + offset, 
    returnData.mem.begin() + offset + size
  );
  return returnDataSlice;
}