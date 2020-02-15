#include "rlp.h"

const uint8_t RLPDecode::OFFSET_SHORT_STRING = 0x80;
const uint8_t RLPDecode::OFFSET_LONG_STRING = 0xb7;
const uint8_t RLPDecode::OFFSET_SHORT_LIST = 0xc0;
const uint8_t RLPDecode::OFFSET_LONG_LIST = 0xf7;

RLPItem RLPDecode::createStr(std::vector<uint8_t> bytes) {
  return {
    RLPType::STRING,
    bytes,
    std::vector<RLPItem>()
  };
}

RLPItem RLPDecode::createList(std::vector<RLPItem> values) {
  return {
    RLPType::LIST,
    std::vector<uint8_t>(),
    values
  };
}

void RLPDecode::decode(std::vector<uint8_t> encoded, std::vector<RLPItem>& list) {
  traverse(encoded, 0, encoded.size(), list);
}

void RLPDecode::traverse(
  std::vector<uint8_t>& data, 
  uint16_t startPos,
  uint16_t end, 
  std::vector<RLPItem>& list
) {
  if (data.size() == 0) return;

  while (startPos < end) {
    uint8_t prefix = data[startPos] & 0xff;
    if (prefix < OFFSET_SHORT_STRING) {
      std::vector<uint8_t> item = { prefix };
      list.push_back(createStr(item));
      startPos += 1;
    } else if (prefix == OFFSET_SHORT_STRING) {
      list.push_back(createStr(std::vector<uint8_t>()) );
      startPos += 1;
    } else if (prefix > OFFSET_SHORT_STRING && prefix <= OFFSET_LONG_STRING) {
      uint8_t strLen = prefix - OFFSET_SHORT_STRING;
      list.push_back(
        createStr(
          std::vector<uint8_t>(
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
          std::vector<uint8_t>(
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
  std::vector<uint8_t>& data,
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