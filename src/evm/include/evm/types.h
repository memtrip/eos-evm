#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include <set>
#include <intx/intx.hpp>
#include <keccak/hash_types.hpp>

typedef intx::uint256 uint256_t;

typedef unsigned int instruct_t; 
typedef std::set<unsigned long> jump_set_t;

typedef std::pair<uint256_t, uint256_t> store_item_t;
typedef std::vector<store_item_t> account_store_t;

typedef ethash::hash256 keccak256_t;
typedef ethash::hash512 keccak512_t;

typedef std::vector<uint8_t> address_t;
typedef std::vector<uint8_t> bytes_t;

struct EnvInfo {
  uint256_t blockNumber;
  uint64_t timestamp;
  uint32_t gasLimit;
  uint32_t chainId;
};

typedef EnvInfo env_t;

enum TransactionActionType {
  TRANSACTION_CREATE,
  TRANSACTION_CALL,
};

typedef TransactionActionType transaction_action_t;

struct TransactionData {
  transaction_action_t action; /* ? */
  uint256_t nonce;
  uint256_t gas_price;
  uint256_t gas_limit;
  address_t to;
  uint256_t value;
  bytes_t data;
  bytes_t v;
  bytes_t r;
  bytes_t s;
  bytes_t digest;
};

typedef TransactionData transaction_t;

enum RLPType {
  STRING,
  LIST
};

struct RLPItem {
  RLPType type;
  bytes_t bytes;
  std::vector<RLPItem> values;
};

typedef std::vector<RLPItem> rlp_t;

const unsigned long INVALID_ARGUMENT = 0xFFFFFFFF;

const size_t WORD_SIZE = 32;

const size_t ADDRESS_SIZE = 20;

constexpr char hex[] = "0123456789abcdef";

#endif