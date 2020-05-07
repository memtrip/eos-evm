# Tools
Useful javascript tools that were used to debug various aspects of the EVM.

## Setup

```
npm install
```

## Decode RLP hex string

The following command decodes an RLP encoded string, it is useful for verifing that the tests in rlp_decode.test.cpp and transaction.test.cpp are making the correct assertions.

```
node decode.js <rlp_string>
```

## Generate keypair / sign message

The following command will generate an Ethereum key pair, sign the message, and output the Ethereum address and a stub RLP encoded transaction
containing the V, R, S of the signed message. The output is useful for verifying that Ethereum addresses are resolved from signatures correctly.

```
node sign.js <message>
```

## Decompress Key
The following command will decompress a compressed EDCSA public key into a 65 bytes uncompressed public key, it is useful for verifying that decompress_key.hpp produces the correct results. 
```
node ecc_decompress.js <compressed_key>
```