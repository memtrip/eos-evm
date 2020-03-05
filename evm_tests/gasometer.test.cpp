#include "catch.hpp"
#include <evm/gasometer.h>

TEST_CASE("Calculate total memory size", "[gasometer]") {

  // given
  Gasometer gasometer(0);

  // when
  mem_gas_cost_t result = gasometer.memGasCost(0, 5);

  // then
  CHECK(3 == result.memGasCost);
  CHECK(3 == result.newMemGas);
  CHECK(32 == result.requiredMemorySize);
}