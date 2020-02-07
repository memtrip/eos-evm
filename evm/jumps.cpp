#include <set>
#include "instruction.h"
#include "jumps.h"
#include "utils.h"

int getSize(char* s) {
  char * t;    
  for (t = s; *t != '\0'; t++);
  return t - s;
}

std::set<unsigned int> Jumps::find_destinations(char* byte_code, unsigned int size) {
  std::set<unsigned int> jumps = std::set<unsigned int>();

  int position = 0;

  while (position < size) {
    char index = byte_code[position];
    int instruction = evm::Instructions::values[index];
    printf("instruction(%d)", instruction);
    printInstruction(instruction);
    position++;
  }

  return jumps;
}