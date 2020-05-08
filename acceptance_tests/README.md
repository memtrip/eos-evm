## Acceptance tests

eos-evm has an extensive unit, integration, and acceptance test coverage. This project contains the integration tests that are generated from the Ethereum test spec, and the acceptance tests which test the deployment and interactions of a wide variety of compiled solditiy contracts.

## Contracts

The Ethereum test spec provides extensive test coverage of the expected EVM state, but it does not cover any potential integration issues between the EVM and it's host environment, in this case, an eosio smart contract. The solidity contracts used in the acceptance tests can be found in `./solidity/contracts`. The following assertions are made for each contract;

| Action                                                                    | Assertion                                                                                                                                                                            |
| ------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| The smart contract constructor bytecode is pushed as a signed transaction | The expected entires are created in the eosio smart contract `code` table, with the correct balances and nonces. The sender account balance is debited for any payable constructors. |
