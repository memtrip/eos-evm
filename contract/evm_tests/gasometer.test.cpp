#include "catch.hpp"
#include <memory>
#include <evm/gasometer.hpp>

TEST_CASE("Calculate total memory size", "[gasometer]") {

  // given
  Gasometer gasometer(0);

  // when
  mem_gas_t result = gasometer.memGasCost(0, 5);

  // then
  CHECK(3 == result.memGasCost);
  CHECK(3 == result.newMemGas);
  CHECK(32 == result.newMemSize);
}