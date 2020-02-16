## Setup

```
npm install
```

## Decode RLP hex string

This command will decode an RLP encoded string, it is useful for verifying the tests in
rlp_decode.test.cpp and transaction.test.cpp are making the correct assertions.

```
node decode.js <rlp_string>
```

## Generate keypair / sign message

This command will generate a key pair, sign a message, and output an Ethereum address + a stub RLP encoded transaction
containing the V, R, S of the signed message. The output can be used to test code related to
resolving an Ethereum address from a signature.

```
node sign.js <message>
```
