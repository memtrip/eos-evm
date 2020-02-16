#include <evm/rlp.h>

RLPItem RLPDecode::createStr(bytes_t bytes) {
  return {
    RLPType::STRING,
    bytes,
    std::vector<RLPItem>()
  };
}

RLPItem RLPDecode::createList(std::vector<RLPItem> values) {
  return {
    RLPType::LIST,
    bytes_t(),
    values
  };
}

void RLPDecode::decode(bytes_t encoded, std::vector<RLPItem>& list) {
  traverse(encoded, 0, encoded.size(), list);
}

void RLPDecode::traverse(
  bytes_t& data, 
  uint16_t startPos,
  uint16_t end, 
  std::vector<RLPItem>& list
) {
  if (data.size() == 0) return;

  while (startPos < end) {
    uint8_t prefix = data[startPos] & 0xff;
    if (prefix < OFFSET_SHORT_STRING) {
      bytes_t item = { prefix };
      list.push_back(createStr(item));
      startPos += 1;
    } else if (prefix == OFFSET_SHORT_STRING) {
      list.push_back(createStr(bytes_t()) );
      startPos += 1;
    } else if (prefix > OFFSET_SHORT_STRING && prefix <= OFFSET_LONG_STRING) {
      uint8_t strLen = prefix - OFFSET_SHORT_STRING;
      list.push_back(
        createStr(
          bytes_t(
            data.begin() + startPos + 1, 
            data.begin() + startPos + strLen + 1
          )
        )
      );
      startPos += (strLen + 1);
    } else if (prefix > OFFSET_LONG_STRING && prefix < OFFSET_SHORT_LIST) {
      uint8_t lenOfStrLen = prefix - OFFSET_LONG_STRING;
      uint16_t strLen = calculateLength(lenOfStrLen, data, startPos);
      list.push_back(
        createStr(
          bytes_t(
            data.begin() + startPos + lenOfStrLen + 1, 
            data.begin() + startPos + lenOfStrLen + strLen + 1
          )
        )
      );
      startPos += (lenOfStrLen + strLen + 1);
    } else if (prefix >= OFFSET_SHORT_LIST && prefix <= OFFSET_LONG_LIST) {
      uint8_t listLen = prefix - OFFSET_SHORT_LIST;
      std::vector<RLPItem> newLevelList = std::vector<RLPItem>();
      traverse(data, startPos + 1, startPos + listLen + 1, newLevelList);
      list.push_back(createList(newLevelList));
      startPos += (listLen + 1);
    } else if (prefix > OFFSET_LONG_LIST) {
      uint8_t lenOfListLen = (prefix - OFFSET_LONG_LIST);
      uint16_t listLen = calculateLength(lenOfListLen, data, startPos);
      std::vector<RLPItem> newLevelList = std::vector<RLPItem>();
      traverse(
        data, 
        startPos + lenOfListLen + 1, 
        startPos + lenOfListLen + listLen + 1, 
        newLevelList
      );
      list.push_back(createList(newLevelList));
      startPos += (lenOfListLen + listLen + 1);
    }
  }
}

uint16_t RLPDecode::calculateLength(
  uint8_t lengthOfLength, 
  bytes_t& data,
  uint16_t pos
) {
  uint8_t pow = lengthOfLength - 1;
  uint16_t length = 0;
  for (int i = 1; i <= lengthOfLength; ++i) {
    length += (data[pos + i] & 0xff) << (8 * pow);
    pow--;
  }
  return length;
}

bytes_t RLPEncode::encode(RLPItem item) {
  if (item.type == RLPType::STRING) {
    return encodeString(item);
  } else {
    return encodeList(item);
  }
}

bytes_t RLPEncode::encodeString(RLPItem item) {
  return encode(item.bytes, OFFSET_SHORT_STRING);
}

bytes_t RLPEncode::encodeList(RLPItem item) {
  std::vector<RLPItem> values = item.values;
  if (values.size() == 0) {
    return encode(bytes_t(), OFFSET_SHORT_LIST);
  } else {
    bytes_t result;
    for (int i = 0; i < values.size(); i++) {
      result = concat(result, encode(values[i]));
    }
    return encode(result, OFFSET_SHORT_LIST);
  }
}

bytes_t RLPEncode::encode(bytes_t bytesValue, uint16_t offset) {
  if (bytesValue.size() == 1
    && offset == OFFSET_SHORT_STRING
    && bytesValue[0] >= 0x00
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
};

bytes_t RLPEncode::toMinimalByteArray(uint16_t value) {
  bytes_t encoded = toByteArray(value);
  for (int i = 0; i < encoded.size(); i++) {
    if (encoded[i] != 0) {
      return bytes_t(std::begin(encoded) + i, std::end(encoded));
    } 
  }

  return bytes_t();
};

bytes_t RLPEncode::toByteArray(uint16_t value) {
  return {
    static_cast<uint8_t>((value >> 24) & 0xff),
    static_cast<uint8_t>((value >> 16) & 0xff),
    static_cast<uint8_t>((value >> 8) & 0xff),
    static_cast<uint8_t>(value & 0xff)
  };
};

bytes_t RLPEncode::concat(bytes_t b1, bytes_t b2) {
  bytes_t result = b1;
  result.insert(result.end(), b2.begin(), b2.end());
  return result;
};