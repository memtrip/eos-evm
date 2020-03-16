#include <evm/gasometer.h>
#include <evm/overflow.h>
#include <evm/utils.h>
#include <evm/big_int.h>

Gasometer::Gasometer(gas_t currentGasArg) {
  currentGas = currentGasArg;
  currentMemGas = 0;
}

instruction_requirements_t Gasometer::requirements(
  External& external,
  instruct_t instruction,
  StackMachine& stack,
  size_t currentMemorySize
) {
  gas_result_t result = calculate(
    external,
    instruction,
    stack,
    currentMemorySize
  );

  switch (result.first) {
    case GasResult::GAS_RESULT:
      {
        gas_t gas = std::get<gas_t>(result.second);

        InstructionRequirements instructionRequirements {
          gas,
          0,
          0,
          currentMemGas
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
          memGas.newMemSize,
          memGas.newMemGas
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
          memGas.newMemSize,
          memGas.newMemGas
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
          memGas.newMemSize,
          memGas.newMemGas
        };

        return std::make_pair(
          InstructionRequirementsResult::INSTRUCTION_RESULT_OK,
          instructionRequirements
        );
      }
    case GasResult::OUT_OF_GAS:
      return std::make_pair(
        InstructionRequirementsResult::INSTRUCTION_RESULT_ERROR,
        0
      );
  }
}

gas_result_t Gasometer::calculate(
  External& external,
  instruct_t instruction,
  StackMachine& stack,
  size_t currentMemorySize
) {
  uint8_t tier = Instruction::tier(instruction);
  uint8_t tierGas = TIER_STEP_GAS[tier];
  uint256_t defaultGas = uint256_t(tierGas);

  switch (Instruction::opcode(instruction)) {
    case Opcode::JUMPDEST:
      return gas(uint256_t(1));
    case Opcode::SSTORE:
      {
        if (currentGas <= CALL_STIPEND) {
          return outOfGas();
        }

        uint256_t address = stack.peek(0);
        uint256_t newVal = stack.peek(1);
        uint256_t current = BigInt::fromBigEndianBytes(external.storageAt(address));

        uint256_t storeGasCost;
        if (current == 0 && newVal != 0) {
          storeGasCost = uint256_t(SSTORE_SET_GAS);
        } else {
          storeGasCost = uint256_t(SSTORE_RESET_GAS);
        }

        return gas(uint256_t(storeGasCost));
      }
    case Opcode::SLOAD:
      return gas(uint256_t(SLOAD_GAS));
    case Opcode::BALANCE:
      return gas(uint256_t(BALANCE_GAS));;
    case Opcode::EXTCODESIZE:
      return gas(uint256_t(EXTCODESIZE_GAS));
    case Opcode::EXTCODEHASH:
      return gas(uint256_t(EXTCODEHASH_GAS));
    case Opcode::SELFDESTRUCT:
      // No empty, new account gas calculation is not included
      return gas(uint256_t(0));
    case Opcode::MSTORE:
    case Opcode::MLOAD:
      return gasMem(defaultGas, memNeeded(stack.peek(0), uint256_t(32)));
    case Opcode::MSTORE8:
      return gasMem(defaultGas, memNeeded(stack.peek(0), uint256_t(1)));
    case Opcode::RETURN:
    case Opcode::REVERT:
      return gasMem(defaultGas, memNeeded(stack.peek(0), stack.peek(1)));
    case Opcode::SHA3:
      {
        gas_t words = Overflow::toWordSize(stack.peek(1)).first;
        uint256_t gas = uint256_t(SHA3_GAS + SHA3_WORD_GAS * words);
        return gasMem(gas, memNeeded(stack.peek(0), stack.peek(1)));
      }
    case Opcode::CALLDATACOPY:
    case Opcode::CODECOPY:
    case Opcode::RETURNDATACOPY:
      return gasMemCopy(
        defaultGas, 
        memNeeded(stack.peek(0), stack.peek(2)), 
        stack.peek(2)
      );
    case Opcode::EXTCODECOPY:
      return gasMemCopy(
        uint256_t(EXTCODECOPY_BASE_GAS), 
        memNeeded(stack.peek(1), stack.peek(3)), 
        stack.peek(3)
      );
    case Opcode::LOG0:
    case Opcode::LOG1:
    case Opcode::LOG2:
    case Opcode::LOG3:
    case Opcode::LOG4:
      {
        uint256_t noOfTopics = Instruction::logTopics(instruction);
        uint256_t logGas = uint256_t(LOG_GAS + LOG_TOPIC_GAS * noOfTopics);
        uint256_t dataGas = stack.peek(1) * uint256_t(LOG_DATA_GAS);
        uint256_t gas = dataGas + logGas;
        return gasMem(gas, memNeeded(stack.peek(0), stack.peek(1)));
      }
    case Opcode::CALL:
    case Opcode::CALLCODE:
      {
        uint256_t gas = CALL_GAS;
        uint256_t mem = std::max(
          memNeeded(stack.peek(5), stack.peek(6)),
          memNeeded(stack.peek(3), stack.peek(4))
        );
        uint256_t address = stack.peek(1);
        bool isValueTransfer = stack.peek(2) == UINT256_ZERO; 

        // No empty, new account gas calculation is not included

        if (isValueTransfer) {
          gas = gas + CALL_VALUE_TRANSFER_GAS;
        }

        uint256_t requested = stack.peek(0);

        return gasMemProvided(gas, mem, requested);
      }
    case Opcode::DELEGATECALL:
    case Opcode::STATICCALL:
      {
        uint256_t gas = CALL_GAS;
        uint256_t mem = std::max(
          memNeeded(stack.peek(4), stack.peek(5)),
          memNeeded(stack.peek(2), stack.peek(3))
        );
        uint256_t requested = stack.peek(0);
        return gasMemProvided(gas, mem, requested);
      }
    case Opcode::CREATE:
      {
        uint256_t start = stack.peek(1);
        uint256_t len = stack.peek(2);
        uint256_t gas = uint256_t(CREATE_GAS);
        uint256_t mem = memNeeded(start, len);
        return gasMemProvided(gas, mem, uint256_t());
      }
    case Opcode::CREATE2:
      {
        uint256_t start = stack.peek(1);
        uint256_t len = stack.peek(2);

        gas_t word = Overflow::toWordSize(len).first;
        gas_t wordGas = SHA3_WORD_GAS * word;
        gas_t gas = Overflow::add(CREATE_GAS, wordGas).first;
        uint256_t mem = memNeeded(stack.peek(2), stack.peek(3));

        return gasMemProvided(uint256_t(gas), mem, uint256_t());
      }
    case Opcode::EXP:
      {
        uint256_t exponent = stack.peek(1);
        gas_t bytes = static_cast<gas_t>(intx::count_significant_words<uint8_t>(exponent));
        gas_t cost = (EXP_GAS + EXP_BYTE_GAS) * bytes;
        return gas(uint256_t(cost));
      }
    case Opcode::BLOCKHASH:
      return gas(uint256_t(BLOCK_HASH_GAS));
  }

  return gas(defaultGas);
}

gas_result_t Gasometer::gas(uint256_t value) {

  gas_result_t result {
    GasResult::GAS_RESULT,
    static_cast<gas_t>(value)
  };
  return result;
}

gas_result_t Gasometer::gasMem(uint256_t defaultGas, uint256_t memoryNeeded) {
  GasMem gasMem {
    static_cast<gas_t>(defaultGas),
    static_cast<gas_t>(memoryNeeded)
  };
  gas_result_t result {
    GasResult::GAS_MEM_RESULT,
    gasMem
  };
  return result;
}

gas_result_t Gasometer::gasMemProvided(uint256_t defaultGas, uint256_t memoryNeeded, uint256_t requested) {
  GasMemProvided gasMemProvided {
    static_cast<gas_t>(defaultGas),
    static_cast<gas_t>(memoryNeeded),
    static_cast<gas_t>(requested)
  };
  gas_result_t result {
    GasResult::GAS_MEM_PROVIDE_RESULT,
    gasMemProvided
  };
  return result;
}

gas_result_t Gasometer::gasMemCopy(uint256_t defaultGas, uint256_t memoryNeeded, uint256_t copy) {
  GasMemCopy gasMemCopy {
    static_cast<gas_t>(defaultGas),
    static_cast<gas_t>(memoryNeeded),
    static_cast<gas_t>(copy)
  };
  gas_result_t result {
    GasResult::GAS_MEM_COPY_RESULT,
    gasMemCopy
  };
  return result;
}

gas_result_t Gasometer::outOfGas() {
  gas_result_t result {
    GasResult::OUT_OF_GAS,
    0
  };
  return result;
}

uint256_t Gasometer::memNeeded(uint256_t mem, uint256_t add) {
  return mem + add;
}

mem_gas_t Gasometer::memGasCost(gas_t currentMemSize, gas_t memSize) {

  gas_t requiredMemSizeRounded = Overflow::toWordSize(memSize).first << 5;

  if (requiredMemSizeRounded > currentMemSize) {
    gas_t s = memSize >> 5;
    uint256_t a = uint256_t(Overflow::mul(s, MEMORY_GAS).first);
    uint256_t b = uint256_t((s * s) >> 9);
    gas_t newMemGas = gas_t(a + b);
    mem_gas_t memGas {
      newMemGas - this->currentMemGas,
      newMemGas,
      requiredMemSizeRounded
    };
    return memGas;
  } else {
    mem_gas_t memGas {
      0,
      this->currentMemGas,
      requiredMemSizeRounded
    };
    return memGas;
  }
}