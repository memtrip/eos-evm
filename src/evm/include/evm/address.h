#pragma once
#include <string>
#include "types.h"

class Address {
  public:
    static bytes_t accountIdentifierFromString(const std::string& accountName, const std::string& addressString);
    static bytes_t accountIdentifierFromBytes(const std::string& accountName, const bytes_t& address);
    static bytes_t ethereumAddress(bytes_t& uncompressedPubKey);
};