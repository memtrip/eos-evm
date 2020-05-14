#pragma once
#include <memory>
#include <evm/call.hpp>
#include <evm/types.h>
#include <evm/pending_state.hpp>
#include <evm/big_int.hpp>
#include <evm/context.hpp>
#include <evm/overflow.hpp>
#include <evm/hex.hpp>
#include <evm/external.h>

class Execute {
  public:
    static call_result_t transaction(
      const uint256_t& senderAddress,
      const uint64_t nonce,
      const env_t& env,
      TransactionActionType actionType,
      gas_t gasLimit,
      const uint256_t& gasPrice,
      const uint256_t& value,
      std::shared_ptr<bytes_t> data,
      const uint256_t& toAddress,
      std::shared_ptr<Operation> operation,
      std::shared_ptr<GasCalculation> gasCalculation,
      std::shared_ptr<External> external,
      std::shared_ptr<PendingState> pendingState
    ) {

      std::shared_ptr<Memory> memory = std::make_shared<Memory>();

      call_result_t callResult;

      switch (actionType) {
        case TransactionActionType::TRANSACTION_CREATE:
          {
            uint256_t codeAddress = Address::makeCreateAddress(
              AddressScheme::LEGACY,
              senderAddress,
              uint256_t(nonce),
              std::shared_ptr<bytes_t>()
            );

            std::shared_ptr<Context> context = Context::makeCreate(
              env, 
              senderAddress, 
              codeAddress,
              gasLimit,
              gasPrice,
              value, 
              data
            );

            emplace_t emplaceResult = external->emplaceCodeAddress(
              senderAddress, 
              codeAddress,
              context->value             
            );

            switch (emplaceResult.first) {
              case EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND:
              case EmplaceResult::EMPLACE_CODE_ALREADY_EXISTS:
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

            callResult = Call::call(
              0,
              CallType::ACTION_CREATE,
              memory,
              context,
              operation,
              gasCalculation,
              external,
              pendingState
            );

            if (callResult.first == MessageCallResult::MESSAGE_CALL_RETURN) {
              
              MessageCallReturn messageCallReturn = std::get<MessageCallReturn>(callResult.second);

              bytes_t code = memory->readSlice(
                messageCallReturn.offset, 
                messageCallReturn.size
              );

              emplace_t emplaceResult = external->emplaceParentCode(
                codeAddress,
                context->value,
                code
              );

              switch (emplaceResult.first) {
                case EmplaceResult::EMPLACE_ADDRESS_NOT_FOUND:
                case EmplaceResult::EMPLACE_CODE_ALREADY_EXISTS:
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
            std::shared_ptr<bytes_t> code = std::make_shared<bytes_t>(external->code(toAddress));

            std::shared_ptr<Context> context = Context::makeCall(
              env, 
              senderAddress, 
              toAddress, 
              gasLimit,
              gasPrice,
              value,
              code, 
              data
            );

            callResult = Call::call(
              0,
              CallType::ACTION_CALL,
              memory,
              context,
              operation,
              gasCalculation,
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
      std::shared_ptr<bytes_t> code, 
      TransactionActionType actionType, 
      gas_t gasLimit,
      const uint256_t& gasPrice,
      const uint256_t& value,
      std::shared_ptr<bytes_t> data,
      const uint256_t& toAddress,
      std::shared_ptr<Operation> operation,
      std::shared_ptr<GasCalculation> gasCalculation,
      std::shared_ptr<External> external,
      std::shared_ptr<PendingState> pendingState
    ) {

      std::shared_ptr<Memory> memory = std::make_shared<Memory>();

      std::shared_ptr<Context> context = Context::makeCodeCall(
        env,
        senderAddress, 
        gasLimit,
        gasPrice,
        value,
        code, 
        data
      );

      return Call::call(
        0,
        CallType::ACTION_STATIC_CALL,
        memory,
        context,
        operation,
        gasCalculation,
        external,
        pendingState
      );
    }
};