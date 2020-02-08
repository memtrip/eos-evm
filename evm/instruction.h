#include "types.h"

class Instruction
{ 
  public: 
    const static unsigned int values[];
    static unsigned char byteAt(instruct_t value, int pos);
    static unsigned char opcode(instruct_t instruction);
    static unsigned char args(instruct_t instruction);
    static unsigned char ret(instruct_t instruction);
    static unsigned char tier(instruct_t instruction);
    static bool isPush(instruct_t instruction);
    static unsigned char pushBytes(instruct_t instruction);
};