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
