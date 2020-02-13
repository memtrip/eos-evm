#include <vector>
#include "types.h"

class Utils {
  public:
    static void printOpcode(unsigned char value);
    static void printTier(unsigned char value);
    static void printOpcodeHex(unsigned char value);
    static void printInstruction(unsigned int value);
    static void printInstructionList();
    static std::vector<uint8_t> hex2bin(const std::string& hex);
    static std::string uint256_2str(uint256_t value);
    static void print_uint256(uint256_t value);
    static uint256_t bigIntFromBigEndianBytes(std::string bytecode_str);
    static bool accountStoreContains(uint256_t key, std::map<uint256_t, uint256_t>* store);
    static uint256_t accountStoreValue(uint256_t key, std::map<uint256_t, uint256_t>* store);
    static std::string bytesTohex(std::vector<uint8_t>* bytes);
};