# eos-evm

eos-evm is an implementation of the Ethereum Virtual Machine (EVM) written in C++17 for the EOSIO.CDT (Contract Development Toolkit). The project enables Ethereum compatible smart contracts to be executed by an eosio blockchain.
An address scheme is used to link an eosio account to an Ethereum address, eos-evm will accept a signed Ethereum transaction, verify the validity of the signature, execute the transaction, and commit any state changes as per the EVM spec. In the case of an unsigned Ethereum transaction, eos-evm will execute the transaction using the eosio permission system.

## Overview

The project

- Acceptance Tests
- Clients
- Contract
- Environment
- Tools

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

### Nonce

The Ethereum transaction nonce rules are enforced, but it's debatable as to whether this is really required, since eosio already provides it's own douple spending prevention mechanism. This extra

### TODO

- Derive smart contract table scope from accountIdentifier
