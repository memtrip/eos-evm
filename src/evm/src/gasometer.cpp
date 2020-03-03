#include <evm/gasometer.h>

gas_result_t Gasometer::requirements(
  External& external,
  instruct_t instruction,
  StackMachine& stack,
  size_t currentMemorySize
) {
  uint8_t tier = Instruction::tier(instruction);

  switch (Instruction::opcode(instruction)) {
    case Opcode::JUMPDEST:
      return gas(uint256_t(1));
    case Opcode::SSTORE:
      return gas(uint256_t(1));
    case Opcode::SLOAD:
      return gas(uint256_t(1));
    case Opcode::BALANCE:
      return gas(uint256_t(1));;
    case Opcode::EXTCODESIZE:
      return gas(uint256_t(1));
    case Opcode::EXTCODEHASH:
      return gas(uint256_t(1));
    case Opcode::SELFDESTRUCT:
      return gas(uint256_t(1));
    case Opcode::MSTORE:
    case Opcode::MLOAD:
      return gas(uint256_t(1));
    case Opcode::MSTORE8:
      return gas(uint256_t(1));
    case Opcode::RETURN:
    case Opcode::REVERT:
      return gas(uint256_t(1));
    case Opcode::SHA3:
      return gas(uint256_t(1));
    case Opcode::CALLDATACOPY:
    case Opcode::CODECOPY:
    case Opcode::RETURNDATACOPY:
      return gas(uint256_t(1));
    case Opcode::EXTCODECOPY:
      return gas(uint256_t(1));
    case Opcode::LOG0:
    case Opcode::LOG1:
    case Opcode::LOG2:
    case Opcode::LOG3:
    case Opcode::LOG4:
      return gas(uint256_t(1));
    case Opcode::CALL:
    case Opcode::CALLCODE:
      return gas(uint256_t(1));
    case Opcode::DELEGATECALL:
    case Opcode::STATICCALL:
      return gas(uint256_t(1));
    case Opcode::CREATE:
      return gas(uint256_t(1));
    case Opcode::CREATE2:
      return gas(uint256_t(1));
    case Opcode::EXP:
      return gas(uint256_t(1));
    case Opcode::BLOCKHASH:
      return gas(uint256_t(1));
  }

  // TODO: should be default gas
  return gas(uint256_t(0));
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