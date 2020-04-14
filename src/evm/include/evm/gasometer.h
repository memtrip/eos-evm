#pragma once
#include <memory>
#include <evm/gas_types.h>
#include <evm/opcode.h>
#include <evm/instruction.hpp>
#include <evm/external.h>
#include <evm/stack.hpp>
#include <evm/gas_calculation.hpp>
#include <evm/context.h>

class Gasometer {
  public:
    Gasometer(gas_t currentGasArg) {
      currentGas = currentGasArg;
      currentMemGas = 0;
    };
    gas_t currentGas;
    gas_t currentMemGas;
    instruction_requirements_t requirements(
      uint8_t opcode,
      instruct_t instruction,
      gas_t currentMemorySize,
      std::shared_ptr<GasCalculation> gasCalculation,
      std::shared_ptr<Context> context,
      std::shared_ptr<StackMachine> stack,
      std::shared_ptr<External> external
    );
    mem_gas_t memGasCost(gas_t currentMemSize, gas_t memSize) const;
};