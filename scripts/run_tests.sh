g++ -std=c++17 ./evm/*.cpp ./evm_tests/*.cpp ./evm/keccak/*.cpp ./deps/intx/lib/intx/*.cpp -I ./evm/ -I ./deps/intx/include/ -I ./deps/catch2/ -o ./out/test_suite.out
./out/test_suite.out