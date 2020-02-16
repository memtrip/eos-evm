#include <vector>
#include <evm/types.h>

class Utils {
  public:
    static void printOpcode(unsigned char value);
    static void printTier(unsigned char value);
    static void printOpcodeHex(unsigned char value);
    static void printInstruction(unsigned int value);
    static void printInstructionList();
    static std::string uint256_2str(uint256_t value);
    static void print_uint256(uint256_t value);
    static uint256_t bigIntFromBigEndianBytes(std::string bytecode_str);
    static store_item_t accountStoreValue(size_t index, account_store_t* store);
    static void printBytes(bytes_t& bytes);
    static env_t env();
};