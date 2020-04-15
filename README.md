## Divergence from the EVM specification

### SSTORE

The SSTORE operation uses keccak256(code_address + key_operand) to store data to the Account State Table.

### SLOAD

THE SLOAD operation uses keccak256(code_address + key_operand) as the key to retreive data from the Account State Table.

### TODO
- Derive smart contract table scope from accountIdentifier