#include <memory>
#include <evm/types.h>
#include <evm/instruction.h>
#include <evm/memory.h>
#include <evm/stack.h>
#include <evm/vm_result.h>
#include <evm/opcode.h>
#include <evm/byte_reader.h>

class Operation { 
  typedef instruction_result_t (Operation::*operation_t)(
    gas_t gas,
    instruct_t instruction, 
    std::shared_ptr<Context> context,
    std::shared_ptr<ByteReader> reader,
    std::shared_ptr<AccountState> accountState,
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
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t add(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t mul(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t sub(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t div(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t sdiv(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t mod(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t smod(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t addmod(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t mulmod(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t exp(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t signextend(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t lt(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t gt(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t slt(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t sgt(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t eq(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t iszero(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t _and(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t _or(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t _xor(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t _not(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t _byte(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t shl(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t shr(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t sar(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t sha3(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t address(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t origin(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t caller(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t callvalue(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t calldataload(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t calldatasize(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t calldatacopy(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t gasprice(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t blockhash(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t coinbase(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t timestamp(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t number(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t difficulty(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t gaslimit(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t chainid(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t pop(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t mload(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t mstore(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t mstore8(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t jump(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t jumpi(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t msize(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t dup(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t swap(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t extcodesize(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t extcodecopy(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t selfbalance(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t log(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t selfdestruct(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t codesize(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t codecopy(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t pc(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t push(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t jumpdest(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t balance(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t sload(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t sstore(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t gas(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t _return(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t _revert(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
    instruction_result_t extcodehash(
      gas_t gas,      
      instruct_t instruction, 
      std::shared_ptr<Context> context, 
      std::shared_ptr<ByteReader> reader,
      std::shared_ptr<AccountState> accountState,
      std::shared_ptr<External> external,
      std::shared_ptr<Memory> memory, 
      std::shared_ptr<StackMachine> stack
    );
};