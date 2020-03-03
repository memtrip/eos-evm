#include <variant>
#include <evm/opcode.h>
#include <evm/instruction.h>
#include <evm/external.h>
#include <evm/stack.h>


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