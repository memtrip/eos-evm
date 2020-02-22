#!/bin/bash

rm -rf ./build/
mkdir -p build
pushd build
cmake ..
make -j$(nproc)
cp ./eos_evm-prefix/src/eos_evm-build/eos_evm.wasm ../eos_evm.wasm