#include "catch.hpp"
#include <memory>
#include <evm/byte_reader.hpp>
#include <evm/types.h>
#include <evm/hex.hpp>
#include <evm/utils.hpp>

TEST_CASE("Byte Reader read(32)", "[byte_reader]" ) {
  std::string bytecode_str = "7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff01600055";
  std::shared_ptr<bytes_t> bytes = std::make_shared<bytes_t>(Hex::hexToBytes(bytecode_str));
  ByteReader byteReader(1);
  uint256_t item = byteReader.read(32, bytes);
  CHECK("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(1)", "[byte_reader]" ) {
  std::shared_ptr<bytes_t> bytes = std::make_shared<bytes_t>(Hex::hexToBytes("6001"));
  ByteReader byteReader(1);
  uint256_t item = byteReader.read(1, bytes);
  CHECK("0000000000000000000000000000000000000000000000000000000000000001" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(17)", "[byte_reader]" ) {
  std::shared_ptr<bytes_t> bytes = std::make_shared<bytes_t>(Hex::hexToBytes("6017"));
  ByteReader byteReader(1);
  uint256_t item = byteReader.read(1, bytes);
  CHECK("0000000000000000000000000000000000000000000000000000000000000017" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(ABC9)", "[byte_reader]" ) {
  std::shared_ptr<bytes_t> bytes = std::make_shared<bytes_t>(Hex::hexToBytes("ABC9"));
  ByteReader byteReader(0);
  uint256_t item = byteReader.read(2, bytes);
  CHECK("000000000000000000000000000000000000000000000000000000000000abc9" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(CD8967)", "[byte_reader]" ) {
  std::shared_ptr<bytes_t> bytes = std::make_shared<bytes_t>(Hex::hexToBytes("CD8967"));
  ByteReader byteReader(0);
  uint256_t item = byteReader.read(3, bytes);
  CHECK("0000000000000000000000000000000000000000000000000000000000cd8967" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(AB78EE54)", "[byte_reader]" ) {
  std::shared_ptr<bytes_t> bytes = std::make_shared<bytes_t>(Hex::hexToBytes("AB78EE54"));
  ByteReader byteReader(0);
  uint256_t item = byteReader.read(4, bytes);
  CHECK("00000000000000000000000000000000000000000000000000000000ab78ee54" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(ABCDEF1234)", "[byte_reader]" ) {
  std::shared_ptr<bytes_t> bytes = std::make_shared<bytes_t>(Hex::hexToBytes("ABCDEF1234"));
  ByteReader byteReader(0);
  uint256_t item = byteReader.read(5, bytes);
  CHECK("000000000000000000000000000000000000000000000000000000abcdef1234" == 
    Utils::uint256_2str(item)
  );
}

TEST_CASE("Byte Reader read(ABCDEF123456)", "[byte_reader]" ) {
  std::shared_ptr<bytes_t> bytes = std::make_shared<bytes_t>(Hex::hexToBytes("ABCDEF123456"));
  ByteReader byteReader(0);
  uint256_t item = byteReader.read(6, bytes);
  CHECK("0000000000000000000000000000000000000000000000000000abcdef123456" == 
    Utils::uint256_2str(item)
  );
}