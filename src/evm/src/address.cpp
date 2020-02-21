#include <evm/address.h>
#include <evm/hash.h>
#include <evm/rlp.h>
#include <evm/hex.h>

std::string Address::createAccountIdentifier(std::string accountName, std::string salt) {

  bytes_t accountNameBytes(accountName.begin(), accountName.end());
  bytes_t saltBytes(salt.begin(), salt.end());

  RLPItem accountNameItem {
    RLPType::STRING,
    accountNameBytes,
    std::vector<RLPItem> {}
  };

  RLPItem saltItem {
    RLPType::STRING,
    saltBytes,
    std::vector<RLPItem> {}
  };

  RLPItem accountNameSaltList {
    RLPType::LIST,
    bytes_t {},
    std::vector<RLPItem> { accountNameItem, saltItem }
  };

  bytes_t result = RLPEncode::encode(accountNameSaltList);

  bytes_t hashBytes = Hash::keccak256(result);

  bytes_t addressBytes(hashBytes.end() - ADDRESS_SIZE, hashBytes.end());

  return Hex::bytesToHex(addressBytes);
};