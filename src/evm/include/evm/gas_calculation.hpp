#pragma once
#include <memory>
#include <evm/gas_types.h>
#include <evm/opcode.h>
#include <evm/types.h>
#include <evm/instruction.hpp>
#include <evm/external.h>
#include <evm/stack.hpp>
#include <evm/context.h>
#include <evm/overflow.hpp>

class GasCalculation {
  typedef gas_result_t (GasCalculation::*calculate_t)(
    instruct_t instruction,
    gas_t defaultGas,
    gas_t currentGas,
    gas_t currentMemorySize,
    std::shared_ptr<Context> context,
    std::shared_ptr<StackMachine> stack,
    std::shared_ptr<External> external
  );
  public:
    calculate_t values[256];
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
  private:
    gas_result_t jumpdest(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      return gas(1);
    }

    gas_result_t sstore(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      if (currentGas <= CALL_STIPEND) {
        return outOfGas();
      }

      uint256_t address = stack->peek(0);
      uint256_t newVal = stack->peek(1);
      uint256_t word = external->storageAt(address, context->codeAddress);

      gas_t storeGasCost;
      if (word == 0 && newVal != 0) {
        storeGasCost = SSTORE_SET_GAS;
      } else {
        storeGasCost = SSTORE_RESET_GAS;
      }

      return gas(storeGasCost);
    }

    gas_result_t sload(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      return gas(SLOAD_GAS);
    }

    gas_result_t balance(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      return gas(BALANCE_GAS);
    }

    gas_result_t extcodesize(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      return gas(EXTCODESIZE_GAS);
    }

    gas_result_t extcodehash(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      return gas(EXTCODEHASH_GAS);
    }

    gas_result_t selfdestruct(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      return gas(0);
    }

    gas_result_t mstore_mload(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t instructionGas = Overflow::uint256Cast(stack->peek(0)).first;
      return gasMem(defaultGas, memNeeded(instructionGas, 32));
    }

    gas_result_t mstore8(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t instructionGas = Overflow::uint256Cast(stack->peek(0)).first;
      return gasMem(defaultGas, memNeeded(instructionGas, 1));
    }

    gas_result_t revert_return(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t instructionGas = Overflow::uint256Cast(stack->peek(0)).first;
      gas_t memoryNeeded = Overflow::uint256Cast(stack->peek(1)).first;
      return gasMem(defaultGas, memNeeded(instructionGas, memoryNeeded));
    }

    gas_result_t sha3(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t instructionGas = Overflow::uint256Cast(stack->peek(0)).first;
      gas_t memoryNeeded = Overflow::uint256Cast(stack->peek(1)).first;
      gas_t words = Overflow::toWordSize(stack->peek(1)).first;
      gas_t gas = SHA3_GAS + SHA3_WORD_GAS * words;
      return gasMem(gas, memNeeded(instructionGas, memoryNeeded));
    }

    gas_result_t calldatacopy_codecopy_returndatacopy(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t instructionGas = Overflow::uint256Cast(stack->peek(0)).first;
      gas_t copySize = Overflow::uint256Cast(stack->peek(2)).first;
      return gasMemCopy(
        defaultGas, 
        memNeeded(instructionGas, copySize), 
        copySize
      );
    }

    gas_result_t extcodecopy(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t instructionGas = Overflow::uint256Cast(stack->peek(1)).first;
      gas_t copySize = Overflow::uint256Cast(stack->peek(3)).first;
      return gasMemCopy(
        EXTCODECOPY_BASE_GAS, 
        memNeeded(instructionGas, copySize), 
        copySize
      );
    }

    gas_result_t log(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t instructionGas = Overflow::uint256Cast(stack->peek(0)).first;
      gas_t memoryNeeded = Overflow::uint256Cast(stack->peek(1)).first;
      gas_t noOfTopics = Overflow::uint256Cast(Instruction::logTopics(instruction)).first;
      gas_t logGas = LOG_GAS + LOG_TOPIC_GAS * noOfTopics;
      gas_t dataGas = memoryNeeded * LOG_DATA_GAS;
      gas_t gas = dataGas + logGas;
      return gasMem(gas, memNeeded(instructionGas, memoryNeeded));
    }

    gas_result_t call_callcode(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t gas = CALL_GAS;
      gas_t value = Overflow::uint256Cast(stack->peek(2)).first;
      gas_t argOffset = Overflow::uint256Cast(stack->peek(3)).first;
      gas_t argLength = Overflow::uint256Cast(stack->peek(4)).first;
      gas_t retOffset = Overflow::uint256Cast(stack->peek(5)).first;
      gas_t retLength = Overflow::uint256Cast(stack->peek(6)).first;

      gas_t mem = std::max(
        memNeeded(argOffset, argLength),
        memNeeded(retOffset, retLength)
      );

      bool isValueTransfer = (value != 0); 
      if (isValueTransfer) {
        gas = gas + CALL_VALUE_TRANSFER_GAS;
      }

      gas_t instructionGas = Overflow::uint256Cast(stack->peek(0)).first;

      return gasMemProvided(gas, mem, instructionGas);
    }

    gas_result_t deletatecall_staticcall(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t argOffset = Overflow::uint256Cast(stack->peek(2)).first;
      gas_t argLength = Overflow::uint256Cast(stack->peek(3)).first;
      gas_t retOffset = Overflow::uint256Cast(stack->peek(4)).first;
      gas_t retLength = Overflow::uint256Cast(stack->peek(5)).first;

      gas_t mem = std::max(
        memNeeded(argOffset, argLength),
        memNeeded(retOffset, retLength)
      );
      gas_t requested = Overflow::uint256Cast(stack->peek(0)).first;
      return gasMemProvided(CALL_GAS, mem, requested);
    }

    gas_result_t create(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t start = Overflow::uint256Cast(stack->peek(1)).first;
      gas_t len = Overflow::uint256Cast(stack->peek(2)).first;
      gas_t gas = CREATE_GAS;
      gas_t mem = memNeeded(start, len);
      return gasMemProvided(gas, mem, 0);
    }

    gas_result_t create2(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t start = Overflow::uint256Cast(stack->peek(1)).first;
      gas_t len = Overflow::uint256Cast(stack->peek(2)).first;

      gas_t word = Overflow::toWordSize(len).first;
      gas_t wordGas = SHA3_WORD_GAS * word;
      gas_t gas = Overflow::add(CREATE_GAS, wordGas).first;
      gas_t mem = memNeeded(start, len);

      return gasMemProvided(gas, mem, 0);
    }

    gas_result_t exp(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      gas_t exponent = Overflow::uint256Cast(stack->peek(1)).first;
      gas_t bytes = Overflow::uint256Cast((intx::count_significant_words<uint8_t>(exponent) + 7) / 8).first;
      gas_t cost = EXP_GAS + EXP_BYTE_GAS * bytes;
      return gas(cost);
    }

    gas_result_t blockhash(
      instruct_t instruction,
      gas_t defaultGas,
      gas_t currentGas,
      gas_t currentMemorySize,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    ) {
      return gas(BLOCK_HASH_GAS);
    }

    gas_result_t gas(gas_t value) {
      return std::make_pair(GasResult::GAS_RESULT, value);
    }

    gas_result_t gasMem(gas_t defaultGas, gas_t memoryNeeded) {
      GasMem gasMem {
        defaultGas,
        memoryNeeded
      };
      return std::make_pair(GasResult::GAS_MEM_RESULT, gasMem);
    }

    gas_result_t gasMemProvided(gas_t defaultGas, gas_t memoryNeeded, gas_t requested) {
      GasMemProvided gasMemProvided {
        defaultGas,
        memoryNeeded,
        requested
      };
      return std::make_pair(GasResult::GAS_MEM_PROVIDE_RESULT, gasMemProvided);
    }

    gas_result_t gasMemCopy(gas_t defaultGas, gas_t memoryNeeded, gas_t copy) {
      GasMemCopy gasMemCopy {
        defaultGas,
        memoryNeeded,
        copy
      };
      return std::make_pair(GasResult::GAS_MEM_COPY_RESULT, gasMemCopy);
    }

    gas_result_t outOfGas() {
      return std::make_pair(GasResult::GAS_OUT_OF_GAS, 0);
    }

    gas_t memNeeded(gas_t mem, gas_t add) {
      if (add == 0) return 0;
      return Overflow::add(mem, add).first;
    }
};