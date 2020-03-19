#!/bin/bash

rm -rf ./build/
rm eos_evm.abi
rm eos_evm.wasm
mkdir -p build
pushd build
cmake ..
make -j$(nproc)
cp ./eos_evm-prefix/src/eos_evm-build/eos_evm.wasm ../eos_evm.wasm
cp ./eos_evm-prefix/src/eos_evm-build/eos_evm.abi ../eos_evm.abi