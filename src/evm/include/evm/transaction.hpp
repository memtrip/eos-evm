#pragma once
#include <memory>
#include <vector>
#include <evm/types.h>
#include <evm/rlp_encode.hpp>
#include <evm/hash.hpp>
#include <evm/overflow.hpp>

class Transaction {
  public:
    static const size_t RLP_ADDRESS = 3;
    static const size_t RLP_DATA = 5;
    static const size_t RLP_V = 6;
    static const size_t RLP_R = 7;
    static const size_t RLP_S = 8;

    static bool hasSignature(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return rlp->at(0).values[RLP_R].bytes.size() > 0 && rlp->at(0).values[RLP_S].bytes.size() > 0;
    }

    static std::shared_ptr<bytes_t> data(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return std::make_shared<bytes_t>(rlp->at(0).values[RLP_DATA].bytes.begin(), rlp->at(0).values[RLP_DATA].bytes.end());
    }

    static TransactionActionType type(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return rlp->at(0).values[RLP_ADDRESS].bytes.size() == 0 ? 
        TransactionActionType::TRANSACTION_CREATE :
        TransactionActionType::TRANSACTION_CALL;
    }

    static uint256_t nonce(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return BigInt::fromBigEndianBytes(rlp->at(0).values[0].bytes);
    }

    static uint256_t gasPrice(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return BigInt::fromBigEndianBytes(rlp->at(0).values[1].bytes);
    }

    static uint64_t gas(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return Overflow::uint256Cast(BigInt::fromBigEndianBytes(rlp->at(0).values[2].bytes)).first;
    }

    static uint256_t value(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return BigInt::fromBigEndianBytes(rlp->at(0).values[4].bytes);
    }

    static bytes_t v(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return rlp->at(0).values[RLP_V].bytes;
    }

    static bytes_t r(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return rlp->at(0).values[RLP_R].bytes;
    }

    static bytes_t s(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return rlp->at(0).values[RLP_S].bytes;
    }

    static bytes_t address(std::shared_ptr<std::vector<RLPItem>> rlp) {
      return rlp->at(0).values[RLP_ADDRESS].bytes;
    }

    static bytes_t signature(std::shared_ptr<std::vector<RLPItem>> rlp) {
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

    static bytes_t digest(std::shared_ptr<std::vector<RLPItem>> rlp, uint8_t chainId) {
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

    static bytes_t prefixedBytes(const bytes_t& hash) {
      std::string prefix = "\u0019Ethereum Signed Message:\n" + std::to_string(hash.size());
      std::vector<uint8_t> messagePrefix(prefix.begin(), prefix.end());
      messagePrefix.insert(messagePrefix.end(), hash.begin(), hash.end());
      return Hash::keccak256(messagePrefix);
    }

  private:
    static uint8_t eip155Compat(const bytes_t& bytes) {
      uint8_t v = static_cast<uint8_t>(bytes[0]);
      if (v == 27) return 0;
      if (v == 28) return 1;
      if (v >= 35) return ((v - 1) % 2);
      return 4;
    }
};