#include "boost/multiprecision/cpp_int.hpp"
#include <vector>

class StackMachine {
  private:
    std::vector<boost::multiprecision::uint256_t> stack;
  public:
    StackMachine();
    void pop(unsigned int n);
    void popOne();
    boost::multiprecision::uint256_t peek(unsigned int n);
    void push(boost::multiprecision::uint256_t item);
};