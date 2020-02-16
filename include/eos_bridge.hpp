#pragma once
#include <evm/address.h>
#include <evm/transaction.h>

class eos_bridge {
  public:
    static string createAccountIdentifier(string name, string salt) {
      return Address::createAccountIdentifier(name, salt);
    }

    static transaction_t parseTransaction(string code) {
      return Transaction::parse(code);
    }

    static bool signatureExists(transaction_t transaction) {
      return Transaction::signatureExists(transaction);
    }
};