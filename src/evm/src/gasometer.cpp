#include <evm/gasometer.h>
#include <evm/overflow.h>
#include <evm/big_int.h>

instruction_requirements_t Gasometer::requirements(
  uint8_t opcode,
  instruct_t instruction,
  gas_t currentMemorySize,
  std::shared_ptr<GasCalculation> gasCalculation,
  std::shared_ptr<StackMachine> stack,
  std::shared_ptr<External> external
) {
  uint8_t tier = Instruction::tier(instruction);
  uint8_t tierGas = TIER_STEP_GAS[tier];
  gas_t defaultGas = tierGas;

  gas_result_t result;
  switch (opcode) {
    case Opcode::JUMPDEST:
    case Opcode::SSTORE:
    case Opcode::SLOAD:
    case Opcode::BALANCE:
    case Opcode::EXTCODESIZE:
    case Opcode::EXTCODEHASH:
    case Opcode::SELFDESTRUCT:
    case Opcode::MSTORE:
    case Opcode::MLOAD:
    case Opcode::MSTORE8:
    case Opcode::REVERT:
    case Opcode::RETURN:
    case Opcode::SHA3:
    case Opcode::CALLDATACOPY:
    case Opcode::CODECOPY:
    case Opcode::RETURNDATACOPY:
    case Opcode::EXTCODECOPY:
    case Opcode::LOG0:
    case Opcode::LOG1:
    case Opcode::LOG2:
    case Opcode::LOG3:
    case Opcode::LOG4:
    case Opcode::CALL:
    case Opcode::CALLCODE:
    case Opcode::DELEGATECALL:
    case Opcode::STATICCALL:
    case Opcode::CREATE:
    case Opcode::CREATE2:
    case Opcode::EXP:
    case Opcode::BLOCKHASH:
      result = std::invoke(
        gasCalculation->values[opcode], 
        gasCalculation, 
        instruction,
        defaultGas,
        currentGas,
        currentMemorySize,
        stack,
        external
      );
      break;
    default:
      result = std::make_pair(GasResult::GAS_RESULT, defaultGas);
      break;
  }

  switch (result.first) {
    case GasResult::GAS_RESULT:
      {
        gas_t gas = std::get<gas_t>(result.second);

        InstructionRequirements instructionRequirements {
          gas,
          0,
          currentMemGas,
          0
        };

        return std::make_pair(
          InstructionRequirementsResult::INSTRUCTION_RESULT_OK,
          instructionRequirements
        );
      }
    case GasResult::GAS_MEM_RESULT:
      {
        GasMem gasMem = std::get<GasMem>(result.second);

        mem_gas_t memGas = memGasCost(currentMemorySize, gasMem.memSize);

        gas_t gas = gasMem.gas + memGas.memGasCost;

        InstructionRequirements instructionRequirements {
          gas,
          0,
          memGas.newMemGas,
          memGas.newMemSize
        };

        return std::make_pair(
          InstructionRequirementsResult::INSTRUCTION_RESULT_OK,
          instructionRequirements
        );
      }
    case GasResult::GAS_MEM_PROVIDE_RESULT:
      {
        GasMemProvided gasMemProvided = std::get<GasMemProvided>(result.second);

        mem_gas_t memGas = memGasCost(currentMemorySize, gasMemProvided.memSize);

        gas_t gas = gasMemProvided.gas + memGas.memGasCost;
        // TODO: calculate provided
        gas_t provided = 0;
        gas_t totalGas = gas + provided;

        InstructionRequirements instructionRequirements {
          totalGas,
          provided,
          memGas.newMemGas,
          memGas.newMemSize
        };

        return std::make_pair(
          InstructionRequirementsResult::INSTRUCTION_RESULT_OK,
          instructionRequirements
        );
      }
    case GasResult::GAS_MEM_COPY_RESULT:
      {
        GasMemCopy gasMemCopy = std::get<GasMemCopy>(result.second);

        mem_gas_t memGas = memGasCost(currentMemorySize, gasMemCopy.memSize);

        gas_t copy = Overflow::numWords(gasMemCopy.copy);
        gas_t copy_gas = COPY_GAS * copy;
        gas_t gas = gasMemCopy.gas + copy_gas + memGas.memGasCost;

        InstructionRequirements instructionRequirements {
          gas,
          0,
          memGas.newMemGas,
          memGas.newMemSize
        };

        return std::make_pair(
          InstructionRequirementsResult::INSTRUCTION_RESULT_OK,
          instructionRequirements
        );
      }
    case GasResult::GAS_OUT_OF_GAS:
      return std::make_pair(
        InstructionRequirementsResult::INSTRUCTION_RESULT_OUT_OF_GAS,
        0
      );
  }
}

mem_gas_t Gasometer::memGasCost(gas_t currentMemSize, gas_t memSize) const {

  gas_t requiredMemSizeRounded = Overflow::toWordSize(memSize).first << 5;

  if (requiredMemSizeRounded > currentMemSize) {
    gas_t s = requiredMemSizeRounded >> 5;
    gas_t a = Overflow::mul(s, MEMORY_GAS).first;
    gas_t b = Overflow::uint256Cast((uint256_t(s) * uint256_t(s)) >> 9).first;
    gas_t newMemGas = a + b;
    mem_gas_t memGas {
      newMemGas - currentMemGas,
      newMemGas,
      requiredMemSizeRounded
    };
    return memGas;
  } else {
    mem_gas_t memGas {
      0,
      currentMemGas,
      requiredMemSizeRounded
    };
    return memGas;
  }
}