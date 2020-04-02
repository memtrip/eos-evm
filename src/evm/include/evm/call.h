#pragma once
#include <memory>
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/external.h>
#include <evm/account_state.h>
#include <evm/context.h>

// message call result
enum MessageCallResult {
  MESSAGE_CALL_SUCCESS,
  MESSAGE_CALL_FAILED,
  MESSAGE_CALL_REVERTED,
  MESSAGE_CALL_OUT_OF_GAS,
  MESSAGE_CALL_TRACE
};

struct MessageCallReturn {
  uint256_t gasLeft;
  ReturnData returnData;
};

typedef std::variant<
  uint8_t,
  MessageCallReturn
> call_result_data_t;

typedef std::pair<MessageCallResult, call_result_data_t> call_result_t;

// contract create result
enum CreateContractResult {
  CONTRACT_CREATE_CREATED,
  CONTRACT_CREATE_REVERTED,
  CONTRACT_CREATE_FAILED
};

struct CreateContractReturn {
  uint256_t address;
  uint256_t gasLeft;
};

typedef std::variant<
  uint8_t,
  CreateContractReturn
> create_contract_result_data_t;

typedef std::pair<CreateContractResult, create_contract_result_data_t> create_contract_result_t;

// address scheme
enum AddressSchemeType {
  FromSenderAndNonce,
  FromSenderSaltAndCodeHash
};

typedef std::variant<
  uint8_t,
  uint256_t
> address_scheme_type_t;

typedef std::pair<
  AddressSchemeType,
  address_scheme_type_t
> address_scheme_t;

class Call {
  public:
    explicit Call(uint16_t s): stackDepth(s) { };
    call_result_t create(
      bool trap,
      std::shared_ptr<Context> context,
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState
    );
    call_result_t call(
      bool trap,
      std::shared_ptr<Context> context,
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState
    );
  private:
    uint16_t stackDepth;
    call_result_t makeCall(
      action_type_t callType,
      bool trap,
      std::shared_ptr<Context> context,
      std::shared_ptr<External> external,
      std::shared_ptr<AccountState> accountState
    );
};