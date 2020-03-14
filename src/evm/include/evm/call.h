#pragma once
#include <evm/types.h>
#include <evm/return_data.h>
#include <evm/call.h>
#include <evm/external.h>
#include <evm/account_state.h>

// message call result
enum MessageCallResult {
  MESSAGE_CALL_SUCCESS,
  MESSAGE_CALL_FAILED,
  MESSAGE_CALL_REVERTED
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
    Call(uint16_t stackDepthArg);
    call_result_t call(
      gas_t gas,
      uint256_t senderAddress,
      uint256_t receiveAddress,
      uint256_t value,
      bytes_t& data,
      uint256_t codeAddress,
      action_type_t callType,
      bool trap,
      env_t env,
      External& external,
      AccountState& accountState
    );
    call_result_t create(
      gas_t gas,
      uint256_t address,
      uint256_t value,
      bytes_t& code,
      action_type_t callType,
      bool trap,
      env_t env,
      External& external,
      AccountState& accountState
    );
  private:
    uint16_t stackDepth;
    call_result_t makeCall(
      params_t params,
      action_type_t callType,
      bool trap,
      env_t env,
      External& external,
      AccountState& accountState
    );
};