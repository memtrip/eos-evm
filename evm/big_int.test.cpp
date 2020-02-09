#include <stdio.h>
#include "catch.hpp"
#include "big_int.h"
#include "types.h"
#include "utils.h"

/**
  These tests assume little-endian byte ordering
*/

TEST_CASE("Instantiate uint256_t from char *", "[fromBytes]") {
  CHECK("1" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("0100000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("1" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("0100000000000000"))
  );
  CHECK("1" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("01"))
  );
  CHECK("15" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("15"))
  );
  CHECK("17" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("1700000000000000"))
  );
  CHECK("24" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("2400000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("1" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("01"))
  );
  CHECK("a" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("0A00000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("a" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("0A00000000000000"))
  );
  CHECK("10" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("1000000000000000000000000000000000000000000000000000000000000000"))
  );
  CHECK("10" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("10"))
  );
  CHECK("faffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("fffffffffffffffffffffffffffffffA"))
  );
  CHECK("fa" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("fA"))
  );
  CHECK("ff" == 
    Utils::uint256_2str(Utils::bigIntFromBytes("ff"))
  );
}