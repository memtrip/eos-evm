#pragma once
#include <vector>
#include <memory>
#include <eosio/asset.hpp>
#include <eosio/eosio.hpp>

#include <evm/call.hpp>

using namespace std;
using namespace eosio;

class [[eosio::contract("eos_evm")]] eos_evm : public contract {
  public:
    static constexpr eosio::symbol CONTRACT_SYMBOL = eosio::symbol{"EVM", 4};
    static constexpr eosio::name TOKEN_CONTRACT = eosio::name("eosio.token");

    struct [[eosio::table]] account {
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
      indexed_by<name("accountid"), const_mem_fun<account, checksum256, &account::secondary_key>>
    > account_table;

    struct [[eosio::table]] account_state {
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
      indexed_by<name("statekey"), const_mem_fun<account_state, checksum256, &account_state::secondary_key>>
    > account_state_table;

    struct [[eosio::table]] account_code {
      uint64_t pk;
      checksum256 accountIdentifier;
      checksum256 address;
      uint64_t nonce;
      string code;
      asset balance;

      auto primary_key() const { return pk; }
      checksum256 secondary_key() const { return accountIdentifier; }
      checksum256 tertiary_key() const { return address; }
    };

    typedef multi_index<
      name("accountcode"), 
      account_code, 
      indexed_by<name("owneraddress"), const_mem_fun<account_code, checksum256, &account_code::secondary_key>>,
      indexed_by<name("codeaddress"), const_mem_fun<account_code, checksum256, &account_code::tertiary_key>>
    > account_code_table;

    eos_evm(name receiver, name code, datastream<const char *> ds): contract(receiver, code, ds) { }

    [[eosio::action]]
    void raw(name from, string code, string sender);

    [[eosio::action]]
    void execute(name from, string code, string sender, string bytecode);

    [[eosio::action]]
    void create(name from, string message);

    [[eosio::action]]
    void withdraw(name to, asset quantity);

    [[eosio::on_notify("eosio.token::transfer")]]
    void transfer(name from, name to, asset quantity, string memo);

  private:
    void incomingTransaction(const name& from, const string& transaction, const string& sender, const bytes_t& bytecode);
    void checkCallResult(const name& from, call_result_t callResult);
    void resolveAccountState(const name& from, std::shared_ptr<PendingState> pendingState);
    void resolveLogs(std::shared_ptr<PendingState> pendingState, std::shared_ptr<External> external);
};