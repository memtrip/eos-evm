#include <boost/numeric/conversion/cast.hpp>
#include "instruction.h"
#include "jumps.h"
#include "utils.h"
#include "opcode.h"

jump_set_t Jumps::findDestinations(char* byte_code, unsigned int size) {
  jump_set_t jumps = jump_set_t();

  int position = 0;

  while (position < size) {
    char index = byte_code[position];
    int instruction = Instruction::values[index];

    if (Instruction::opcode(instruction) == Opcode::JUMPDEST) {
      printf("{{%d}}", position);
      jumps.insert(position);
    } else {
      position += Instruction::pushBytes(instruction);
    }

    position++;
  }

  return jumps;
}

unsigned long Jumps::verifyJump(uint256_t position, jump_set_t validDestinations) {
  using boost::numeric_cast;
  try {
      unsigned long jump = numeric_cast<unsigned long>(position);
      printf("<%lu>", jump);
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