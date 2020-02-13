#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <set>
#include "boost/multiprecision/cpp_int.hpp"
#include "keccak/hash_types.hpp"


typedef boost::multiprecision::uint256_t uint256_t;
typedef boost::multiprecision::limb_type limb_type_t;

typedef unsigned int instruct_t; 
typedef std::set<unsigned long> jump_set_t;

typedef ethash::hash256 keccak256_t;
typedef ethash::hash512 keccak512_t;

const unsigned long INVALID_ARGUMENT = 0xFFFFFFFFFFFFFFFF;

const size_t WORD_SIZE = 32;

#endif