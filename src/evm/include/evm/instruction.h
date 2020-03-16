#pragma once
#include <evm/types.h>
#include <evm/stack.h>

enum InstructionVerifyResult {
  INSTRUCTION_ERROR_UNDER_FLOW,
  INSTRUCTION_ERROR_OUT_OF_STACK,
  INSTRUCTION_VALID
};

typedef InstructionVerifyResult instruction_verify_t;

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
    static instruction_verify_t verify(instruct_t instruction, StackMachine& stack); 
};