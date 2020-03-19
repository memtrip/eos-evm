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
    ACTION writelog(name from, string message);
    ACTION clearlog();

  private:
    void handleCallResult(call_result_t callResult);
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

    TABLE account_state {
      name user;
      checksum256 key;
      checksum256 value;

      auto primary_key() const { return user.value; }
      checksum256 secondary_key() const { return key; }
    };
    typedef multi_index<name("accountstate"), account_state> account_state_table;

    TABLE account_code {
      name user;
      string code;

      auto primary_key() const { return user.value; }
    };
    typedef multi_index<name("accountcode"), account_code> account_code_table;

    TABLE log {
      uint64_t key;
      name    user;
      string  message;
      uint64_t primary_key() const { return key; }
    };
    typedef multi_index<name("log"), log> log_table;
};