#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include <set>
#include <variant>
#include <intx/intx.hpp>
#include <keccak/hash_types.hpp>

typedef intx::uint256 uint256_t;

struct InstructionValue {
  uint8_t opcode;
  uint8_t args;
  uint8_t ret;
  uint8_t tier;
};

typedef InstructionValue instruct_t; 
typedef std::set<uint64_t> jump_set_t;

typedef std::array<uint8_t, 32> address_t;
typedef std::vector<uint8_t> bytes_t;
typedef std::array<char, 33> compressed_key_t;
typedef uint64_t gas_t;

const unsigned long INVALID_ARGUMENT = 0xFFFFFFFF;
const size_t WORD_SIZE = 32;
const size_t ADDRESS_SIZE = 20;
const size_t STACK_LIMIT = 1024;
constexpr char HEX_VALUES[] = "0123456789abcdef";

constexpr uint256_t UINT256_ZERO = uint256_t(0);
constexpr uint256_t UINT256_32 = uint256_t(32);
constexpr uint256_t UINT256_FF = uint256_t(0xff);
constexpr uint256_t UINT256_ONE = uint256_t(1);

const uint8_t OFFSET_SHORT_STRING = 0x80;
const uint8_t OFFSET_LONG_STRING = 0xb7;
const uint8_t OFFSET_SHORT_LIST = 0xc0;
const uint8_t OFFSET_LONG_LIST = 0xf7;

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

enum CallType {
  ACTION_CALL,
  ACTION_STATIC_CALL,
  ACTION_CREATE
};

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
  std::variant<
    bytes_t,
    std::vector<RLPItem>
  > value;
};

typedef std::vector<RLPItem> rlp_list_t;


enum TrapKind {
  TRAP_STACK_UNDERFLOW,
  TRAP_OUT_OF_STACK,
  TRAP_INVALID_INSTRUCTION,
  TRAP_INVALID_JUMP,
  TRAP_INSUFFICIENT_FUNDS,
  TRAP_INVALID_CODE_ADDRESS,
  TRAP_OVERFLOW,
  TRAP_MUTATE_STATIC
};

typedef TrapKind trap_t;

enum EmplaceResult {
  EMPLACE_ADDRESS_NOT_FOUND,
  EMPLACE_INSUFFICIENT_FUNDS,
  EMPLACE_CODE_ALREADY_EXISTS,
  EMPLACE_SUCCESS
};

typedef std::variant<
  uint8_t
> emplace_result_t;

typedef std::pair<EmplaceResult, emplace_result_t> emplace_t;

enum AddressScheme {
  SENDER,
  LEGACY,
  EIP_1014
};

enum MessageCallResult {
  MESSAGE_CALL_SUCCESS,
  MESSAGE_CALL_RETURN,
  MESSAGE_CALL_FAILED,
  MESSAGE_CALL_REVERTED,
  MESSAGE_CALL_OUT_OF_GAS
};

struct MessageCallReturn {
  gas_t gasLeft;
  uint64_t offset;
  uint64_t size;
};

typedef std::variant<
  gas_t,
  trap_t,
  MessageCallReturn
> call_result_data_t;

typedef std::pair<MessageCallResult, call_result_data_t> call_result_t;

enum TransferType {
  TRANSFER_PARENT_OUTGOING, // Transfer senderAddress is the parent context senderAddress
  TRANSFER_PARENT_INCOMING, // Transfer toAddress is the parent context senderAddress
  TRANSFER_PARENT_CHILD_OUTGOING, // Account is seeding its parent contract
  TRANSFER_ADHOC // Transfer is unrelated to the parent context senderAddress
};

#endif