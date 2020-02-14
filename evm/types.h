#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <set>
#include <intx/intx.hpp>
#include "keccak/hash_types.hpp"

typedef intx::uint256 uint256_t;

typedef unsigned int instruct_t; 
typedef std::set<unsigned long> jump_set_t;

typedef std::pair<uint256_t, uint256_t> store_item_t;
typedef std::vector<store_item_t> account_store_t;

typedef ethash::hash256 keccak256_t;
typedef ethash::hash512 keccak512_t;

struct EnvInfo {
  uint256_t blockNumber;
  uint64_t timestamp;
  uint32_t gasLimit;
  uint32_t chainId;
};

typedef EnvInfo env_t;

const unsigned long INVALID_ARGUMENT = 0xFFFFFFFFFFFFFFFF;

const size_t WORD_SIZE = 32;

#endif