#pragma once
#include <string>
#include "types.h"

class Address {
  public:
    static std::string createFromString(std::string accountName, std::string addressString);
    static std::string createFromBytes(std::string accountName, bytes_t address);
};