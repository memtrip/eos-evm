## Add boost to the C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH="$HOME/.cpp/catch2:$CPLUS_INCLUDE_PATH"
export CPLUS_INCLUDE_PATH="$HOME/.cpp/boost_1_72_0:$CPLUS_INCLUDE_PATH"

## Run the test suite

./scripts/run_tests.sh
