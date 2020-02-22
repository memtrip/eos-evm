#include <evm/transaction.h>
#include <evm/rlp.h>
#include <evm/big_int.h>
#include <evm/hex.h>
#include <evm/hash.h>

transaction_t Transaction::parse(std::string hex, uint8_t chainId) {
  bytes_t bytes = Hex::hexToBytes(hex);
  std::vector<RLPItem> items = std::vector<RLPItem>();
  RLPDecode::decode(bytes, items);

  address_t address = items[0].values[3].bytes;

  return {
    address.size() == 0 ? 
      transaction_action_t::TRANSACTION_CREATE :
      transaction_action_t::TRANSACTION_CALL,
    BigInt::fromBigEndianBytes(items[0].values[0].bytes), /* nonce */
    BigInt::fromBigEndianBytes(items[0].values[1].bytes), /* gas_price */
    BigInt::fromBigEndianBytes(items[0].values[2].bytes), /* gas_limit */
    address, /* to */
    BigInt::fromBigEndianBytes(items[0].values[4].bytes), /* value */
    items[0].values[5].bytes, /* data */
    items[0].values[6].bytes, /* v */
    items[0].values[7].bytes, /* r */
    items[0].values[8].bytes, /* s */
    Transaction::digest(items, chainId)
  };
}

bool Transaction::signatureExists(transaction_t transaction) {
  return transaction.r.size() != 0 && transaction.s.size() != 0;
}

bytes_t Transaction::signatureBytes(transaction_t transaction) {
  bytes_t signatureBytes;
  signatureBytes.reserve(1 + transaction.r.size() + transaction.s.size());

  uint8_t v = eip155Compat(transaction.v);
  v += 27;

  signatureBytes.push_back(v);
  signatureBytes.insert(signatureBytes.end(), transaction.r.begin(), transaction.r.end());
  signatureBytes.insert(signatureBytes.end(), transaction.s.begin(), transaction.s.end());
  return signatureBytes;
}

bytes_t Transaction::digest(rlp_t rlp, uint8_t chainId) {

  RLPItem nonce {
    RLPType::STRING,
    rlp[0].values[0].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem gasPrice {
    RLPType::STRING,
    rlp[0].values[1].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem gasLimit {
    RLPType::STRING,
    rlp[0].values[2].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem address {
    RLPType::STRING,
    rlp[0].values[3].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem value {
    RLPType::STRING,
    rlp[0].values[4].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem data {
    RLPType::STRING,
    rlp[0].values[5].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem v {
    RLPType::STRING,
    bytes_t { chainId },
    std::vector<RLPItem> {}
  };

  RLPItem r {
    RLPType::STRING,
    bytes_t { },
    std::vector<RLPItem> {}
  };

  RLPItem s {
    RLPType::STRING,
    bytes_t { },
    std::vector<RLPItem> {}
  };

  RLPItem itemList {
    RLPType::LIST,
    bytes_t {},
    std::vector<RLPItem> { 
      nonce, gasPrice, gasLimit, 
      address, value, data,
      v, r, s  
    }
  };

  bytes_t rlpBytes = RLPEncode::encode(itemList);
  return Hash::keccak256(rlpBytes);
}

uint8_t Transaction::eip155Compat(bytes_t bytes) {
  uint8_t v = static_cast<uint8_t>(bytes[0]);
  if (v == 27) return 0;
  if (v == 28) return 1;
  if (v >= 35) return ((v - 1) % 2);
  return 4;
}