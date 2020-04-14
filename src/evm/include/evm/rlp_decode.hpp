#pragma once
#include <memory>
#include <evm/types.h>

class RLPDecode {
  public:
    static void decode(const bytes_t& encoded, std::shared_ptr<std::vector<RLPItem>> list) {
      traverse(encoded, 0, encoded.size(), list);
    }

  private:
    static void traverse(
      const bytes_t& data, 
      uint16_t startPos,
      uint16_t end, 
      std::shared_ptr<std::vector<RLPItem>> list
    ) {
      if (data.size() == 0) return;

      while (startPos < end) {
        uint8_t prefix = data[startPos] & 0xff;
        if (prefix < RLPItem::OFFSET_SHORT_STRING) {
          list->push_back({
            RLPType::STRING,
            bytes_t { prefix },
            std::vector<RLPItem>()
          });
          startPos += 1;
        } else if (prefix == RLPItem::OFFSET_SHORT_STRING) {
          list->push_back({
            RLPType::STRING,
            bytes_t(),
            std::vector<RLPItem>()
          });
          startPos += 1;
        } else if (prefix > RLPItem::OFFSET_SHORT_STRING && prefix <= RLPItem::OFFSET_LONG_STRING) {
          uint8_t strLen = prefix - RLPItem::OFFSET_SHORT_STRING;
          list->push_back({
            RLPType::STRING,
            bytes_t(
              data.begin() + startPos + 1, 
              data.begin() + startPos + strLen + 1
            ),
            std::vector<RLPItem>()
          });
          startPos += (strLen + 1);
        } else if (prefix > RLPItem::OFFSET_LONG_STRING && prefix < RLPItem::OFFSET_SHORT_LIST) {
          uint8_t lenOfStrLen = prefix - RLPItem::OFFSET_LONG_STRING;
          uint16_t strLen = calculateLength(lenOfStrLen, data, startPos);
          list->push_back({
            RLPType::STRING,
            bytes_t(
              data.begin() + startPos + lenOfStrLen + 1, 
              data.begin() + startPos + lenOfStrLen + strLen + 1
            ),
            std::vector<RLPItem>()
          });
          startPos += (lenOfStrLen + strLen + 1);
        } else if (prefix >= RLPItem::OFFSET_SHORT_LIST && prefix <= RLPItem::OFFSET_LONG_LIST) {
          uint8_t listLen = prefix - RLPItem::OFFSET_SHORT_LIST;
          std::shared_ptr<std::vector<RLPItem>> newLevelList = std::make_shared<std::vector<RLPItem>>();
          traverse(data, startPos + 1, startPos + listLen + 1, newLevelList);
          list->push_back({
            RLPType::LIST,
            bytes_t(),
            std::vector<RLPItem>(newLevelList->begin(), newLevelList->end())
          });
          startPos += (listLen + 1);
        } else if (prefix > RLPItem::OFFSET_LONG_LIST) {
          uint8_t lenOfListLen = (prefix - RLPItem::OFFSET_LONG_LIST);
          uint16_t listLen = calculateLength(lenOfListLen, data, startPos);
          std::shared_ptr<std::vector<RLPItem>> newLevelList = std::make_shared<std::vector<RLPItem>>();
          traverse(
            data, 
            startPos + lenOfListLen + 1, 
            startPos + lenOfListLen + listLen + 1, 
            newLevelList
          );
          list->push_back({
            RLPType::LIST,
            bytes_t(),
            std::vector<RLPItem>(newLevelList->begin(), newLevelList->end())
          });
          startPos += (lenOfListLen + listLen + 1);
        }
      }
    }

    static uint16_t calculateLength(
      uint8_t lengthOfLength, 
      const bytes_t& data,
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
};