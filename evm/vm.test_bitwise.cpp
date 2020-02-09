// #include <stdio.h>
// #include "catch.hpp"
// #include "utils.h"
// #include "vm.h"

// // TODO: this test should asser that the account store has set values
// TEST_CASE("Bitwise", "[bitwise]") {
//   std::string bytecode_str = "60ff610ff08181818116600055176001551860025560008015600355198015600455600555";
//   char bytecode_array[bytecode_str.length() / 2];
//   Utils::hex2bin(bytecode_str, bytecode_array);
//   VM vm {};
//   AccountState accountState {};
//   StackMachine sm {};

//   // when
//   vm.execute(bytecode_array, sizeof(bytecode_array), sm, accountState);

//   // then
//   CHECK("" == 
//     Utils::uint256_2str(sm.top())
//   );
// }