#!/bin/bash

rm -rf ../environment/mnt_nodeos/eos_evm/
mkdir ../environment/mnt_nodeos/eos_evm/
cp ./eos_evm.wasm ../environment/mnt_nodeos/eos_evm/
cp ./eos_evm.abi ../environment/mnt_nodeos/eos_evm/

docker exec -it environment_nodeos_1 bash /eosio/deploy-eos_evm.sh
