#include <memory>
#include <evm/rlp.h>
#include <evm/big_int.h>
#include <evm/hex.h>
#include <evm/hash.h>
#include <evm/transaction.h>
#include <evm/overflow.h>

const size_t RLP_ADDRESS = 3;
const size_t RLP_DATA = 5;
const size_t RLP_V = 6;
const size_t RLP_R = 7;
const size_t RLP_S = 8;

std::shared_ptr<bytes_t> Transaction::data(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return std::make_shared<bytes_t>(bytes_t(rlp->at(0).values[RLP_DATA].bytes.begin(), rlp->at(0).values[RLP_DATA].bytes.end()));
}

bool Transaction::hasSignature(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return rlp->at(0).values[RLP_R].bytes.size() > 0 && rlp->at(0).values[RLP_S].bytes.size() > 0;
}

bytes_t Transaction::signature(std::shared_ptr<std::vector<RLPItem>> rlp) {
  bytes_t signatureBytes;
  if (rlp->at(0).values[RLP_R].bytes.size() != 0 && rlp->at(0).values[RLP_S].bytes.size() != 0) {
    signatureBytes.reserve(1 + rlp->at(0).values[RLP_R].bytes.size() + rlp->at(0).values[RLP_S].bytes.size());

    uint8_t v = eip155Compat(rlp->at(0).values[RLP_V].bytes);
    v += 27;

    signatureBytes.push_back(v);
    signatureBytes.insert(signatureBytes.end(), rlp->at(0).values[RLP_R].bytes.begin(), rlp->at(0).values[RLP_R].bytes.end());
    signatureBytes.insert(signatureBytes.end(), rlp->at(0).values[RLP_S].bytes.begin(), rlp->at(0).values[RLP_S].bytes.end());
  }
  return signatureBytes;
}

TransactionActionType Transaction::type(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return rlp->at(0).values[RLP_ADDRESS].bytes.size() == 0 ? 
    TransactionActionType::TRANSACTION_CREATE :
    TransactionActionType::TRANSACTION_CALL;
}

uint256_t Transaction::nonce(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return BigInt::fromBigEndianBytes(rlp->at(0).values[0].bytes);
}

uint256_t Transaction::gasPrice(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return BigInt::fromBigEndianBytes(rlp->at(0).values[1].bytes);
}

uint64_t Transaction::gasLimit(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return Overflow::uint256Cast(BigInt::fromBigEndianBytes(rlp->at(0).values[2].bytes)).first;
}

uint256_t Transaction::value(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return BigInt::fromBigEndianBytes(rlp->at(0).values[4].bytes);
}

bytes_t Transaction::v(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return rlp->at(0).values[RLP_V].bytes;
}

bytes_t Transaction::r(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return rlp->at(0).values[RLP_R].bytes;
}

bytes_t Transaction::s(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return rlp->at(0).values[RLP_S].bytes;
}

bytes_t Transaction::address(std::shared_ptr<std::vector<RLPItem>> rlp) {
  return rlp->at(0).values[RLP_ADDRESS].bytes;
}

bytes_t Transaction::digest(std::shared_ptr<std::vector<RLPItem>> rlp, uint8_t chainId) {

  RLPItem nonce {
    RLPType::STRING,
    rlp->at(0).values[0].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem gasPrice {
    RLPType::STRING,
    rlp->at(0).values[1].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem gasLimit {
    RLPType::STRING,
    rlp->at(0).values[2].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem address {
    RLPType::STRING,
    rlp->at(0).values[3].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem value {
    RLPType::STRING,
    rlp->at(0).values[4].bytes,
    std::vector<RLPItem> {}
  };

  RLPItem data {
    RLPType::STRING,
    rlp->at(0).values[5].bytes,
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

uint8_t Transaction::eip155Compat(const bytes_t& bytes) {
  uint8_t v = static_cast<uint8_t>(bytes[0]);
  if (v == 27) return 0;
  if (v == 28) return 1;
  if (v >= 35) return ((v - 1) % 2);
  return 4;
}

bytes_t Transaction::prefixedBytes(const bytes_t& hash) {
  std::string prefix = "\u0019Ethereum Signed Message:\n" + std::to_string(hash.size());
  std::vector<uint8_t> messagePrefix(prefix.begin(), prefix.end());
  messagePrefix.insert(messagePrefix.end(), hash.begin(), hash.end());
  return Hash::keccak256(messagePrefix);
}