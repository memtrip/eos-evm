g++ -std=c++17 ./src/evm/src/*.cpp ./evm_tests/main.cpp ./evm_tests/external_mock.cpp ./evm_tests/vm.test_call.cpp ./src/evm/deps/keccak/src/*.cpp ./src/evm/deps/intx/src/*.cpp -I ./src/evm/include/ -I ./src/evm/deps/intx/include/ -I ./src/evm/deps/keccak/include/ -I ./evm_tests/include/ -I ./src/evm/deps/secp256k1/upstream/include -o ./out/test_suite.out
./out/test_suite.out