#include "instruction.h"
#include "jumps.h"
#include "utils.h"
#include "opcode.h"

jump_set_t Jumps::findDestinations(bytes_t bytes) {
  jump_set_t jumps = jump_set_t();

  int position = 0;

  while (position < bytes.size()) {
    char index = bytes[position];
    int instruction = Instruction::values[index];

    if (Instruction::opcode(instruction) == Opcode::JUMPDEST) {
      jumps.insert(position);
    } else {
      position += Instruction::pushBytes(instruction);
    }

    position++;
  }

  return jumps;
}

unsigned long Jumps::verifyJump(uint256_t position, jump_set_t& validDestinations) {
  try {
      unsigned long jump = static_cast<unsigned long>(position);
      bool exists = validDestinations.find(jump) != validDestinations.end();
      if (validDestinations.find(jump) != validDestinations.end()) {
        return jump;
      } else {
        return INVALID_ARGUMENT;
      }
   } catch(...) {
    return INVALID_ARGUMENT;
   }
}