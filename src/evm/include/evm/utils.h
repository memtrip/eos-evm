#include <vector>
#include <evm/types.h>
#include <evm/return_data.h>

class Utils {
  public:
    static void printOpcode(uint8_t value);
    static void printTier(uint8_t value);
    static void printOpcodeHex(uint8_t value);
    static void printInstruction(unsigned int value);
    static void printInstructionList();
    static std::string uint256_2str(uint256_t value);
    static void print_uint256(uint256_t value);
    static uint256_t bigIntFromBigEndianBytes(std::string bytecode_str);
    static store_item_t accountStoreValue(size_t index, account_store_t* store);
    static void printBytes(bytes_t& bytes);
    static env_t env();
    static params_t params(bytes_t data);
    static bytes_t returnDataSlice(ReturnData returnData);
};