#pragma once
#include <memory>
#include <evm/byte_reader.hpp>
#include <evm/stack.hpp>
#include <evm/types.h>
#include <evm/pending_state.hpp>
#include <evm/vm_result.h>
#include <evm/memory.hpp>
#include <evm/external.h>
#include <evm/gasometer.hpp>
#include <evm/context.hpp>
#include <evm/operation.hpp>

class VM {
  public:
    VM(
      std::shared_ptr<StackMachine> stackArg,
      std::shared_ptr<Gasometer> gasometerArg
    ) {
      stack = stackArg;
      gasometer = gasometerArg;
      returnData = std::make_shared<bytes_t>();
    };
    exec_result_t execute(
      uint16_t stackDepth,
      Operation& operation,
      std::shared_ptr<Context> context,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external
    );
    exec_result_t step(
      uint16_t stackDepth,
      Operation& operation,
      jump_set_t& jumps, 
      std::shared_ptr<Context> context,
      std::shared_ptr<GasCalculation> gasCalculation,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external
    );
    instruction_result_t executeCreateInstruction(
      uint16_t stackDepth,
      Operation& operation,
      uint8_t opcode,
      gas_t providedGas,
      std::shared_ptr<Context> context,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external
    );
    instruction_result_t executeCallInstruction(
      uint16_t stackDepth,
      Operation& operation,
      uint8_t opcode,
      gas_t providedGas,
      std::shared_ptr<Context> context,
      std::shared_ptr<Memory> memory,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external
    );
    std::shared_ptr<StackMachine> stack;
  private:
    std::shared_ptr<Gasometer> gasometer;
    std::shared_ptr<bytes_t> returnData;
};