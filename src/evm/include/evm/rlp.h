#include <vector>
#include <evm/types.h>

const uint8_t OFFSET_SHORT_STRING = 0x80;
const uint8_t OFFSET_LONG_STRING = 0xb7;
const uint8_t OFFSET_SHORT_LIST = 0xc0;
const uint8_t OFFSET_LONG_LIST = 0xf7;

class RLPDecode {
  public:
    static RLPItem createStr(bytes_t& bytes);
    static RLPItem createList(std::vector<RLPItem>& values);
    static void decode(bytes_t& encoded, std::vector<RLPItem>& list);

  private:
    static void traverse(
      bytes_t& data, 
      uint16_t startPos,
      uint16_t end, 
      std::vector<RLPItem>& list
    );

    static uint16_t calculateLength(
      uint8_t lengthOfLength, 
      const bytes_t& data,
      uint16_t pos
    );
};

class RLPEncode {
  public:
    static bytes_t encode(RLPItem& item);
    static bytes_t encodeString(RLPItem& item);
    static bytes_t encodeList(const RLPItem& item);

  private:
    static bytes_t encode(bytes_t& bytesValue, uint16_t offset);
    static bytes_t toMinimalByteArray(uint16_t value);
    static bytes_t toByteArray(uint16_t value);
    static bytes_t concat(const bytes_t& b1, const bytes_t& b2);
};