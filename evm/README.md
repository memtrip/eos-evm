## Add boost to the C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH="$HOME/.cpp/catch2:$CPLUS_INCLUDE_PATH"
export CPLUS_INCLUDE_PATH="$HOME/.cpp/intx/include:$CPLUS_INCLUDE_PATH"

## Run the test suite

./scripts/run_tests.sh
