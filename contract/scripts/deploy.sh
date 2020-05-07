#!/bin/bash

rm -rf ./env/mnt_nodeos/eos_evm/
mkdir ./env/mnt_nodeos/eos_evm/
cp ./eos_evm.wasm ./env/mnt_nodeos/eos_evm/
cp ./eos_evm.abi ./env/mnt_nodeos/eos_evm/

docker exec -it env_nodeos_1 bash /eosio/deploy-eos_evm.sh
