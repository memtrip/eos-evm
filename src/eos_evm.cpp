#include <string>
#include <eosio/crypto.hpp>
#include <eos_evm.hpp>
#include <eos_system.hpp>
#include <eos_ecrecover.hpp>
#include <eos_utils.hpp>
#include <eos_execute.hpp>

#include <evm/address.hpp>
#include <evm/transaction.hpp>
#include <evm/hex.hpp>
#include <evm/rlp_decode.hpp>
#include <evm/big_int.hpp>
#include <evm/hash.hpp>
#include <evm/overflow.hpp>

void eos_evm::raw(name from, string code, string sender) {
  incomingTransaction(from, code, sender, bytes_t());
}

void eos_evm::execute(name from, string code, string sender, string bytecode) {
  #if RELEASE
  check(false, "execute is only available during development.");
  #endif
  incomingTransaction(from, code, sender, Hex::hexToBytes(bytecode));
}

void eos_evm::incomingTransaction(const name& from, const string& transaction, const string& sender, const bytes_t& bytecode) {
  require_auth(from);

  bytes_t transactionBytes = Hex::hexToBytes(transaction);

  std::shared_ptr<std::vector<RLPItem>> rlp = std::make_shared<std::vector<RLPItem>>();
  RLPDecode::decode(transactionBytes, rlp);

  std::shared_ptr<account_store_t> cacheItems = std::make_shared<account_store_t>();
  std::shared_ptr<AccountState> accountState = std::make_shared<AccountState>(cacheItems);

  uint64_t transactionNonce = Overflow::uint256Cast(Transaction::nonce(rlp)).first;

  bool hasSignature = Transaction::hasSignature(rlp);
  bytes_t accountIdentifierBytes = hasSignature ? eos_ecrecover::recover(from.to_string(), rlp) : Hex::hexToBytes(sender);
  checksum256 accountIdentifier = Hex::hexToChecksum256(accountIdentifierBytes);
  uint256_t senderAddress = BigInt::fromBigEndianBytes(accountIdentifierBytes);

  account_table _account(get_self(), get_self().value);
  auto idx = _account.get_index<name("accountid")>();
  auto itr = idx.find(accountIdentifier);

  check(itr != idx.end(), hasSignature ? "The account identifier associated with this transaction does not exist." 
    : "Could not find sender, did you provide the correct account identifier?");
  check((transactionNonce - itr->nonce) == 1, "Transaction nonce invalid.");
  if (!hasSignature) check(has_auth(itr->user), "You do not have permission to execute a transaction for the specified sender.");

  std::shared_ptr<External> external = std::make_shared<eos_external>(this, itr->user, itr->nonce, itr->balance.amount);

  call_result_t callResult;
  if (bytecode.size() > 0) {
    callResult = eos_execute::code(senderAddress, bytecode, rlp, external, accountState);
  } else {
    callResult = eos_execute::transaction(senderAddress, rlp, external, accountState);
  }

  checkCallResult(from, callResult);
  resolveAccountState(from, accountState);

  idx.modify(itr, from, [&](auto& account) {
    account.nonce += 1;
    account.balance.amount = external->senderAccountBalance();
  });
}

void eos_evm::checkCallResult(const name& from, call_result_t callResult) {
  switch (callResult.first) {
    case MESSAGE_CALL_SUCCESS:
    case MESSAGE_CALL_RETURN:
      break;
    case MESSAGE_CALL_REVERTED:
      check(false, "MESSAGE_CALL_REVERTED");
      break;
    case MESSAGE_CALL_OUT_OF_GAS:
      check(false, "MESSAGE_CALL_OUT_OF_GAS");
      break;
    case MESSAGE_CALL_FAILED:
      {
        trap_t trap = std::get<trap_t>(callResult.second);
        switch (trap) {
          case TrapKind::TRAP_STACK_UNDERFLOW:
            check(false, "STACK_UNDERFLOW");
            break;
          case TrapKind::TRAP_OUT_OF_STACK:
            check(false, "OUT_OF_STACK");
            break;
          case TrapKind::TRAP_INVALID_INSTRUCTION:
            check(false, "INVALID_INSTRUCTION");
            break;
          case TrapKind::TRAP_INVALID_JUMP:
            check(false, "INVALID_JUMP");
            break;
          case TrapKind::TRAP_INSUFFICIENT_FUNDS:
            check(false, "MESSAGE_CALL_FAILED [Insufficient funds.]");
            break;
          case TrapKind::TRAP_INVALID_CODE_ADDRESS:
            check(false, "MESSAGE_CALL_FAILED [An invalid address is attempting to create a contract.]");
            break;
        }
        break;
      }
  }
}

void eos_evm::resolveAccountState(const name& from, std::shared_ptr<AccountState> accountState) {
  if (accountState->cacheItems->size() > 0) {
    // TODO: the scope of account_state should be derived from codeAddress
    account_state_table _account_state(get_self(), from.value);
    for (int i = 0; i < accountState->cacheItems->size(); i++) {
      checksum256 compositeKey =  BigInt::toFixed32(Hash::keccak256WordPair(
        accountState->cacheItems->at(i).codeAddress,
        accountState->cacheItems->at(i).key
      ));
      auto idx = _account_state.get_index<name("statekey")>();
      auto itr = idx.find(compositeKey);
      if (itr != idx.end()) {
        idx.modify(itr, from, [&](auto& account_state) {
          account_state.value = BigInt::toFixed32(accountState->cacheItems->at(i).value);
        });
      } else {
        _account_state.emplace(from, [&](auto& account_state) {
          account_state.pk = _account_state.available_primary_key();
          account_state.accountIdentifier = BigInt::toFixed32(accountState->cacheItems->at(i).codeAddress);
          account_state.key = compositeKey;
          account_state.value = BigInt::toFixed32(accountState->cacheItems->at(i).value);
        });
      }
    }
  }
}

void eos_evm::create(name from, string message) {
  require_auth(from);

  account_table _account(get_self(), get_self().value);

  auto iterator = _account.find(from.value);
  check(iterator == _account.end(), "An Ethereum account already exists for this user.");

  bytes_t accountIdentifier = Address::accountIdentifierFromString(
    from.to_string(), 
    message
  );

  _account.emplace(from, [&](auto& account) {
    account.user = from;
    account.nonce = 0;
    account.balance = asset(0, CONTRACT_SYMBOL);
    account.accountIdentifier = Hex::hexToChecksum256(accountIdentifier);
  });
}

void eos_evm::withdraw(name to, asset quantity) {
  require_auth(to);

  check(quantity.amount > 0, "Please provide a withdraw quantity.");

  account_table _account(get_self(), get_self().value);
  auto iterator = _account.find(to.value);
  check(iterator != _account.end(), "The `to` account is not linked to an Ethereum account.");
  check(iterator->balance.amount >= quantity.amount, "Insufficient funds.");

  _account.modify(iterator, same_payer, [&](auto& account) {
    account.balance.amount -= quantity.amount;
  });

  action{
    permission_level{get_self(), "active"_n},
    "eosio.token"_n,
    "transfer"_n,
    std::make_tuple(get_self(), to, quantity, std::string("EVM withdrawal"))
  }.send();
}

void eos_evm::transfer(name from, name to, asset quantity, string memo) {
  if (from == get_self()) return;
  if (to != get_self()) return;
  if (from == "eosio.stake"_n || from == "eosio.ram"_n || from == "eosio.names"_n || from == "eosio"_n) return;
  
  check(quantity.symbol == CONTRACT_SYMBOL, "The funds from an unknown token symbol were rejected.");
  check(get_first_receiver() == TOKEN_CONTRACT, "The funds from an unknown token contract were rejected.");
  check(quantity.amount > 0, "Please provide an amount to transfer.");

  account_table _account(get_self(), get_self().value);
  auto iterator = _account.find(from.value);
  check(iterator != _account.end(), "The `from` account is not linked to an Ethereum account.");

  _account.modify(iterator, same_payer, [&](auto& account) {
    account.balance.amount += quantity.amount;
  });
}