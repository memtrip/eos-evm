# eos-evm

eos-evm is an implementation of the Ethereum Virtual Machine (EVM) written in C++17 for the EOSIO.CDT (Contract Development Toolkit). The project enables Ethereum compatible smart contracts to be executed by an eosio blockchain.
An address scheme is used to link an eosio account to an Ethereum address, eos-evm will accept a signed Ethereum transaction, verify the validity of the signature, execute the transaction, and commit any state changes as per the EVM spec. In the case of an unsigned Ethereum transaction, eos-evm will execute the transaction using the eosio permission system.

## Overview

eos-evm is divided into five subprojects:

| Name             | Purpose                                                                               |
| ---------------- | ------------------------------------------------------------------------------------- |
| Environment      | Single node Docker environment with eos-evm and the default system contracts deployed |
| Acceptance Tests | Verifying EVM state and behaviour via Chain API `push_transaction`                    |
| Clients          | Example contracts, Kotlin SDK for eos-evm contracts, and an Ethereum test generator   |
| Contract         | C++17 EVM implementation, the eosio smart contract, and EVM unit tests                |
| Tools            | Useful javascript tools for debugging various aspects of the EVM                      |

## Divergence from the EVM specification

### SSTORE

The SSTORE operation uses keccak256(code_address + key_operand) to store data to the Account State Table.

### SLOAD

THE SLOAD operation uses keccak256(code_address + key_operand) as the key to retreive data from the Account State Table.

### Deployment

When deploying the EVM smart contract, the --add-code permisison is required to grant permissions for the Withdraw transfer action.

```
cleos set account permission eos.evm active --add-code
```

### TODO

- Derive smart contract table scope from accountIdentifier
