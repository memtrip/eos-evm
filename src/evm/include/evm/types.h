#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include <set>
#include <intx/intx.hpp>
#include <keccak/hash_types.hpp>

typedef intx::uint256 uint256_t;

typedef unsigned int instruct_t; 
typedef std::set<uint64_t> jump_set_t;

typedef ethash::hash256 keccak256_t;
typedef ethash::hash512 keccak512_t;

typedef std::vector<uint8_t> address_t;
typedef std::vector<uint8_t> bytes_t;
typedef std::array<char, 33> compressed_key_t;

struct EnvInfo {
  uint256_t chainId;
  uint256_t blockNumber;
  uint256_t timestamp;
  uint256_t gasLimit;
  uint256_t coinbase;
  uint256_t difficulty;
  uint256_t blockHash; 
};

typedef EnvInfo env_t;

enum ActionType {
  ACTION_CREATE,
  ACTION_CALL,
  ACTION_CALL_CODE,
  ACTION_DELEGATE_CALL,
  ACTION_STATIC_CALL,
  ACTION_CREATE2
};

typedef ActionType action_type_t;

typedef uint64_t gas_t;

struct Params {
  uint256_t codeAddress;
  uint256_t codeHash;
  uint256_t codeVersion;
  uint256_t address;
  uint256_t sender;
  uint256_t origin;
  gas_t gas;
  uint256_t gasPrice;
  uint256_t value;
  bytes_t code;
  bytes_t data;
};

typedef Params params_t;

enum TransactionActionType {
  TRANSACTION_CREATE,
  TRANSACTION_CALL,
};

enum RLPType {
  STRING,
  LIST
};

struct RLPItem {
  RLPType type;
  bytes_t bytes;
  std::vector<RLPItem> values;

  static const uint8_t OFFSET_SHORT_STRING = 0x80;
  static const uint8_t OFFSET_LONG_STRING = 0xb7;
  static const uint8_t OFFSET_SHORT_LIST = 0xc0;
  static const uint8_t OFFSET_LONG_LIST = 0xf7;
};

typedef std::vector<RLPItem> rlp_t;

const unsigned long INVALID_ARGUMENT = 0xFFFFFFFF;

const size_t WORD_SIZE = 32;

const size_t ADDRESS_SIZE = 20;

constexpr char HEX_VALUES[] = "0123456789abcdef";

constexpr uint256_t UINT256_ZERO = uint256_t(0);
constexpr uint256_t UINT256_32 = uint256_t(32);
constexpr uint256_t UINT256_FF = uint256_t(0xff);
constexpr uint256_t UINT256_ONE = uint256_t(1);

const size_t STACK_LIMIT = 1024;

#endif