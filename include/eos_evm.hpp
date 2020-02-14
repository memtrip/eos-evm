#include <eosio/asset.hpp>
#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT eos_evm : public contract {
  public:
    using contract::contract;

    ACTION writelog(name from, string message);
    ACTION clearlog();

  private:
    TABLE account {
      name account;
      uint64_t nonce;
      asset balance;

      name primary_key() const { return account; }
    };
    typedef multi_index<name("account"), account> account_table;

    TABLE log {
      uint64_t key;
      name    user;
      string  message;
      uint64_t primary_key() const { return key; }
    };
    typedef multi_index<name("log"), log> log_table;
};