#pragma once
#include "keccak/keccak.hpp"

class eos_keccak {
  public:
    static void keccak256(string message) {
      const char *data = message.c_str();
      ethash::hash256 result = ethash::keccak256(data, message.length());
    }
};