#include <evm/address.h>
#include <evm/hash.h>
#include <evm/rlp.h>
#include <evm/hex.h>

std::string Address::createFromString(std::string accountName, std::string addressString) {
  bytes_t address = Hex::hexToBytes(addressString);
  return createFromBytes(accountName, address);
};

std::string Address::createFromBytes(std::string accountName, bytes_t address) {
  
  bytes_t accountNameBytes(accountName.begin(), accountName.end());

  RLPItem accountNameItem {
    RLPType::STRING,
    accountNameBytes,
    std::vector<RLPItem> {}
  };

  RLPItem addressItem {
    RLPType::STRING,
    address,
    std::vector<RLPItem> {}
  };

  RLPItem accountNameAddressList {
    RLPType::LIST,
    bytes_t {},
    std::vector<RLPItem> { accountNameItem, addressItem }
  };

  bytes_t result = RLPEncode::encode(accountNameAddressList);

  bytes_t hashBytes = Hash::keccak256(result);

  bytes_t addressBytes(hashBytes.end() - ADDRESS_SIZE, hashBytes.end());

  return Hex::bytesToHex(addressBytes);
}