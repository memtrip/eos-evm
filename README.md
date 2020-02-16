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

## Run docker

```
docker run -dt --name eosio_evm_v2.0.0 --publish 8888:8888 --publish 5555:5555 --volume /Users/samkirton/.eosio/evm:/eosio -w /eosio eostudio/eos:v2.0.0 /bin/bash
```

```
docker exec -it -w /eosio eosio_evm_v2.0.0 /bin/bash -c "nodeos -e -p eosio --plugin eosio::http_plugin --plugin eosio::chain_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::history_api_plugin --data-dir /eosio/data --config-dir /eosio/config --http-server-address=0.0.0.0:8888 --access-control-allow-origin=* --http-validate-host=false --max-transaction-time=200 --disable-replay-opts --contracts-console"
```

## Hard replay

```
docker exec -it -w /eosio eosio_evm_v2.0.0 /bin/bash -c "nodeos -e -p eosio --plugin eosio::http_plugin --plugin eosio::chain_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::history_api_plugin --data-dir /eosio/data --config-dir /eosio/config --http-server-address=0.0.0.0:8888 --access-control-allow-origin=* --http-validate-host=false --max-transaction-time=200 --hard-replay-blockchain --disable-replay-opts --contracts-console --filter-on=* --filter-out=eosio:onblock:"
```
