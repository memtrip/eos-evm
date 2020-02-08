#include "instruction.h"
#include "jumps.h"
#include "utils.h"
#include "opcode.h"

jump_set_t Jumps::find_destinations(char* byte_code, unsigned int size) {
  jump_set_t jumps = jump_set_t();

  int position = 0;

  while (position < size) {
    char index = byte_code[position];
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