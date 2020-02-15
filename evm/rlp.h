#include <vector>
#include "types.h"

enum RLPType {
  STRING,
  LIST
};

struct RLPItem {
  RLPType type;
  std::vector<uint8_t> bytes;
  std::vector<RLPItem> values;
};

class RLPDecode {
  public:
    static const uint8_t OFFSET_SHORT_STRING;
    static const uint8_t OFFSET_LONG_STRING;
    static const uint8_t OFFSET_SHORT_LIST;
    static const uint8_t OFFSET_LONG_LIST;

    static RLPItem createStr(std::vector<uint8_t> bytes);
    static RLPItem createList(std::vector<RLPItem> values);

    static void decode(std::vector<uint8_t>, std::vector<RLPItem>& list);

  private:
    static void traverse(
      std::vector<uint8_t>& data, 
      uint16_t start,
      uint16_t end, 
      std::vector<RLPItem>& list
    );

    static uint16_t calculateLength(
      uint8_t lengthOfLength, 
      std::vector<uint8_t>& data,
      uint16_t position
    );
};