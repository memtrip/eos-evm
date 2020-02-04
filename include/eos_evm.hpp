#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

namespace evm {
  CONTRACT eos_evm : public contract {
    public:
      using contract::contract;

      ACTION writelog(name from, string message);
      ACTION clearlog();

    private:
      TABLE log {
        uint64_t key;
        name    user;
        string  message;
        uint64_t primary_key() const { return key; }
      };
      typedef multi_index<name("log"), log> log_table;
  };
}