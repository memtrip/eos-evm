#pragma once
#include <memory>
#include <evm/call.hpp>
#include <evm/types.h>
#include <evm/pending_state.hpp>
#include <evm/big_int.hpp>
#include <evm/context.hpp>
#include <evm/overflow.hpp>
#include <evm/hex.hpp>
#include <evm/utils.hpp>
#include <evm/external.h>

#include <eos_external.hpp>
#include <eos_system.hpp>

class eos_execute {
  public:
    static call_result_t transaction(
      const uint256_t& senderAddress,
      const env_t& env,
      std::shared_ptr<std::vector<RLPItem>> rlp, 
      std::shared_ptr<External> external,
      std::shared_ptr<PendingState> pendingState
    ) {

      std::shared_ptr<Memory> memory = std::make_shared<Memory>();

      call_result_t callResult;

      switch (Transaction::type(rlp)) {
        case TransactionActionType::TRANSACTION_CREATE:
          {
            std::shared_ptr<Context> context = Context::makeCreate(env, senderAddress, rlp);

            callResult = Call::call(
              0,
              CallType::ACTION_CREATE,
              memory,
              context,
              external,
              pendingState
            );

            if (callResult.first == MessageCallResult::MESSAGE_CALL_RETURN) {
              
              MessageCallReturn messageCallReturn = std::get<MessageCallReturn>(callResult.second);

              std::shared_ptr<bytes_t> code = std::make_shared<bytes_t>(memory->readSlice(
                messageCallReturn.offset, 
                messageCallReturn.size
              ));

              external->incrementNonce();

              emplace_t emplaceResult = external->emplaceCode(
                context->sender, 
                context->sender,
                0, // TODO: where does the endowment for parent addresses come from?
                code
              );

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

            callResult = Call::call(
              0,
              CallType::ACTION_CALL,
              memory,
              context,
              external,
              pendingState
            );

            if (callResult.first == MessageCallResult::MESSAGE_CALL_RETURN) {
              MessageCallReturn messageCallReturn = std::get<MessageCallReturn>(callResult.second);
              if (messageCallReturn.size > 0)
                eosio::print("return" + Hex::bytesToWordOutput(memory->memory, messageCallReturn.offset, messageCallReturn.size));
            } else if (callResult.first == MessageCallResult::MESSAGE_CALL_REVERTED) {
              MessageCallReturn messageCallReturn = std::get<MessageCallReturn>(callResult.second);
              if (messageCallReturn.size > 0)
                eosio::print("revert" + Hex::bytesToWordOutput(memory->memory, messageCallReturn.offset, messageCallReturn.size));
            }

            break;
        }
      }
      return callResult;
    }

    static call_result_t code(
      const uint256_t& senderAddress,
      const env_t& env,
      const bytes_t& code, 
      std::shared_ptr<std::vector<RLPItem>> rlp, 
      std::shared_ptr<External> external,
      std::shared_ptr<PendingState> pendingState
    ) {

      std::shared_ptr<Memory> memory = std::make_shared<Memory>();

      uint256_t toAddress = BigInt::fromBigEndianBytes(Transaction::address(rlp));
      std::shared_ptr<Context> context = Context::makeCodeCall(env, senderAddress, code, rlp, external);

      return Call::call(
        0,
        CallType::ACTION_STATIC_CALL,
        memory,
        context,
        external,
        pendingState
      );
    }
};