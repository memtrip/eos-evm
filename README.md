# eos-evm

eos-evm is an implementation of the Ethereum Virtual Machine (EVM) written in C++17 for the EOSIO.CDT (Contract Development Toolkit). The project enables Ethereum compatible smart contracts to be executed by an eosio blockchain.
An address scheme is used to link an eosio account to an Ethereum address, eos-evm will accept a signed Ethereum transaction, verify the validity of the signature, execute the transaction, and commit any state changes as per the EVM spec. In the case of an unsigned Ethereum transaction, eos-evm will execute the transaction using the eosio permission system.

## Overview

eos-evm is divided into five subprojects:

| Name             | Purpose                                                                               |
| ---------------- | ------------------------------------------------------------------------------------- |
| Environment      | Single node Docker environment with eos-evm and the default system contracts deployed |
| Acceptance Tests | Verifying EVM state and behaviour via Chain API `push_transaction`                    |
| Clients          | REPL, and an Ethereum test generator                                                  |
| Contract         | C++17 EVM implementation, the eosio smart contract, and EVM unit tests                |
| Tools            | Useful javascript tools for debugging various aspects of the EVM                      |

## Development environment

The solution is development on Mac OSX 10.14.\*, and the smart contract is compiled using EOSIO.CDT 1.7.0. Changes may
be required to build the contract or run the unit tests in a different environment.
