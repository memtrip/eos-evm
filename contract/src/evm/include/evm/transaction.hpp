#pragma once
#include <vector>
#include <variant>
#include <evm/types.h>
#include <evm/rlp_encode.hpp>
#include <evm/hash.hpp>
#include <evm/overflow.hpp>
#include <evm/hex.hpp>

class Transaction {
  public:
    static const size_t RLP_NONCE = 0;
    static const size_t RLP_GAS_PRICE = 1;
    static const size_t RLP_GAS_LIMIT = 2;
    static const size_t RLP_ADDRESS = 3;
    static const size_t RLP_VALUE = 4;
    static const size_t RLP_DATA = 5;
    static const size_t RLP_V = 6;
    static const size_t RLP_R = 7;
    static const size_t RLP_S = 8;

    static bool hasSignature(rlp_list_t* rlp) {
      return std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_R].value).size() > 0 
        && std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_S].value).size() > 0;
    }

    static bytes_t data(rlp_list_t* rlp) {
      return std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_DATA].value);
    }

    static TransactionActionType type(rlp_list_t* rlp) {
      return std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_ADDRESS].value).size() == 0 ? 
        TransactionActionType::TRANSACTION_CREATE :
        TransactionActionType::TRANSACTION_CALL;
    }

    static uint256_t nonce(rlp_list_t* rlp) {
      return BigInt::fromBigEndianBytes(std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_NONCE].value));
    }

    static uint256_t gasPrice(rlp_list_t* rlp) {
      return BigInt::fromBigEndianBytes(std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_GAS_PRICE].value));
    }

    static gas_t gas(rlp_list_t* rlp) {
      return Overflow::uint256Cast(
        BigInt::fromBigEndianBytes(std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_GAS_LIMIT].value))
      ).first;
    }

    static bytes_t address(rlp_list_t* rlp) {
      return std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_ADDRESS].value);
    }

    static uint256_t value(rlp_list_t* rlp) {
      return BigInt::fromBigEndianBytes(std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_VALUE].value));
    }

    static bytes_t v(rlp_list_t* rlp) {
      return std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_V].value);
    }

    static bytes_t r(rlp_list_t* rlp) {
      bytes_t r = std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_R].value);
      if (r.size() > 0) Hex::padWordSize(r);
      return r;
    }

    static bytes_t s(rlp_list_t* rlp) {
      bytes_t s = std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_S].value);
      if (s.size() > 0) Hex::padWordSize(s);
      return s;
    }

    static bytes_t signature(rlp_list_t* rlp, uint256_t chainId) {
      bytes_t signatureBytes;
      bytes_t rBytes = r(rlp);
      bytes_t sBytes = s(rlp);
      bytes_t vBytes = v(rlp);

      if (rBytes.size() != 0 && sBytes.size() != 0) {
        signatureBytes.reserve(1 + rBytes.size() + sBytes.size()); 

        uint8_t v = eip155Compat(vBytes);
        v += 27;

        signatureBytes.push_back(v);
        signatureBytes.insert(signatureBytes.end(), rBytes.begin(), rBytes.end());
        signatureBytes.insert(signatureBytes.end(), sBytes.begin(), sBytes.end());
      }
      return signatureBytes;
    }

    static bytes_t digest(rlp_list_t* rlp, uint8_t chainId) {
      RLPItem nonce {
        RLPType::STRING,
        std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_NONCE].value)
      };

      RLPItem gasPrice {
        RLPType::STRING,
        std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_GAS_PRICE].value)
      };

      RLPItem gasLimit {
        RLPType::STRING,
        std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_GAS_LIMIT].value)
      };

      RLPItem address {
        RLPType::STRING,
        std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_ADDRESS].value)
      };

      RLPItem value {
        RLPType::STRING,
        std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_VALUE].value)
      };

      RLPItem data {
        RLPType::STRING,
        std::get<bytes_t>(std::get<rlp_list_t>(rlp->at(0).value)[RLP_DATA].value)
      };

      RLPItem v {
        RLPType::STRING,
        bytes_t { chainId }
      };

      RLPItem r {
        RLPType::STRING,
        bytes_t()
      };

      RLPItem s {
        RLPType::STRING,
        bytes_t()
      };

      RLPItem itemList {
        RLPType::LIST,
        rlp_list_t { 
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
      bytes_t messagePrefix(prefix.begin(), prefix.end());
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