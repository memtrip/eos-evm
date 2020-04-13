#include <evm/operation.h>
#include <evm/big_int.h>
#include <evm/hash.h>
#include <evm/overflow.h>

instruction_result_t Operation::stop(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  return std::make_pair(InstructionResult::STOP_EXEC, 0);
}

instruction_result_t Operation::add(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t result = stack->peek(0) + stack->peek(1);
  stack->pop(2);
  stack->push(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::mul(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t result = stack->peek(0) * stack->peek(1);
  stack->pop(2);
  stack->push(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::sub(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t result = stack->peek(0) - stack->peek(1);
  stack->pop(2);
  stack->push(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::div(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::sdiv(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t a = stack->peek(0);
  uint256_t b = stack->peek(1);
  uint256_t result = b != 0 ? intx::sdivrem(a, b).quot : 0;
  stack->pop(2);
  stack->push(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::mod(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::smod(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::addmod(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::mulmod(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::exp(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::signextend(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::lt(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  bool result = stack->peek(0) < stack->peek(1);
  stack->pop(2);
  stack->pushBool(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::gt(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  bool result = stack->peek(0) > stack->peek(1);
  stack->pop(2);
  stack->pushBool(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::slt(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::sgt(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::eq(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  bool result = stack->peek(0) == stack->peek(1);
  stack->pop(2);
  stack->pushBool(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::iszero(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  bool result = stack->peek(0) == UINT256_ZERO;
  stack->pop(1);
  stack->pushBool(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::_and(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t result = stack->peek(0) & stack->peek(1);
  stack->pop(2);
  stack->push(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::_or(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t result = stack->peek(0) | stack->peek(1);
  stack->pop(2);
  stack->push(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::_xor(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t result = stack->peek(0) ^ stack->peek(1);
  stack->pop(2);
  stack->push(result);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::_not(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t item = stack->peek(0);
  stack->pop(1);
  stack->push(~item);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::_byte(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::shl(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::shr(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::sar(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::sha3(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t offset = stack->peek(0);
  uint256_t size = stack->peek(1);
  std::shared_ptr<bytes_t> bytes = memory->readSlice(
    Overflow::uint256Cast(offset).first, 
    Overflow::uint256Cast(size).first
  );
  stack->pop(2);
  bytes_t hashBytes = Hash::keccak256(bytes);
  stack->push(BigInt::fromBigEndianBytes(hashBytes));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::address(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->address);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::origin(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->origin);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::caller(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->sender);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::callvalue(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->value);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::calldataload(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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
    uint256_t value = BigInt::load32(begin, context->data);
    stack->push(value);
  }
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::calldatasize(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(uint256_t(context->data->size()));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::calldatacopy(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::gasprice(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(uint256_t(context->gasPrice));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::blockhash(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->pop(1);
  stack->push(context->blockHash);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::coinbase(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->coinbase);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::timestamp(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->timestamp);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::number(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->blockNumber);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::difficulty(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->difficulty);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::gaslimit(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->gasLimit);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::chainid(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(context->chainId);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::pop(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->pop(1);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::mload(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::mstore(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::mstore8(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::jump(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::jumpi(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::msize(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  size_t length = memory->length();
  stack->push(uint256_t(length));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::dup(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(stack->peek(Instruction::dupPosition(instruction)));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::swap(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->swapWithTop(Instruction::swapPosition(instruction));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::extcodesize(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t address = stack->peek(0);
  stack->pop(1);
  size_t codeSize = external->code(address)->size();
  stack->push(uint256_t(codeSize));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::extcodecopy(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::selfbalance(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(uint256_t(external->balance(context->address)));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::log(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint8_t numberOfTopics = Instruction::logTopics(instruction);
  uint256_t offset = stack->peek(0);
  uint256_t size = stack->peek(1);

  std::vector<uint256_t> topics;
  for (int i = 2; i < 2 + numberOfTopics; i++) {
    topics.push_back(stack->peek(i));
  }

  std::shared_ptr<bytes_t> bytes = memory->readSlice(
    Overflow::uint256Cast(offset).first, 
    Overflow::uint256Cast(size).first
  );

  stack->pop(2 + numberOfTopics);

  external->log(topics, bytes);
  
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::selfdestruct(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t address = stack->peek(0);
  stack->pop(1);
  external->suicide(address);
  return std::make_pair(InstructionResult::STOP_EXEC, 0);
}

instruction_result_t Operation::codesize(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(uint256_t(context->code->size()));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::codecopy(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::pc(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(uint256_t(reader->pc()));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::push(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(reader->read(Instruction::pushBytes(instruction), context->code));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::jumpdest(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::balance(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t address = stack->peek(0);
  stack->push(uint256_t(external->balance(address)));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::sload(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t key = stack->peek(0);
  uint256_t word = accountState->get(key, context->codeAddress);

  stack->pop(1);
  stack->push(word);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::sstore(
  gas_t gas,
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  uint256_t key = stack->peek(0);
  uint256_t value = stack->peek(1);  
  stack->pop(2);
  accountState->put(key, value, context->codeAddress);
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::gas(
  gas_t gas,      
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {
  stack->push(uint256_t(gas));
  return std::make_pair(InstructionResult::OK, 0);
}

instruction_result_t Operation::_return(
  gas_t gas,      
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::_revert(
  gas_t gas,      
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
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

instruction_result_t Operation::extcodehash(
  gas_t gas,      
  instruct_t instruction, 
  std::shared_ptr<Context> context, 
  std::shared_ptr<ByteReader> reader,
  std::shared_ptr<AccountState> accountState,
  std::shared_ptr<External> external,
  std::shared_ptr<Memory> memory, 
  std::shared_ptr<StackMachine> stack
) {  
  uint256_t address = stack->peek(0);
  stack->pop(1);
  std::shared_ptr<bytes_t> codeBytes = external->code(address);
  bytes_t hashBytes = Hash::keccak256(codeBytes);
  stack->push(BigInt::fromBigEndianBytes(hashBytes));
  return std::make_pair(InstructionResult::OK, 0);
}