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
        uint8_t index = bytes->at(position);
        instruct_t instruction = Instruction::values[index];

        if (instruction.opcode == Opcode::JUMPDEST) {
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