#pragma once
#include <memory>
#include <evm/gas_types.h>
#include <evm/opcode.h>
#include <evm/types.h>
#include <evm/instruction.h>
#include <evm/external.h>
#include <evm/stack.h>

class GasCalculation {
  typedef gas_result_t (GasCalculation::*calculate_t)(
    instruct_t instruction,
    gas_t defaultGas,
    gas_t currentGas,
    gas_t currentMemorySize,
    std::shared_ptr<StackMachine> stack,
    std::shared_ptr<External> external
  );
  public:
    GasCalculation() { 
      values[Opcode::JUMPDEST] = &GasCalculation::jumpdest;
      values[Opcode::SSTORE] = &GasCalculation::sstore;
      values[Opcode::SLOAD] = &GasCalculation::sload;
      values[Opcode::BALANCE] = &GasCalculation::balance;
      values[Opcode::EXTCODESIZE] = &GasCalculation::extcodesize;
      values[Opcode::EXTCODEHASH] = &GasCalculation::extcodehash;
      values[Opcode::SELFDESTRUCT] = &GasCalculation::selfdestruct;
      values[Opcode::MSTORE] = &GasCalculation::mstore_mload;
      values[Opcode::MLOAD] = &GasCalculation::mstore_mload;
      values[Opcode::MSTORE8] = &GasCalculation::mstore8;
      values[Opcode::REVERT] = &GasCalculation::revert_return;
      values[Opcode::RETURN] = &GasCalculation::revert_return;
      values[Opcode::SHA3] = &GasCalculation::sha3;
      values[Opcode::CALLDATACOPY] = &GasCalculation::calldatacopy_codecopy_returndatacopy;
      values[Opcode::CODECOPY] = &GasCalculation::calldatacopy_codecopy_returndatacopy;
      values[Opcode::RETURNDATACOPY] = &GasCalculation::calldatacopy_codecopy_returndatacopy;
      values[Opcode::EXTCODECOPY] = &GasCalculation::extcodecopy;
      values[Opcode::LOG0] = &GasCalculation::log;
      values[Opcode::LOG1] = &GasCalculation::log;
      values[Opcode::LOG2] = &GasCalculation::log;
      values[Opcode::LOG3] = &GasCalculation::log;
      values[Opcode::LOG4] = &GasCalculation::log;
      values[Opcode::CALL] = &GasCalculation::call_callcode;
      values[Opcode::CALLCODE] = &GasCalculation::call_callcode;
      values[Opcode::DELEGATECALL] = &GasCalculation::deletatecall_staticcall;
      values[Opcode::STATICCALL] = &GasCalculation::deletatecall_staticcall;
      values[Opcode::CREATE] = &GasCalculation::create;
      values[Opcode::CREATE2] = &GasCalculation::create2;
      values[Opcode::EXP] = &GasCalculation::exp;
      values[Opcode::BLOCKHASH] = &GasCalculation::blockhash;
    };
    calculate_t values[256];
  private:
    gas_result_t gas(gas_t value);
    gas_result_t gasMem(gas_t defaultGas, gas_t memoryNeeded);
    gas_result_t gasMemProvided(gas_t defaultGas, gas_t memoryNeeded, gas_t requested);
    gas_result_t gasMemCopy(gas_t defaultGas, gas_t memoryNeeded, gas_t copy);
    gas_result_t outOfGas();
    gas_t memNeeded(gas_t mem, gas_t add);
    gas_result_t jumpdest(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t sstore(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t sload(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t balance(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t extcodesize(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t extcodehash(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t selfdestruct(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t mstore_mload(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t mstore8(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t revert_return(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t sha3(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t calldatacopy_codecopy_returndatacopy(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t extcodecopy(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t log(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t call_callcode(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t deletatecall_staticcall(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t create(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t create2(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t exp(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    gas_result_t blockhash(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
};