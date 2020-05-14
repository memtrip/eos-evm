#include <string>
#include <memory>
#include <eosio/crypto.hpp>

#include <eos_evm.hpp>
#include <eos_system.hpp>
#include <eos_ecrecover.hpp>
#include <eos_external.hpp>

#include <evm/execute.hpp>
#include <evm/address.hpp>
#include <evm/transaction.hpp>
#include <evm/hex.hpp>
#include <evm/rlp_decode.hpp>
#include <evm/big_int.hpp>
#include <evm/hash.hpp>
#include <evm/hex.hpp>
#include <evm/overflow.hpp>

void eos_evm::raw(name from, bytes_t code, string sender) {
  incomingTransaction(from, code, sender, bytes_t());
}

void eos_evm::execute(name from, bytes_t code, string sender, bytes_t bytecode) {
  #if RELEASE
  check(false, "execute is only available during development.");
  #endif
  incomingTransaction(from, code, sender, bytecode);
}

void eos_evm::incomingTransaction(const name& from, const bytes_t& transaction, const string& sender, const bytes_t& bytecode) {
  require_auth(from);

  env_t env = eos_system::env();

  rlp_list_t* rlp = new rlp_list_t();
  RLPDecode::decode(transaction, rlp);

  uint64_t transactionNonce = Overflow::uint256Cast(Transaction::nonce(rlp)).first;
  bool hasSignature = Transaction::hasSignature(rlp);
  bytes_t digest = Transaction::digest(rlp, 0x01);
  bytes_t signature = Transaction::signature(rlp, env.chainId);

  TransactionActionType actionType = Transaction::type(rlp);
  gas_t gasLimit = Transaction::gas(rlp);
  uint256_t gasPrice = Transaction::gasPrice(rlp);
  uint256_t value = Transaction::value(rlp);
  uint256_t toAddress = BigInt::fromBigEndianBytes(Transaction::address(rlp));
  std::shared_ptr<bytes_t> data = std::make_shared<bytes_t>(Transaction::data(rlp));

  bytes_t accountIdentifierBytes = hasSignature ? eos_ecrecover::recover(from.to_string(), rlp, env) : Hex::hexToBytes(sender);
  checksum256 accountIdentifier = Hex::hexToChecksum256(accountIdentifierBytes);
  uint256_t senderAddress = BigInt::fromBigEndianBytes(accountIdentifierBytes);

  delete rlp;

  std::shared_ptr<Operation> operation = std::make_shared<Operation>();
  std::shared_ptr<GasCalculation> gasCalculation = std::make_shared<GasCalculation>();
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();

  account_table _account(get_self(), get_self().value);
  auto idx = _account.get_index<name("accountid")>();
  auto itr = idx.find(accountIdentifier);

  check(itr != idx.end(), hasSignature ? "The account identifier associated with this transaction does not exist." 
    : "Could not find sender, did you provide the correct account identifier?");
  check((transactionNonce - itr->nonce) == 1, "Transaction nonce invalid. got " + to_string(transactionNonce) + " wanted " + to_string(itr->nonce + 1));
  if (!hasSignature) check(has_auth(itr->user), "You do not have permission to execute a transaction for the specified sender.");

  std::shared_ptr<External> external = std::make_shared<eos_external>(
    this, senderAddress, itr->user, BigInt::fromFixed32(itr->balance.extract_as_byte_array()));

  call_result_t callResult;
  if (bytecode.size() > 0) {
    callResult = Execute::code(
      senderAddress, 
      env, 
      std::make_shared<bytes_t>(bytecode), 
      actionType, 
      gasLimit,
      gasPrice,
      value,
      data,
      toAddress,
      operation,
      gasCalculation,
      external, 
      pendingState
    );
  } else {
    callResult = Execute::transaction(
      senderAddress, 
      itr->nonce, 
      env, 
      actionType,
      gasLimit,
      gasPrice,
      value,
      data,
      toAddress,
      operation,
      gasCalculation,
      external, 
      pendingState
    );
  }

  checkCallResult(from, callResult);
  resolveAccountState(from, pendingState);
  resolveLogs(pendingState, external);

  idx.modify(itr, from, [&](auto& account) {
    account.nonce = itr->nonce + 1;
    account.balance = BigInt::toFixed32(external->senderAccountBalance());
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
            check(false, "STACK_LIMIT");
            break;
          case TrapKind::TRAP_INVALID_INSTRUCTION:
            check(false, "INVALID_INSTRUCTION");
            break;
          case TrapKind::TRAP_INVALID_JUMP:
            check(false, "JUMP_DESTINATION");
            break;
          case TrapKind::TRAP_INSUFFICIENT_FUNDS:
            check(false, "MESSAGE_CALL_FAILED [Insufficient funds.]");
            break;
          case TrapKind::TRAP_INVALID_CODE_ADDRESS:
            check(false, "MESSAGE_CALL_FAILED [An invalid address is attempting to modify a contract.]");
            break;
          case TrapKind::TRAP_OVERFLOW:
            check(false, "MESSAGE_CALL_FAILED [An integer overflow ocurred.]");
            break;
          case TrapKind::TRAP_MUTATE_STATIC:
            check(false, "MESSAGE_CALL_FAILED [A mutation occurred in a static context.]");
            break;
        }
        break;
      }
  }
}

void eos_evm::resolveAccountState(const name& from, std::shared_ptr<PendingState> pendingState) {
  if (pendingState->accountState.size() > 0) {
    account_state_table _account_state(get_self(), get_self().value);
    for (int i = 0; i < pendingState->accountState.size(); i++) {
      checksum256 compositeKey =  BigInt::toFixed32(Hash::keccak256WordPair(
        pendingState->accountState.at(i).codeAddress,
        pendingState->accountState.at(i).key
      ));
      auto idx = _account_state.get_index<name("statekey")>();
      auto itr = idx.find(compositeKey);
      if (itr != idx.end()) {
        idx.modify(itr, from, [&](auto& account_state) {
          account_state.value = BigInt::toFixed32(pendingState->accountState.at(i).value);
        });
      } else {
        _account_state.emplace(from, [&](auto& account_state) {
          account_state.pk = _account_state.available_primary_key();
          account_state.accountIdentifier = BigInt::toFixed32(pendingState->accountState.at(i).codeAddress);
          account_state.key = compositeKey;
          account_state.value = BigInt::toFixed32(pendingState->accountState.at(i).value);
        });
      }
    }
  }
}

void eos_evm::resolveLogs(std::shared_ptr<PendingState> pendingState, std::shared_ptr<External> external) {
  if (pendingState->logs.size() > 0) {
    for (int i = 0; i < pendingState->logs.size(); i++) {
      external->log(pendingState->logs.at(i).topics, pendingState->logs.at(i).data);
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
    account.balance = std::array<uint8_t, 32>{};
    account.accountIdentifier = Hex::hexToChecksum256(accountIdentifier);
  });
}

void eos_evm::withdraw(name to, asset quantity) {
  require_auth(to);

  check(quantity.amount > 0, "Please provide a withdraw quantity.");

  account_table _account(get_self(), get_self().value);
  auto iterator = _account.find(to.value);
  check(iterator != _account.end(), "The `to` account is not linked to an Ethereum account.");

  uint256_t quantityValue = (quantity.amount * BigInt::wei());
  uint256_t currentBalance = BigInt::fromFixed32(iterator->balance.extract_as_byte_array());
  check(currentBalance >= quantityValue, "Insufficient funds.");

  _account.modify(iterator, same_payer, [&](auto& account) {
    account.balance = BigInt::toFixed32(currentBalance - quantityValue); 
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
    uint256_t newBalance = BigInt::fromFixed32(account.balance.extract_as_byte_array()) + (quantity.amount * BigInt::wei());
    account.balance = BigInt::toFixed32(newBalance);
  });
}