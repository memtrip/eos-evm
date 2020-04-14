#pragma once
#include <memory>
#include <evm/types.h>
#include <evm/instruction.hpp>
#include <evm/opcode.h>

class Jumps {
  public:
    static jump_set_t findDestinations(std::shared_ptr<bytes_t> bytes) {
      jump_set_t jumps = jump_set_t();

      int position = 0;

      while (position < bytes->size()) {
        char index = bytes->at(position);
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

    static uint64_t verifyJump(uint64_t position, const jump_set_t& validDestinations) {
      if (validDestinations.find(position) != validDestinations.end()) return position;
      return INVALID_ARGUMENT;
    }
};