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
const size_t SLOAD_GAS = 50;
const size_t BALANCE_GAS = 20;
const size_t EXTCODESIZE_GAS = 20;
const size_t EXTCODEHASH_GAS = 400;
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

enum InstructionRequirementsResult {
  INSTRUCTION_RESULT_OK,
  INSTRUCTION_RESULT_OUT_OF_GAS,
  INSTRUCTION_RESULT_ERROR
};

struct InstructionRequirements {
  gas_t gasCost;
  gas_t provideGas;
  gas_t memoryTotalGas;
  gas_t memoryRequiredSize;
};

typedef std::variant<
  uint8_t,
  InstructionRequirements
> instruction_requirements_result_t;

typedef std::pair<
  InstructionRequirementsResult,
  instruction_requirements_result_t
> instruction_requirements_t;

enum GasResult {
  GAS_RESULT,
  GAS_MEM_RESULT,
  GAS_MEM_PROVIDE_RESULT,
  GAS_MEM_COPY_RESULT,
  GAS_OUT_OF_GAS
};

struct GasMem {
  gas_t gas;
  gas_t memSize;
};

struct GasMemProvided {
  gas_t gas;
  gas_t memSize;
  gas_t requested;
};

struct GasMemCopy {
  gas_t gas;
  gas_t memSize;
  gas_t copy;
};

typedef std::variant<
  gas_t,
  GasMem,
  GasMemProvided,
  GasMemCopy
> gas_result_type_t;

typedef std::pair<GasResult, gas_result_type_t> gas_result_t;

struct MemGas {
  gas_t memGasCost;
  gas_t newMemGas;
  gas_t newMemSize;
};

typedef MemGas mem_gas_t;

class Gasometer {
  public:
    explicit Gasometer(gas_t g): currentGas(g), currentMemGas(0) { };
    gas_t currentGas;
    gas_t currentMemGas;
    instruction_requirements_t requirements(
      External& external,
      instruct_t instruction,
      std::vector<uint256_t>& args,
      gas_t currentMemorySize
    );
    gas_result_t calculate(
      External& external,
      instruct_t instruction,
      std::vector<uint256_t>& args,
      gas_t currentMemorySize
    );
    mem_gas_t memGasCost(gas_t currentMemSize, gas_t memSize) const;
  private:
    static gas_result_t gas(gas_t value);
    static gas_result_t gasMem(gas_t defaultGas, gas_t memoryNeeded);
    static gas_result_t gasMemProvided(gas_t defaultGas, gas_t memoryNeeded, gas_t requested);
    static gas_result_t gasMemCopy(gas_t defaultGas, gas_t memoryNeeded, gas_t copy);
    static gas_result_t outOfGas();
    static gas_t memNeeded(gas_t mem, gas_t add);
};