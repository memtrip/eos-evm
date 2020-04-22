#pragma once
#include <memory>
#include <evm/call.h>
#include <evm/types.h>
#include <evm/account_state.hpp>
#include <evm/big_int.hpp>
#include <evm/context.hpp>
#include <evm/overflow.hpp>
#include <evm/hex.hpp>
#include <evm/external.h>

#include <eos_external.hpp>
#include <eos_system.hpp>

class eos_execute {
  public:
    static call_result_t transaction(
      uint256_t senderAddress,
      std::shared_ptr<std::vector<RLPItem>> rlp, 
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState
    ) {
      env_t env = eos_system::env();
      Call call = Call(0);

      std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
      std::shared_ptr<Memory> memory = std::make_shared<Memory>(memoryBytes);

      call_result_t callResult;

      switch (Transaction::type(rlp)) {
        case TransactionActionType::TRANSACTION_CREATE:
          {
            std::shared_ptr<Context> context = Context::makeCreate(env, senderAddress, rlp);

            callResult = call.call(
              memory,
              context,
              external,
              accountState
            );

            if (callResult.first == MessageCallResult::MESSAGE_CALL_RETURN) {
              
              MessageCallReturn messageCallReturn = std::get<MessageCallReturn>(callResult.second);

              std::shared_ptr<bytes_t> code = memory->readSlice(
                messageCallReturn.offset, 
                messageCallReturn.size
              );

              emplace_t emplaceResult = external->emplaceCode(context->sender, 0, code, AddressScheme::EIP_1014);

              switch (emplaceResult.first) {
                case EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND:
                  return std::make_pair(
                    MessageCallResult::MESSAGE_CALL_FAILED,
                    TrapKind::TRAP_INVALID_CODE_ADDRESS
                  );
                case EmplaceResult::EMPLACE_INSUFFICIENT_FUNDS:
                  return std::make_pair(
                    MessageCallResult::MESSAGE_CALL_FAILED,
                    TrapKind::TRAP_INSUFFICIENT_FUNDS
                  );
                case EmplaceResult::EMPLACE_SUCCESS:
                  break;
              }
            }
            break;
          }
        case TransactionActionType::TRANSACTION_CALL:
          {
            uint256_t toAddress = BigInt::fromBigEndianBytes(Transaction::address(rlp));

            std::shared_ptr<Context> context = Context::makeCall(env, senderAddress, toAddress, rlp, external);

            callResult = call.call(
              memory,
              context,
              external,
              accountState
            );

            if (callResult.first == MessageCallResult::MESSAGE_CALL_RETURN) {
              MessageCallReturn messageCallReturn = std::get<MessageCallReturn>(callResult.second);
              if (messageCallReturn.size > 0)
                eosio::print("return" + Hex::bytesToWordOutput(memory->memory, messageCallReturn.offset, messageCallReturn.size));
            }

            break;
        }
      }
      return callResult;
    }

    static call_result_t code(
      uint256_t senderAddress,
      const bytes_t& code, 
      std::shared_ptr<std::vector<RLPItem>> rlp, 
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState
    ) {
      env_t env = eos_system::env();
      Call call = Call(0);

      std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
      std::shared_ptr<Memory> memory = std::make_shared<Memory>(memoryBytes);

      uint256_t toAddress = BigInt::fromBigEndianBytes(Transaction::address(rlp));
      std::shared_ptr<Context> context = Context::makeCodeCall(env, senderAddress, code, rlp, external);

      return call.call(
        memory,
        context,
        external,
        accountState
      );
    }
};