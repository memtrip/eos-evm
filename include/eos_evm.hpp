#include <eosio/asset.hpp>
#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT eos_evm : public contract {
  public:
    using contract::contract;

    ACTION raw(name from, string code, string sender);
    ACTION create(name sender, string message);
    ACTION writelog(name from, string message);
    ACTION clearlog();

  private:
    TABLE account {
      name account;
      uint64_t nonce;
      asset balance;
      checksum256 accountIdentifier;

      name primary_key() const { return account; }
      checksum256 secondary_key() const { return accountIdentifier; }
    };
    typedef multi_index<name("account"), account> account_table;

    TABLE account_state {
      name account;
      checksum256 key;
      checksum256 value;

      name primary_key() const { return account; }
      checksum256 secondary_key() const { return key; }
    };
    typedef multi_index<name("accountstate"), account_state> account_state_table;

    TABLE account_code {
      name account;
      string code;

      name primary_key() const { return account; }
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