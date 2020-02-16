#pragma once

#ifndef STUB

#include "address.h"

class eos_bridge {
  public:
    static string createAccountIdentifier(string name, string salt) {
      return Address::createAccountIdentifier(name, salt);
    }
};

/* Stub values for quicker contract builds */
#else
class eos_bridge {
  public:
    static string createAccountIdentifier(string name, string salt) {
      return "account_identifier";
    }
};
#endif