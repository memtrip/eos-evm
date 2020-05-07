## Test suite generation

The Ethereum community actively maintains a JSON test specification (https://github.com/ethereum/tests), the specification defines an extensive test suite that can verify the integrity of an EVM implementation. This project parses the `VMTests` and `TransactionTests` into an object model, Freemarker templates use this object model to auto generate code files containing C++ Catch2 unit tests and Kotlin integration tests for each scenario.

The generated unit tests exist in the contracts/evm_tests/ project, and the integration tests exist in the acceptance_tests project.

### Tests fork

The VMTest scenarios occasionally depend existing addresses or a pre-defined blockchain state, due to the eos-evm address scheme, it is not possible to verify these scenarios from the integration test level. As such, `ethereum/tests` has been forked to provide the following new JSON properties:

- `unitOnly` the scenario will only be generated as a unit test.
- `post["failure"]["reason"]` allows VM integration tests to make assertions against failure reasons e.g; jumped_destination or stack_underflow.
- `skip` the scenario will be skipped (only used to skip the 10mb encoded transaction test)

### Generate

The following command is used to generate the test code, the files will be written to the `./build` directory.

```
./gradlew runGenerate
```
