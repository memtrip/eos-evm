#include <vector>
#include "catch.hpp"
#include <memory>
#include <evm/memory.hpp>
#include <evm/types.h>
#include <evm/utils.hpp>
#include <evm/hex.hpp>

#include <evm/call.hpp>
#include <evm/big_int.hpp>
#include "test_utils.hpp"

TEST_CASE("Memory write and read", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(0x80 + 32);

  uint256_t writeWord = uint256_t(0xabcdef);
  memory->write(0x80, writeWord);

  // then
  uint256_t slice1 = memory->read(0x80);
  REQUIRE("0000000000000000000000000000000000000000000000000000000000abcdef" == Utils::uint256_2str(slice1)); 
}

TEST_CASE("Memory write and read (1)", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(0x80 + 32);

  uint256_t writeWord = uint256_t(0xabcdef);
  memory->write(0x80, writeWord);

  // then
  uint256_t slice1 = memory->read(0x80);
  REQUIRE("0000000000000000000000000000000000000000000000000000000000abcdef" == Utils::uint256_2str(slice1)); 
}

TEST_CASE("Memory write and read (2)", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(32);

  uint256_t writeWord = uint256_t(0x06);
  memory->write(0x00, writeWord);

  // then
  uint256_t slice1 = memory->read(0x00);
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000006" == Utils::uint256_2str(slice1)); 
}

TEST_CASE("Write word at index 32, write word at index 0, read word at index 32", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(64);
  Utils::printBytes(memory->memory, "empty_memory");

  uint256_t writeWord = uint256_t(0x06);
  memory->write(0x20, writeWord);

  uint256_t writeSecondWord = uint256_t(0x01);
  memory->write(0x00, writeSecondWord);

  // then
  uint256_t slice1 = memory->read(0x20);
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000006" == Utils::uint256_2str(slice1)); 
}

TEST_CASE("Memory write by byte and read", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(32);
  memory->writeByte(0x1d, uint256_t(0xab));
  memory->writeByte(0x1e, uint256_t(0xcd));
  memory->writeByte(0x1f, uint256_t(0xef));

  // then
  uint256_t slice1 = memory->read(0x00);
  REQUIRE("0000000000000000000000000000000000000000000000000000000000abcdef" == Utils::uint256_2str(slice1)); 
}

TEST_CASE("Memory write single byte and read", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(32);
  memory->writeByte(0x1F, uint256_t(0x06));

  // then
  uint256_t slice1 = memory->read(0x00);
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000006" == Utils::uint256_2str(slice1)); 
}

TEST_CASE("Memory write at index", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(32);

  uint256_t word = Utils::bigIntFromBigEndianBytes("0000000000000000000000000000000000000000000000000000000000000000");
  memory->write(
    0x00,
    word
  );

  // then
  uint256_t slice1 = memory->read(0x00);
  REQUIRE("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(slice1)); 
}

TEST_CASE("Memory write at index (1)", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(32);

  uint256_t word = Utils::bigIntFromBigEndianBytes("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
  memory->write(
    0x00,
    word
  );

  // then
  uint256_t slice1 = memory->read(0x00);
  REQUIRE("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff" == 
    Utils::uint256_2str(slice1)); 
}

TEST_CASE("Memory copy data", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();

  bytes_t copyBytes = Hex::hexToBytes("608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032");

  // when
  memory->expand(314);
  memory->copyData(
    0x00,
    0x82,
    0xB8,
    std::make_shared<bytes_t>(copyBytes)  
  );

  bytes_t slice = memory->readSlice(0x00, 0xB8);
  REQUIRE("6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032" == 
    TestUtils::bytesToHex(slice)
  ); 
}


TEST_CASE("Memory to return", "[memory]") {
  // given
  std::shared_ptr<Memory> memory = std::make_shared<Memory>();
  
  // when
  memory->expand(64);

  uint256_t word1 = Utils::bigIntFromBigEndianBytes("000000000000000000000000000000000000000000000000000000000000000a");
  memory->write(
    0x00,
    word1
  );

  uint256_t word2 = Utils::bigIntFromBigEndianBytes("0000000000000000000000000000000000000000000000000000000000000000");
  memory->write(
    0x20,
    word2
  );

  uint256_t slice1 = memory->read(0x00);
  CHECK("000000000000000000000000000000000000000000000000000000000000000a" == 
    Utils::uint256_2str(slice1)); 

  uint256_t slice2 = memory->read(0x20);
  CHECK("0000000000000000000000000000000000000000000000000000000000000000" == 
    Utils::uint256_2str(slice2)); 

  bytes_t returnDataBytes = memory->readSlice(0x1f, 0x20);

  CHECK("0a00000000000000000000000000000000000000000000000000000000000000" ==
    TestUtils::bytesToHex(returnDataBytes)
  );
}