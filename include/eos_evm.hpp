#pragma once
#include <vector>
#include <memory>
#include <eosio/asset.hpp>
#include <eosio/eosio.hpp>

#include <evm/call.h>

using namespace std;
using namespace eosio;

CONTRACT eos_evm : public contract {
  public:
    using contract::contract;

    ACTION raw(name from, string code, string sender);
    ACTION create(name from, string message);

    // <account>
    TABLE account {
      name user;
      uint64_t nonce;
      asset balance;
      checksum256 accountIdentifier;

      auto primary_key() const { return user.value; }
      checksum256 secondary_key() const { return accountIdentifier; }
    };
    typedef multi_index<
      name("account"), 
      account, 
      indexed_by<name("accountid"), const_mem_fun<account, checksum256, &account::secondary_key> >
    > account_table;
    // </account>

    // <account_state>
    TABLE account_state {
      uint64_t pk;
      checksum256 accountIdentifier;
      checksum256 key;
      checksum256 value;

      uint64_t primary_key() const { return pk; }
      checksum256 secondary_key() const { return key; }
    };
    typedef multi_index<
      name("accountstate"), 
      account_state, 
      indexed_by<name("statekey"), const_mem_fun<account_state, checksum256, &account_state::secondary_key> >
    > account_state_table;
    // </account_state>

    // <account_code>
    TABLE account_code {
      uint64_t pk;
      checksum256 accountIdentifier;
      string code;

      auto primary_key() const { return pk; }
      checksum256 secondary_key() const { return accountIdentifier; }
    };
    typedef multi_index<
      name("accountcode"), 
      account_code, 
      indexed_by<name("codeaddress"), const_mem_fun<account_code, checksum256, &account_code::secondary_key> >
    > account_code_table;
    // </account_code>

  private:
    void handleCallResult(name from, call_result_t callResult, std::shared_ptr<AccountState> accountState);
    void commitState(name from, std::shared_ptr<AccountState> accountState);
};