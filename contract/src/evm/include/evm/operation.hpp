#pragma once
#include <memory>
#include <evm/types.h>
#include <evm/instruction.hpp>
#include <evm/memory.hpp>
#include <evm/stack.hpp>
#include <evm/vm_result.h>
#include <evm/opcode.h>
#include <evm/byte_reader.hpp>
#include <evm/context.hpp>
#include <evm/pending_state.hpp>
#include <evm/external.h>

class Operation { 
  typedef instruction_result_t (Operation::*operation_t)(
    gas_t gas,
    instruct_t instruction, 
    std::shared_ptr<Context> context,
    std::shared_ptr<ByteReader> reader,
    std::shared_ptr<PendingState> pendingState,
    std::shared_ptr<External> external,
    std::shared_ptr<Memory> memory, 
    std::shared_ptr<StackMachine> stack
  );
  public: 
    Operation() {
      values[Opcode::STOP] = &Operation::stop;
      values[Opcode::ADD] = &Operation::add;
      values[Opcode::MUL] = &Operation::mul;
      values[Opcode::SUB] = &Operation::sub;
      values[Opcode::DIV] = &Operation::div;
      values[Opcode::SDIV] = &Operation::sdiv;
      values[Opcode::MOD] = &Operation::mod;
      values[Opcode::SMOD] = &Operation::smod;
      values[Opcode::ADDMOD] = &Operation::addmod;
      values[Opcode::MULMOD] = &Operation::mulmod;
      values[Opcode::EXP] = &Operation::exp;
      values[Opcode::SIGNEXTEND] = &Operation::signextend;
      values[Opcode::LT] = &Operation::lt;
      values[Opcode::GT] = &Operation::gt;
      values[Opcode::SLT] = &Operation::slt;
      values[Opcode::SGT] = &Operation::sgt;
      values[Opcode::EQ] = &Operation::eq;
      values[Opcode::ISZERO] = &Operation::iszero;
      values[Opcode::AND] = &Operation::_and;
      values[Opcode::OR] = &Operation::_or;
      values[Opcode::XOR] = &Operation::_xor;
      values[Opcode::NOT] = &Operation::_not;
      values[Opcode::BYTE] = &Operation::_byte;
      values[Opcode::SHL] = &Operation::shl;
      values[Opcode::SHR] = &Operation::shr;
      values[Opcode::SAR] = &Operation::sar;
      values[Opcode::SHA3] = &Operation::sha3;
      values[Opcode::ADDRESS] = &Operation::address;
      values[Opcode::ORIGIN] = &Operation::origin;
      values[Opcode::CALLER] = &Operation::caller;
      values[Opcode::CALLVALUE] = &Operation::callvalue;
      values[Opcode::CALLDATALOAD] = &Operation::calldataload;
      values[Opcode::CALLDATASIZE] = &Operation::calldatasize;
      values[Opcode::CALLDATACOPY] = &Operation::calldatacopy;
      values[Opcode::GASPRICE] = &Operation::gasprice;
      values[Opcode::BLOCKHASH] = &Operation::blockhash;
      values[Opcode::COINBASE] = &Operation::coinbase;
      values[Opcode::TIMESTAMP] = &Operation::timestamp;
      values[Opcode::NUMBER] = &Operation::number;
      values[Opcode::DIFFICULTY] = &Operation::difficulty;
      values[Opcode::GASLIMIT] = &Operation::gaslimit;
      values[Opcode::CHAINID] = &Operation::chainid;
      values[Opcode::POP] = &Operation::pop;
      values[Opcode::MLOAD] = &Operation::mload;
      values[Opcode::MSTORE] = &Operation::mstore;
      values[Opcode::MSTORE8] = &Operation::mstore8;
      values[Opcode::JUMP] = &Operation::jump;
      values[Opcode::JUMPI] = &Operation::jumpi;
      values[Opcode::MSIZE] = &Operation::msize;
      values[Opcode::DUP1] = &Operation::dup;
      values[Opcode::DUP2] = &Operation::dup;
      values[Opcode::DUP3] = &Operation::dup;
      values[Opcode::DUP4] = &Operation::dup;
      values[Opcode::DUP5] = &Operation::dup;
      values[Opcode::DUP6] = &Operation::dup;
      values[Opcode::DUP7] = &Operation::dup;
      values[Opcode::DUP8] = &Operation::dup;
      values[Opcode::DUP9] = &Operation::dup;
      values[Opcode::DUP10] = &Operation::dup;
      values[Opcode::DUP11] = &Operation::dup;
      values[Opcode::DUP12] = &Operation::dup;
      values[Opcode::DUP13] = &Operation::dup;
      values[Opcode::DUP14] = &Operation::dup;
      values[Opcode::DUP15] = &Operation::dup;
      values[Opcode::DUP16] = &Operation::dup;
      values[Opcode::SWAP1] = &Operation::swap;
      values[Opcode::SWAP2] = &Operation::swap;
      values[Opcode::SWAP3] = &Operation::swap;
      values[Opcode::SWAP4] = &Operation::swap;
      values[Opcode::SWAP5] = &Operation::swap;
      values[Opcode::SWAP6] = &Operation::swap;
      values[Opcode::SWAP7] = &Operation::swap;
      values[Opcode::SWAP8] = &Operation::swap;
      values[Opcode::SWAP9] = &Operation::swap;
      values[Opcode::SWAP10] = &Operation::swap;
      values[Opcode::SWAP11] = &Operation::swap;
      values[Opcode::SWAP12] = &Operation::swap;
      values[Opcode::SWAP13] = &Operation::swap;
      values[Opcode::SWAP14] = &Operation::swap;
      values[Opcode::SWAP15] = &Operation::swap;
      values[Opcode::SWAP16] = &Operation::swap;
      values[Opcode::EXTCODESIZE] = &Operation::extcodesize;
      values[Opcode::EXTCODECOPY] = &Operation::extcodecopy;
      values[Opcode::SELFBALANCE] = &Operation::selfbalance;
      values[Opcode::LOG0] = &Operation::log;
      values[Opcode::LOG1] = &Operation::log;
      values[Opcode::LOG2] = &Operation::log;
      values[Opcode::LOG3] = &Operation::log;
      values[Opcode::LOG4] = &Operation::log;
      values[Opcode::SELFDESTRUCT] = &Operation::selfdestruct;
      values[Opcode::CODESIZE] = &Operation::codesize;
      values[Opcode::CODECOPY] = &Operation::codecopy;
      values[Opcode::PC] = &Operation::pc;
      values[Opcode::PUSH1] = &Operation::push;
      values[Opcode::PUSH2] = &Operation::push;
      values[Opcode::PUSH3] = &Operation::push;
      values[Opcode::PUSH4] = &Operation::push;
      values[Opcode::PUSH5] = &Operation::push;
      values[Opcode::PUSH6] = &Operation::push;
      values[Opcode::PUSH7] = &Operation::push;
      values[Opcode::PUSH8] = &Operation::push;
      values[Opcode::PUSH9] = &Operation::push;
      values[Opcode::PUSH10] = &Operation::push;
      values[Opcode::PUSH11] = &Operation::push;
      values[Opcode::PUSH12] = &Operation::push;
      values[Opcode::PUSH13] = &Operation::push;
      values[Opcode::PUSH14] = &Operation::push;
      values[Opcode::PUSH15] = &Operation::push;
      values[Opcode::PUSH16] = &Operation::push;
      values[Opcode::PUSH17] = &Operation::push;
      values[Opcode::PUSH18] = &Operation::push;
      values[Opcode::PUSH19] = &Operation::push;
      values[Opcode::PUSH20] = &Operation::push;
      values[Opcode::PUSH21] = &Operation::push;
      values[Opcode::PUSH22] = &Operation::push;
      values[Opcode::PUSH23] = &Operation::push;
      values[Opcode::PUSH24] = &Operation::push;
      values[Opcode::PUSH25] = &Operation::push;
      values[Opcode::PUSH26] = &Operation::push;
      values[Opcode::PUSH27] = &Operation::push;
      values[Opcode::PUSH28] = &Operation::push;
      values[Opcode::PUSH29] = &Operation::push;
      values[Opcode::PUSH30] = &Operation::push;
      values[Opcode::PUSH31] = &Operation::push;
      values[Opcode::PUSH32] = &Operation::push;
      values[Opcode::JUMPDEST] = &Operation::jumpdest;
      values[Opcode::BALANCE] = &Operation::balance;
      values[Opcode::SLOAD] = &Operation::sload;
      values[Opcode::SSTORE] = &Operation::sstore;
      values[Opcode::GAS] = &Operation::gas;
      values[Opcode::RETURN] = &Operation::_return;
      values[Opcode::REVERT] = &Operation::_revert;
      values[Opcode::EXTCODEHASH] = &Operation::extcodehash;
    };
    
    operation_t values[256];

    instruction_result_t stop(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      return std::make_pair(InstructionResult::STOP_EXEC, 0);
    }

    instruction_result_t add(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t result = stack->peek(0) + stack->peek(1);
      stack->pop(2);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t mul(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t result = stack->peek(0) * stack->peek(1);
      stack->pop(2);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t sub(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t result = stack->peek(0) - stack->peek(1);
      stack->pop(2);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t div(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);

      if (b == 0) {
        stack->pop(2);
        stack->push(uint256_t(0));
      } else {
        uint256_t result = a / b;
        stack->pop(2);
        stack->push(result);
      }

      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t sdiv(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      uint256_t result = b != 0 ? intx::sdivrem(a, b).quot : 0;
      stack->pop(2);
      stack->push(b != 0 ? intx::sdivrem(a, b).quot : 0);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t mod(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      if (b == 0) {
        stack->pop(2);
        stack->push(uint256_t(0));
      } else {
        uint256_t result = a % b;
        stack->pop(2);
        stack->push(result);
      }
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t smod(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      uint256_t result = b != 0 ? intx::sdivrem(a, b).rem : 0;
      stack->pop(2);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t addmod(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      uint256_t c = stack->peek(2);
      uint256_t result = c != 0 ? intx::addmod(a, b, c) : 0;
      stack->pop(3);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t mulmod(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      uint256_t c = stack->peek(2);
      uint256_t result = c != 0 ? intx::mulmod(a, b, c) : 0;
      stack->pop(3);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t exp(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      uint256_t result = intx::exp(a, b);
      stack->pop(2);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t signextend(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t ext = stack->peek(0);
      uint256_t x = stack->peek(1);
      stack->pop(1);
      if (ext < 31) {
        stack->pop(1);
        auto sign_bit = static_cast<int>(ext) * 8 + 7;
        auto sign_mask = uint256_t{1} << sign_bit;
        auto value_mask = sign_mask - 1;
        auto is_neg = (x & sign_mask) != 0;
        stack->push(is_neg ? x | ~value_mask : x & value_mask);
      }
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t lt(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      bool result = stack->peek(0) < stack->peek(1);
      stack->pop(2);
      stack->pushBool(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t gt(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      bool result = stack->peek(0) > stack->peek(1);
      stack->pop(2);
      stack->pushBool(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t slt(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      stack->pop(2);

      bool x_neg = static_cast<bool>(a >> 255);
      bool y_neg = static_cast<bool>(b >> 255);

      stack->pushBool((x_neg ^ y_neg) ? x_neg : a < b);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t sgt(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      stack->pop(2);

      bool x_neg = static_cast<bool>(a >> 255);
      bool y_neg = static_cast<bool>(b >> 255);

      stack->pushBool((x_neg ^ y_neg) ? y_neg : a < b);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t eq(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      bool result = stack->peek(0) == stack->peek(1);
      stack->pop(2);
      stack->pushBool(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t iszero(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      bool result = stack->peek(0) == UINT256_ZERO;
      stack->pop(1);
      stack->pushBool(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t _and(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t result = stack->peek(0) & stack->peek(1);
      stack->pop(2);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t _or(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t result = stack->peek(0) | stack->peek(1);
      stack->pop(2);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t _xor(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t result = stack->peek(0) ^ stack->peek(1);
      stack->pop(2);
      stack->push(result);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t _not(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t item = stack->peek(0);
      stack->pop(1);
      stack->push(~item);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t _byte(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t word = stack->peek(0);
      uint256_t val = stack->peek(1);
      stack->pop(2);
      if (word < UINT256_32) {
        uint64_t word64 = Overflow::uint256Cast(word).first;
        uint256_t result = val >> (8 * (31 - word64)) & UINT256_FF;
        stack->push(result);
      } else {
        stack->push(UINT256_ZERO);
      }
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t shl(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      stack->pop(2);
      stack->push(b <<= a);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t shr(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      stack->pop(2);
      stack->push(b >>= a);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t sar(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t a = stack->peek(0);
      uint256_t b = stack->peek(1);
      
      if ((b & (uint256_t{1} << 255)) == 0) {
        stack->push(b >>= a);
      } else {
        constexpr auto allones = ~uint256_t{};
        if (a >= 256) {
          stack->push(allones);
        } else {
          const auto shift = static_cast<unsigned>(a);
          stack->push((b >> shift) | (allones << (256 - shift)));
        }
      }
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t sha3(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint64_t offset = Overflow::uint256Cast(stack->peek(0)).first;
      uint64_t size = Overflow::uint256Cast(stack->peek(1)).first;
      stack->pop(2);
      stack->push(memory->hashSlice(offset, size));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t address(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->address);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t origin(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->origin);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t caller(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->sender);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t callvalue(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->value);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t calldataload(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t index = stack->peek(0);
      stack->pop(1);
      if (context->data->size() < index) {
        stack->push(UINT256_ZERO);
      } else {
        size_t begin = Overflow::uint256Cast(index).first;
        size_t end = std::min(begin + WORD_SIZE, context->data->size());
        uint8_t data[WORD_SIZE] = {};
        for (size_t i = begin; i < end; i++)
          data[i - begin] = context->data->at(i);
        uint256_t word = intx::be::load<uint256_t>(data);
        stack->push(word);
      }
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t calldatasize(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(uint256_t(context->data->size()));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t calldatacopy(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t destOffset = stack->peek(0);
      uint256_t sourceOffset = stack->peek(1);
      uint256_t sizeItem = stack->peek(2);

      memory->copyData(
        Overflow::uint256Cast(destOffset).first, 
        Overflow::uint256Cast(sourceOffset).first, 
        Overflow::uint256Cast(sizeItem).first, 
        context->data
      );
      stack->pop(3);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t gasprice(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(uint256_t(context->gasPrice));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t blockhash(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->pop(1);
      stack->push(context->blockHash);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t coinbase(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->coinbase);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t timestamp(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->timestamp);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t number(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->blockNumber);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t difficulty(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->difficulty);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t gaslimit(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->gasLimit);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t chainid(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(context->chainId);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t pop(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->pop(1);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t mload(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t offset = stack->peek(0);
      uint256_t word = memory->read(Overflow::uint256Cast(offset).first);
      stack->pop(1);
      stack->push(word);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t mstore(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t offset = stack->peek(0);
      uint256_t word = stack->peek(1);
      memory->write(Overflow::uint256Cast(offset).first, word);
      stack->pop(2);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t mstore8(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t offset = stack->peek(0);
      uint256_t byte = stack->peek(1);
      memory->writeByte(Overflow::uint256Cast(offset).first, byte);
      stack->pop(2);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t jump(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t position = stack->peek(0);
      stack->pop(1);
      return std::make_pair(
        InstructionResult::JUMP_POSITION,
        Overflow::uint256Cast(position).first
      );
    }

    instruction_result_t jumpi(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t condition = stack->peek(1);
      if (condition == UINT256_ONE) {
        uint256_t position = stack->peek(0);
        uint64_t positionValue = Overflow::uint256Cast(position).first;
        stack->pop(2);
        return std::make_pair(
          InstructionResult::JUMP_POSITION, 
          positionValue
        );
      }
      stack->pop(2);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t msize(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      size_t length = memory->length();
      stack->push(uint256_t(length));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t dup(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(stack->peek(Instruction::dupPosition(instruction)));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t swap(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->swapWithTop(Instruction::swapPosition(instruction));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t extcodesize(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t address = stack->peek(0);
      stack->pop(1);
      size_t codeSize = external->code(address).size();
      stack->push(uint256_t(codeSize));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t extcodecopy(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t address = stack->peek(0);
      uint256_t destOffset = stack->peek(1);
      uint256_t sourceOffset = stack->peek(2);
      uint256_t sizeItem = stack->peek(3);

      memory->copyData(
        Overflow::uint256Cast(destOffset).first, 
        Overflow::uint256Cast(sourceOffset).first, 
        Overflow::uint256Cast(sizeItem).first, 
        external->code(address)
      );
      stack->pop(4);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t selfbalance(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(external->balance(context->address));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t log(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint8_t numberOfTopics = Instruction::logTopics(instruction);
      uint64_t offset = Overflow::uint256Cast(stack->peek(0)).first;
      uint64_t size = Overflow::uint256Cast(stack->peek(1)).first;

      std::vector<uint256_t> topics;
      for (int i = 2; i < 2 + numberOfTopics; i++) {
        topics.push_back(stack->peek(i));
      }

      stack->pop(2 + numberOfTopics);

      if (context->isStatic) return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_MUTATE_STATIC);

      pendingState->log(topics, memory->readSlice(offset, size));
      
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t selfdestruct(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t refundAddress = stack->peek(0);
      stack->pop(1);

      if (context->isStatic) return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_MUTATE_STATIC);

      emplace_t result = external->selfdestruct(context->codeAddress, refundAddress);

      switch (result.first) {
        case EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND:
        case EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS:
        case EmplaceResult::EMPLACE_CODE_ALREADY_EXISTS:
          return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_INVALID_CODE_ADDRESS);
        case EmplaceResult::EMPLACE_SUCCESS:
          return std::make_pair(InstructionResult::STOP_EXEC, 0);
      }
    }

    instruction_result_t codesize(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(uint256_t(context->code->size()));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t codecopy(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t destOffset = stack->peek(0);
      uint256_t sourceOffset = stack->peek(1);
      uint256_t sizeItem = stack->peek(2);

      memory->copyData(
        Overflow::uint256Cast(destOffset).first, 
        Overflow::uint256Cast(sourceOffset).first, 
        Overflow::uint256Cast(sizeItem).first, 
        context->code
      );
      stack->pop(3);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t pc(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(uint256_t(reader->pc()));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t push(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(reader->read(Instruction::pushBytes(instruction), context->code));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t jumpdest(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t balance(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t balance = external->balance(stack->peek(0));
      stack->pop(1);
      stack->push(balance);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t sload(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t key = stack->peek(0);
      uint256_t word = pendingState->getState(key, context->codeAddress, external);

      stack->pop(1);
      stack->push(word);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t sstore(
      gas_t gas,
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t key = stack->peek(0);
      uint256_t value = stack->peek(1);  
      stack->pop(2);

      if (context->isStatic) return std::make_pair(InstructionResult::INSTRUCTION_TRAP, TrapKind::TRAP_MUTATE_STATIC);

      pendingState->putState(key, value, context->codeAddress);
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t gas(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      stack->push(uint256_t(gas));
      return std::make_pair(InstructionResult::OK, 0);
    }

    instruction_result_t _return(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t initOff = stack->peek(0);
      uint256_t initSize = stack->peek(1);
      stack->pop(2);

      StopExecutionResult result {
        gas,
        Overflow::uint256Cast(initOff).first,
        Overflow::uint256Cast(initSize).first,
        true
      };
      
      return std::make_pair(
        InstructionResult::STOP_EXEC_RETURN,
        result
      ); 
    }

    instruction_result_t _revert(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {
      uint256_t initOff = stack->peek(0);
      uint256_t initSize = stack->peek(1);
      stack->pop(2);

      StopExecutionResult result {
        gas,
        Overflow::uint256Cast(initOff).first,
        Overflow::uint256Cast(initSize).first,
        false
      };
      
      return std::make_pair(
        InstructionResult::STOP_EXEC_RETURN,
        result
      );
    }

    instruction_result_t extcodehash(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<PendingState> pendingState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    ) {  
      uint256_t address = stack->peek(0);
      stack->pop(1);
      bytes_t codeBytes = external->code(address);
      stack->push(Hash::keccak256Word(codeBytes));
      return std::make_pair(InstructionResult::OK, 0);
    }
};