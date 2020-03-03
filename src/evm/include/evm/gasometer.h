#pragma once
#include <variant>
#include <evm/opcode.h>
#include <evm/instruction.h>
#include <evm/external.h>
#include <evm/stack.h>

constexpr uint8_t TIER_STEP_GAS[] = { 0, 2, 3, 5, 8, 10, 20, 0 };

const size_t CALL_STIPEND = 2300;
const size_t SSTORE_SET_GAS = 20000;
const size_t SSTORE_RESET_GAS = 5000;
const size_t SLOAD_GAS = 200;
const size_t BALANCE_GAS = 400;
const size_t EXTCODESIZE_GAS = 20;
const size_t EXTCODEHASH_GAS = 400;
const bool NO_EMPTY = false;
const size_t SHA3_GAS = 30;
const size_t SHA3_WORD_GAS = 6;
const size_t EXTCODECOPY_BASE_GAS = 20;
const size_t LOG_GAS = 375;
const size_t LOG_TOPIC_GAS = 375;
const size_t LOG_DATA_GAS = 8;
const size_t CALL_GAS = 40;
const size_t CALL_NEW_ACCOUNT_GAS = 25000;
const size_t CALL_VALUE_TRANSFER_GAS = 9000;
const size_t CREATE_GAS = 32000;
const size_t EXP_GAS = 10;
const size_t EXP_BYTE_GAS = 10;
const size_t BLOCK_HASH_GAS = 20;
const size_t COPY_GAS = 3;
const size_t MEMORY_GAS = 3;
const size_t QUAD_COEFF_DIV = 512;

struct InstructionRequirements {
  size_t gasCost;
  size_t provideGas;
  size_t memoryTotalGas;
  size_t memoryRequiredSize;
};

enum GasResult {
  GAS_RESULT,
  GAS_MEM_RESULT,
  GAS_MEM_PROVIDE_RESULT,
  GAS_MEM_COPY_RESULT
};

struct GasMem {
  uint256_t defaultGas;
  uint256_t memoryNeeded;
};

struct GasMemProvided {
  uint256_t defaultGas;
  uint256_t memoryNeeded;
  uint256_t requested;
};

struct GasMemCopy {
  uint256_t defaultGas;
  uint256_t memoryNeeded;
  uint256_t copy;
};

typedef std::variant<
  uint256_t,
  GasMem,
  GasMemProvided,
  GasMemCopy
> gas_result_type_t;

typedef std::pair<GasResult, gas_result_type_t> gas_result_t;

class Gasometer {
  public:
    gas_result_t requirements(
      External& external,
      instruct_t instruction,
      StackMachine& stack,
      size_t currentMemorySize
    );
  private:
    gas_result_t gas(uint256_t value);
    gas_result_t gasMem(uint256_t defaultGas, uint256_t memoryNeeded);
    gas_result_t gasMemProvided(uint256_t defaultGas, uint256_t memoryNeeded, uint256_t requested);
    gas_result_t gasMemCopy(uint256_t defaultGas, uint256_t memoryNeeded, uint256_t copy);
};