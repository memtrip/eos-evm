#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <set>
#include "boost/multiprecision/cpp_int.hpp"

typedef boost::multiprecision::uint256_t uint256_t;
typedef boost::multiprecision::limb_type limb_type_t;

typedef unsigned int instruct_t; 
typedef std::set<unsigned long> jump_set_t;

const unsigned long INVALID_ARGUMENT = 0xFFFFFFFFFFFFFFFF;

#endif