#include <vector>
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/vm_result.h>

class Utils {
  public:
    static void printOpcode(uint8_t value);
    static void printTier(uint8_t value);
    static void printOpcodeHex(uint8_t value);
    static void printInstruction(unsigned int value);
    static void printInstructionList();
    static std::string uint256_2str(uint256_t value);
    static uint256_t bigIntFromBigEndianBytes(std::string bytecode_str);
    static store_item_t accountStoreValue(size_t index, account_store_t* store);
    static env_t env();
    static params_t params(bytes_t code, bytes_t data);
    static params_t createParams(bytes_t code, bytes_t data);
    static bytes_t returnDataSlice(ReturnData returnData);
    static gas_t gasLeft(exec_result_t vm_result);
};