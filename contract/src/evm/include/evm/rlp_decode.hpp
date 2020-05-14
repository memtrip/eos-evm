#pragma once
#include <memory>
#include <evm/types.h>

class RLPDecode {
  public:
    static void decode(const bytes_t& encoded, rlp_list_t* output) {
      traverse(encoded, 0, encoded.size(), output);
    }

  private:
    static void traverse(
      const bytes_t& data, 
      uint16_t startPos,
      uint16_t end, 
      rlp_list_t* output
    ) {
      if (data.size() == 0) return;
      while (startPos < end) {
        uint8_t prefix = data[startPos] & 0xff;
        if (prefix < OFFSET_SHORT_STRING) {
          output->push_back({
            RLPType::STRING,
            bytes_t { prefix }
          });
          startPos += 1;
        } else if (prefix == OFFSET_SHORT_STRING) {
          output->push_back({
            RLPType::STRING,
            bytes_t()
          });
          startPos += 1;
        } else if (prefix > OFFSET_SHORT_STRING && prefix <= OFFSET_LONG_STRING) {
          uint8_t strLen = prefix - OFFSET_SHORT_STRING;
          output->push_back({
            RLPType::STRING,
            bytes_t(
              data.begin() + startPos + 1, 
              data.begin() + startPos + strLen + 1
            )
          });
          startPos += (strLen + 1);
        } else if (prefix > OFFSET_LONG_STRING && prefix < OFFSET_SHORT_LIST) {
          uint8_t lenOfStrLen = prefix - OFFSET_LONG_STRING;
          uint16_t strLen = calculateLength(lenOfStrLen, data, startPos);
          output->push_back({
            RLPType::STRING,
            bytes_t(
              data.begin() + startPos + lenOfStrLen + 1, 
              data.begin() + startPos + lenOfStrLen + strLen + 1
            )
          });
          startPos += (lenOfStrLen + strLen + 1);
        } else if (prefix >= OFFSET_SHORT_LIST && prefix <= OFFSET_LONG_LIST) {
          uint8_t listLen = prefix - OFFSET_SHORT_LIST;
          rlp_list_t* newLevelList = new rlp_list_t();
          traverse(data, startPos + 1, startPos + listLen + 1, newLevelList);
          output->push_back({
            RLPType::LIST,
            rlp_list_t(newLevelList->begin(), newLevelList->end())
          });
          startPos += (listLen + 1);
          delete newLevelList;
        } else if (prefix > OFFSET_LONG_LIST) {
          uint8_t lenOfListLen = (prefix - OFFSET_LONG_LIST);
          uint16_t listLen = calculateLength(lenOfListLen, data, startPos);
          rlp_list_t* newLevelList = new rlp_list_t();
          traverse(
            data, 
            startPos + lenOfListLen + 1, 
            startPos + lenOfListLen + listLen + 1, 
            newLevelList
          );
          output->push_back({
            RLPType::LIST,
            rlp_list_t(newLevelList->begin(), newLevelList->end())
          });
          startPos += (lenOfListLen + listLen + 1);
          delete newLevelList;
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