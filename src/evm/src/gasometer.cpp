#include <evm/gasometer.h>

gas_result_t Gasometer::requirements(
  External& external,
  instruct_t instruction,
  StackMachine& stack,
  size_t currentMemorySize
) {
  uint8_t tier = Instruction::tier(instruction);
  uint256_t defaultGas = TIER_STEP_GAS[tier];

  switch (Instruction::opcode(instruction)) {
    case Opcode::JUMPDEST:
      return gas(uint256_t(1));
    case Opcode::SSTORE:
      // TODO
      return gas(uint256_t(1));
    case Opcode::SLOAD:
      return gas(uint256_t(SLOAD_GAS));
    case Opcode::BALANCE:
      return gas(uint256_t(BALANCE_GAS));;
    case Opcode::EXTCODESIZE:
      return gas(uint256_t(EXTCODESIZE_GAS));
    case Opcode::EXTCODEHASH:
      return gas(uint256_t(EXTCODEHASH_GAS));
    case Opcode::SELFDESTRUCT:
      // TODO
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
      // TODO
      return gas(uint256_t(1));
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
        uint256_t logGas = LOG_GAS + LOG_TOPIC_GAS + noOfTopics;
        uint256_t dataGas = stack.peek(1) * uint256_t(LOG_DATA_GAS);
        uint256_t gas = dataGas + logGas;
        return gasMem(gas, memNeeded(stack.peek(0), stack.peek(1)));
      }
    case Opcode::CALL:
    case Opcode::CALLCODE:
      // TODO
      return gas(uint256_t(1));
    case Opcode::DELEGATECALL:
    case Opcode::STATICCALL:
      {
        // TODO
        return gas(uint256_t(1));
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
      // TODO
      return gas(uint256_t(1));
    case Opcode::EXP:
      // TODO
      return gas(uint256_t(1));
    case Opcode::BLOCKHASH:
      return gas(uint256_t(BLOCK_HASH_GAS));
  }

  // TODO: should be default gas
  return gas(defaultGas);
}

gas_result_t Gasometer::gas(uint256_t value) {

  gas_result_t result {
    GasResult::GAS_RESULT,
    value
  };
  return result;
}

gas_result_t Gasometer::gasMem(uint256_t defaultGas, uint256_t memoryNeeded) {
  GasMem gasMem {
    defaultGas,
    memoryNeeded
  };
  gas_result_t result {
    GasResult::GAS_MEM_RESULT,
    gasMem
  };
  return result;
}

gas_result_t Gasometer::gasMemProvided(uint256_t defaultGas, uint256_t memoryNeeded, uint256_t requested) {
  GasMemProvided gasMemProvided {
    defaultGas,
    memoryNeeded,
    requested
  };
  gas_result_t result {
    GasResult::GAS_MEM_PROVIDE_RESULT,
    gasMemProvided
  };
  return result;
}

gas_result_t Gasometer::gasMemCopy(uint256_t defaultGas, uint256_t memoryNeeded, uint256_t copy) {
  GasMemCopy gasMemCopy {
    defaultGas,
    memoryNeeded,
    copy
  };
  gas_result_t result {
    GasResult::GAS_MEM_COPY_RESULT,
    gasMemCopy
  };
  return result;
}

uint256_t Gasometer::memNeeded(uint256_t mem, uint256_t add) {
  return mem + add;
}