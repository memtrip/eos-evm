# eos-evm contract
The eos-evm smart contract is composed of four components; the contract execution environment, a C++17 implementation of the EVM, 
an extensive unit test suite, and build scripts.

## Build
The contract uses CMake and EOSIO.CDT (Contract Development Toolkit) to compile the solution into WASM, and to generate an ABI definition.
```
./scripts/build.sh
```

## Test
The EVM implementation has no dependency on EOSIO.CDT, it is unit tested in isolation using Catch2. The tests appended with `_`, such as 
`_vmArithmeticTest.test` have been auto generated based off the Ethereum tests respository. Thousands of tests and assertions ensure the reliablity
of the EVM implementation.
```
./scripts/run_all_tests.sh
```

## Deploy
The contract can be built and deployed to the local docker environment using;
```
./deploy # deploy existing artifacts
./publish # build and deploy
```

The --add-code permisison is required to grant permissions for the Withdraw transfer action.
```
cleos set account permission eos.evm active --add-code
```

## Actions
### `create`
```
void create(name from, string message);
```
EVM accounts are created using the `create` action, the action accepts a `from` account, and either a blob of arbitrary text or an existing Ethereum address as a `message`. A new account identifier is created by hashing these two inputs.
```
keccak256(fromAccount, message)
```  


### `raw`
```
void raw(name from, bytes_t code, string sender);
```
Ethereum transactions are pushed to eos-evm using the `raw` action, the action accepts a `from` account, an RLP encoded Ethereum transaction, and an optional sender accountIdentifier. The action either queries the `account` table with the provided sender accountIdentifier, or if a sender was not provided, the contract attempts to resolve an Ethereum address based on the V, R, S, and digest components of the signed trsnsaction. If the address of a signature can be resolved, it is hashed with the eos account name of the sender. The `account` table is queried with this hash, and used to determine whether the sender has previously sent a `create` action containing the signature address. If an `account` exists, its accountIdentifier will be used as the `senderAddress` in the EVM execution context. 

This Address scheme allows the eos-evm smart contract to determine whether an eos account is in possesion of the private key associated with an external Ethereum address. 

### `withdraw`
```
void withdraw(name to, asset quantity);
```
Withdraw a quantity from the EVM balance of the provided eos account name.

### `transfer`
```
void transfer(name from, name to, asset quantity, string memo);
```
The contract responds to eosio.token transfers, the value received in the transfer is used to seed the eos account associated with the `from` account with an EVM balance. An EVM acocunt must be associated with the `from` account for the transfer to be 
successful. 1 Ether is represented as 1.0000 EOS.

## Tables
### `account` 
eos-evm accounts that have been created via the `create` Action, the table is indexed by `user` and `accountIdentifier`. 
| Name              | Type               | Description                                             |
| ----------------- | ------------------ | ------------------------------------------------------- |
| user              | eosio::name        | The eos account that created the EVM account            |
| nonce             | uint64_t           | Incremented with each transaction                       |
| balance           | eosio::checksum256 | EVM balance as a uint256 value                          |
| accountIdentifier | eosio::checksum256 | The result of keccak256(eos_account_name, salt/address) |

### `account_state`
Persistent storage for EVM smart contracts, the table is indexed by `accountIdentifier` and `key`. The table is used by the SLOAD and SSTORE instructions, it is also useful for clients that want to query the state of an EVM contract.
| Name              | Type               | Description                                          |
| ----------------- | ------------------ | ---------------------------------------------------- |
| pk                | uint64_t           | auto incrementing value to ensure each row is unique |
| accountIdentifier | eosio::checksum256 | The contract address that created the data entry     |
| key               | eosio::checksum256 | uint256 key                                          |
| value             | eosio::checksum256 | uint256 value                                        |

### `account_code`
EVM contract address with balance and bytecode, the table is indexed by `owner` and `address`. 
| Name    | Type                 | Description                                                                             |
| ------- | -------------------- | --------------------------------------------------------------------------------------- |
| pk      | uint64_t             | auto incrementing value to ensure each row is unique                                    |
| owner   | eosio::checksum256   | The accountIdentifier (or address) of the account (or contract) that published the code |
| address | eosio::checksum256   | The address of the contract                                                             |
| nonce   | uint64_t             | Incremented when the account_code address creates a child contract                      |
| code    | std::vector<uint8_t> | The contract bytcode                                                                    |
| balance | eosio::checksum256   | The balance of the contract address                                                     |

## Divergence from the EVM specification
### SSTORE

The SSTORE operation uses keccak256(code_address + key) to store data to the Account State Table. This ensures that
keys are always unique within the `account_state` table index.

### SLOAD

THE SLOAD operation uses keccak256(code_address + key) as the key to retreive data from the Account State Table.