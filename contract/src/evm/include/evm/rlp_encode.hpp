#pragma once
#include <evm/types.h>

class RLPEncode {
  public:
    static bytes_t encode(const RLPItem& item) {
      if (item.type == RLPType::STRING) {
        return encodeString(std::get<bytes_t>(item.value));
      } else {
        return encodeList(std::get<rlp_list_t>(item.value));
      }
    }

    static bytes_t encodeString(const bytes_t& bytes) {
      return encode(bytes, OFFSET_SHORT_STRING);
    }

    static bytes_t encodeList(const rlp_list_t& values) {
      if (values.size() == 0) {
        bytes_t emptyBytes = bytes_t();
        return encode(emptyBytes, OFFSET_SHORT_LIST);
      } else {
        bytes_t result;
        for (int i = 0; i < values.size(); i++) {
          bytes_t encodedBytes = encode(values[i]);
          result = concat(result, encodedBytes);
        }
        return encode(result, OFFSET_SHORT_LIST);
      }
    }

  private:
    static bytes_t encode(const bytes_t& bytesValue, uint16_t offset) {
      if (bytesValue.size() == 1
        && offset == OFFSET_SHORT_STRING
        && bytesValue[0] <= 0x7f
      ) {
        return bytesValue;
      } else if (bytesValue.size() <= 55) {
        bytes_t result;
        result.reserve(bytesValue.size() + 1);
        result.push_back(static_cast<uint8_t>(offset + bytesValue.size()));
        result.insert(result.begin() + 1, std::begin(bytesValue), std::end(bytesValue));
        return result;
      } else {
        bytes_t encodedStringLength = toMinimalByteArray(bytesValue.size());
        bytes_t result;
        result.reserve(bytesValue.size() + encodedStringLength.size() + 1);
        result.push_back(static_cast<uint8_t>((offset + 0x37) + encodedStringLength.size()));
        result.insert(
          result.begin() + 1,
          encodedStringLength.begin(), 
          encodedStringLength.end()
        );
        result.insert(
          result.begin() + 1 + encodedStringLength.size(), 
          bytesValue.begin(), 
          bytesValue.end()
        );
        return result;
      }
    }

    static bytes_t toMinimalByteArray(uint16_t value) {
      bytes_t encoded = toByteArray(value);
      for (int i = 0; i < encoded.size(); i++) {
        if (encoded[i] != 0) {
          return bytes_t(std::begin(encoded) + i, std::end(encoded));
        } 
      }

      return bytes_t();
    }

    static bytes_t toByteArray(uint16_t value) {
      return {
        static_cast<uint8_t>((value >> 24) & 0xff),
        static_cast<uint8_t>((value >> 16) & 0xff),
        static_cast<uint8_t>((value >> 8) & 0xff),
        static_cast<uint8_t>(value & 0xff)
      };
    }

    static bytes_t concat(const bytes_t& b1, const bytes_t& b2) {
      bytes_t result = b1;
      result.insert(result.end(), b2.begin(), b2.end());
      return result;
    }
};