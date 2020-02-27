#include <evm/types.h>

class Instruction
{ 
  public: 
    const static unsigned int values[];
    static uint8_t byteAt(instruct_t value, int pos);
    static uint8_t opcode(instruct_t instruction);
    static uint8_t args(instruct_t instruction);
    static uint8_t ret(instruct_t instruction);
    static uint8_t tier(instruct_t instruction);
    static bool isPush(instruct_t instruction);
    static uint8_t pushBytes(instruct_t instruction);
    static uint8_t dupPosition(instruct_t instruction);
    static uint8_t swapPosition(instruct_t instruction);
    static uint8_t logTopics(instruct_t instruction);
};