#include "catch.hpp"
#include <evm/utils.h>
#include <evm/vm.h>
#include <evm/hex.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/gasometer.h>
#include <evm/big_int.h>
#include <evm/transaction.h>
#include "external_mock.h"

TEST_CASE("Call with transaction", "[call]") {

  // given
  transaction_t transaction = Transaction::parse("0xf855018203e88207d0808088000000000000000026a0fe2defcff2c42065c102e8cf9f88396571f972c2dc2698e4ef9f86939b927885a0033a9938cf9611aa166ec7fa39ad543a213d5f99aa93821bcfbf3eb4d96df227", 1);

  ExternalMock external {};
  AccountState accountState(&external);
  Call call(0);

  bytes_t addressBytes = Hex::hexToBytes("0f572e5295c57f15886f9b263e2f6d2d6c7b5ec6");

  env_t env = Utils::env();

  // when
  call_result_t result = call.execute(
    transaction,
    addressBytes,
    env,
    external,
    accountState
  );

  // then
  CHECK(MessageCallResult::MESSAGE_CALL_SUCCESS == result.first);
}