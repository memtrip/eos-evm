## Run the test suite

./scripts/run_tests.sh

## Build the eosio contract with stubbed evm

```
docker run --rm --name eosio.cdt_v1.7.0 --volume "/Users/samkirton/EOS Studio/eos_evm:/project" -w /project eostudio/eosio.cdt:v1.7.0 /bin/bash -c "eosio-cpp -DSTUB=true -abigen -I ./include -R resource -contract eos_evm -o eos_evm.wasm src/eos_evm.cpp"
```

## Build all the contract sources

```
docker run --rm --name eosio.cdt_v1.7.0 --volume "/Users/samkirton/EOS Studio/eos_evm:/project" -w /project eostudio/eosio.cdt:v1.7.0 /bin/bash -c "eosio-cpp -abigen -I ./include -I ./deps/keccak/include/ -I ./deps/intx/include/ -I ./evm/include -R resource -contract eos_evm -o eos_evm.wasm src/eos_evm.cpp ./deps/keccak/*.cpp ./deps/intx/lib/intx/*.cpp ./evm/*.cpp"
```
