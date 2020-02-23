#pragma once
#include <string>
#include "types.h"

class Address {
  public:
    static bytes_t accountIdentifierFromString(std::string accountName, std::string addressString);
    static bytes_t accountIdentifierFromBytes(std::string accountName, bytes_t address);
    static bytes_t ethereumAddress(bytes_t uncompressedPubKey);
};