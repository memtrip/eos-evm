#include <evm/gasometer.h>
#include <evm/overflow.h>
#include <evm/big_int.h>

instruction_requirements_t Gasometer::requirements(
  External& external,
  instruct_t instruction,
  std::vector<uint256_t>& args,
  gas_t currentMemorySize
) {
  gas_result_t result = calculate(
    external,
    instruction,
    args,
    currentMemorySize
  );

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

gas_result_t Gasometer::calculate(
  External& external,
  instruct_t instruction,
  std::vector<uint256_t>& args,
  gas_t currentMemorySize
) {
  uint8_t tier = Instruction::tier(instruction);
  uint8_t tierGas = TIER_STEP_GAS[tier];
  gas_t defaultGas = tierGas;

  switch (Instruction::opcode(instruction)) {
    case Opcode::JUMPDEST:
      return gas(1);
    case Opcode::SSTORE:
      {
        if (currentGas <= CALL_STIPEND) {
          return outOfGas();
        }

        uint256_t address = args.at(0);
        uint256_t newVal = args.at(1);
        bytes_t addressBytes = external.storageAt(address);
        uint256_t current = BigInt::fromBigEndianBytes(addressBytes);

        gas_t storeGasCost;
        if (current == 0 && newVal != 0) {
          storeGasCost = SSTORE_SET_GAS;
        } else {
          storeGasCost = SSTORE_RESET_GAS;
        }

        return gas(storeGasCost);
      }
    case Opcode::SLOAD:
      return gas(SLOAD_GAS);
    case Opcode::BALANCE:
      return gas(BALANCE_GAS);;
    case Opcode::EXTCODESIZE:
      return gas(EXTCODESIZE_GAS);
    case Opcode::EXTCODEHASH:
      return gas(EXTCODEHASH_GAS);
    case Opcode::SELFDESTRUCT:
      // No empty, new account gas calculation is not included
      return gas(0);
    case Opcode::MSTORE:
    case Opcode::MLOAD:
      {
        gas_t instructionGas = Overflow::uint256Cast(args.at(0)).first;
        return gasMem(defaultGas, memNeeded(instructionGas, 32));
      }
    case Opcode::MSTORE8:
      {
        gas_t instructionGas = Overflow::uint256Cast(args.at(0)).first;
        return gasMem(defaultGas, memNeeded(instructionGas, 1));
      }
    case Opcode::RETURN:
    case Opcode::REVERT:
      {
        gas_t instructionGas = Overflow::uint256Cast(args.at(0)).first;
        gas_t memoryNeeded = Overflow::uint256Cast(args.at(1)).first;
        return gasMem(defaultGas, memNeeded(instructionGas, memoryNeeded));
      }
    case Opcode::SHA3:
      {
        gas_t instructionGas = Overflow::uint256Cast(args.at(0)).first;
        gas_t memoryNeeded = Overflow::uint256Cast(args.at(1)).first;
        gas_t words = Overflow::toWordSize(args.at(1)).first;
        gas_t gas = SHA3_GAS + SHA3_WORD_GAS * words;
        return gasMem(gas, memNeeded(instructionGas, memoryNeeded));
      }
    case Opcode::CALLDATACOPY:
    case Opcode::CODECOPY:
    case Opcode::RETURNDATACOPY:
      {
        gas_t instructionGas = Overflow::uint256Cast(args.at(0)).first;
        gas_t copySize = Overflow::uint256Cast(args.at(2)).first;
        return gasMemCopy(
          defaultGas, 
          memNeeded(instructionGas, copySize), 
          copySize
        );
      }
    case Opcode::EXTCODECOPY:
      {
        gas_t instructionGas = Overflow::uint256Cast(args.at(1)).first;
        gas_t copySize = Overflow::uint256Cast(args.at(3)).first;
        return gasMemCopy(
          EXTCODECOPY_BASE_GAS, 
          memNeeded(instructionGas, copySize), 
          copySize
        );
      }
    case Opcode::LOG0:
    case Opcode::LOG1:
    case Opcode::LOG2:
    case Opcode::LOG3:
    case Opcode::LOG4:
      {
        gas_t instructionGas = Overflow::uint256Cast(args.at(0)).first;
        gas_t memoryNeeded = Overflow::uint256Cast(args.at(1)).first;
        gas_t noOfTopics = Overflow::uint256Cast(Instruction::logTopics(instruction)).first;
        gas_t logGas = LOG_GAS + LOG_TOPIC_GAS * noOfTopics;
        gas_t dataGas = memoryNeeded * LOG_DATA_GAS;
        gas_t gas = dataGas + logGas;
        return gasMem(gas, memNeeded(instructionGas, memoryNeeded));
      }
    case Opcode::CALL:
    case Opcode::CALLCODE:
      {
        gas_t gas = CALL_GAS;
        gas_t value = Overflow::uint256Cast(args.at(2)).first;
        gas_t argOffset = Overflow::uint256Cast(args.at(3)).first;
        gas_t argLength = Overflow::uint256Cast(args.at(4)).first;
        gas_t retOffset = Overflow::uint256Cast(args.at(5)).first;
        gas_t retLength = Overflow::uint256Cast(args.at(6)).first;

        gas_t mem = std::max(
          memNeeded(argOffset, argLength),
          memNeeded(retOffset, retLength)
        );

        bool isValueTransfer = (value != 0); 
        if (isValueTransfer) {
          gas = gas + CALL_VALUE_TRANSFER_GAS;
        }

        gas_t instructionGas = Overflow::uint256Cast(args.at(0)).first;

        return gasMemProvided(gas, mem, instructionGas);
      }
    case Opcode::DELEGATECALL:
    case Opcode::STATICCALL:
      {
        gas_t argOffset = Overflow::uint256Cast(args.at(2)).first;
        gas_t argLength = Overflow::uint256Cast(args.at(3)).first;
        gas_t retOffset = Overflow::uint256Cast(args.at(4)).first;
        gas_t retLength = Overflow::uint256Cast(args.at(5)).first;

        gas_t mem = std::max(
          memNeeded(argOffset, argLength),
          memNeeded(retOffset, retLength)
        );
        gas_t requested = Overflow::uint256Cast(args.at(0)).first;
        return gasMemProvided(CALL_GAS, mem, requested);
      }
    case Opcode::CREATE:
      {
        gas_t start = Overflow::uint256Cast(args.at(1)).first;
        gas_t len = Overflow::uint256Cast(args.at(2)).first;
        gas_t gas = CREATE_GAS;
        gas_t mem = memNeeded(start, len);
        return gasMemProvided(gas, mem, 0);
      }
    case Opcode::CREATE2:
      {
        gas_t start = Overflow::uint256Cast(args.at(1)).first;
        gas_t len = Overflow::uint256Cast(args.at(2)).first;

        gas_t word = Overflow::toWordSize(len).first;
        gas_t wordGas = SHA3_WORD_GAS * word;
        gas_t gas = Overflow::add(CREATE_GAS, wordGas).first;
        gas_t mem = memNeeded(start, len);

        return gasMemProvided(gas, mem, 0);
      }
    case Opcode::EXP:
      {
        gas_t exponent = Overflow::uint256Cast(args.at(1)).first;
        gas_t bytes = Overflow::uint256Cast((intx::count_significant_words<uint8_t>(exponent) + 7) / 8).first;
        gas_t cost = EXP_GAS + EXP_BYTE_GAS * bytes;
        return gas(cost);
      }
    case Opcode::BLOCKHASH:
      return gas(BLOCK_HASH_GAS);
  }

  return gas(defaultGas);
}

gas_result_t Gasometer::gas(gas_t value) {
  return std::make_pair(GasResult::GAS_RESULT, value);
}

gas_result_t Gasometer::gasMem(gas_t defaultGas, gas_t memoryNeeded) {
  GasMem gasMem {
    defaultGas,
    memoryNeeded
  };
  return std::make_pair(GasResult::GAS_MEM_RESULT, gasMem);
}

gas_result_t Gasometer::gasMemProvided(gas_t defaultGas, gas_t memoryNeeded, gas_t requested) {
  GasMemProvided gasMemProvided {
    defaultGas,
    memoryNeeded,
    requested
  };
  return std::make_pair(GasResult::GAS_MEM_PROVIDE_RESULT, gasMemProvided);
}

gas_result_t Gasometer::gasMemCopy(gas_t defaultGas, gas_t memoryNeeded, gas_t copy) {
  GasMemCopy gasMemCopy {
    defaultGas,
    memoryNeeded,
    copy
  };
  return std::make_pair(GasResult::GAS_MEM_COPY_RESULT, gasMemCopy);
}

gas_result_t Gasometer::outOfGas() {
  return std::make_pair(GasResult::GAS_OUT_OF_GAS, 0);
}

gas_t Gasometer::memNeeded(gas_t mem, gas_t add) {
  return Overflow::add(mem, add).first;
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