#include "catch.hpp"
#include "test_utils.hpp"
#include "external_mock.hpp"

#include <memory>

#include <evm/utils.hpp>
#include <evm/vm.h>
#include <evm/hex.hpp>
#include <evm/gasometer.hpp>
#include <evm/big_int.hpp>

TEST_CASE("Create the most basic contract using COPYCODE", "[create]") {
  bytes_t codeBytes =  Hex::hexToBytes("6080604052348015600f57600080fd5b50603580601d6000396000f300");
  bytes_t emptyBytes = bytes_t();
  env_t env = Utils::env();
  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  // and then
  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" == 
    code
  );
}

TEST_CASE("Create contract using CODECOPY", "[create]") {
  bytes_t codeBytes = Hex::hexToBytes("608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032");
  env_t env = Utils::env();
  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  // and then
  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a723158209551755b4e59ca6cf78d79f5356d91565950805937074458700610f23c6ecf9b64736f6c63430005100032" == 
    code
  );

  REQUIRE(1 == pendingState->logs.size());
  CHECK(1 == pendingState->logs[0].topics.size());
  CHECK("b8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad6" == 
    Utils::uint256_2str(pendingState->logs[0].topics[0])
  );

  REQUIRE(0 == external->emplaceSpy.size());
}

TEST_CASE("Create contract using CREATE (1)", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes("7c601080600c6000396000f3006000355415600957005b60203560003555600052601d60036017f0600055");

  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_VOID == vm_result.first);

  REQUIRE(1 == external->emplaceSpy.size());

  std::string code = external->emplaceSpy[0].second;

  CHECK("6000355415600957005b602035600035" == 
    code
  );
}

TEST_CASE("Create main contract using COPYCODE, and a child contract with CREATE (1)", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes(
    "608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008b565b61013a8061016883390190565b60cf806100996000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063bc33657a14602d575b600080fd5b60336075565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820d9d1db44331e8aef66d876ff3bdf5c632d0ca766882d6e738a2c7b978d29077364736f6c63430005100032608060405234801561001057600080fd5b507fb8a00d6d8ca1be30bfec34d8f97e55f0f0fd9eeb7fb46e030516363d4cfe1ad630604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a160b8806100826000396000f3fe6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a7231582071c7fe98a34e7c0c2e10ae018de7d3708ce7189591eff656e9cbf717bc03c1f664736f6c63430005100032"
  );
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("6080604052348015600f57600080fd5b506004361060285760003560e01c8063bc33657a14602d575b600080fd5b60336075565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820d9d1db44331e8aef66d876ff3bdf5c632d0ca766882d6e738a2c7b978d29077364736f6c63430005100032" == 
    code
  );

  REQUIRE(1 == external->emplaceSpy.size());

  std::string childCode = external->emplaceSpy[0].second;

  CHECK("6080604052348015600f57600080fd5b506004361060285760003560e01c8063771602f714602d575b600080fd5b606060048036036040811015604157600080fd5b8101908080359060200190929190803590602001909291905050506076565b6040518082815260200191505060405180910390f35b600081830190509291505056fea265627a7a7231582071c7fe98a34e7c0c2e10ae018de7d3708ce7189591eff656e9cbf717bc03c1f664736f6c63430005100032" == 
    childCode
  );
}

TEST_CASE("Create contract using CREATE2", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes(
    "6080604052348015600f57600080fd5b5060cb8061001e6000396000f3fe608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032"
  );
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a7231582069c4265b77ab1bd39221ac01c9f6f1adacb2f5a7beeccf724523846fa4aaf8ba64736f6c63430005100032" == 
    code
  );
}

TEST_CASE("Create contract using CREATE (3)", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes(
    "608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008a565b60e98061024c83390190565b6101b3806100996000396000f3fe6080604052600060606000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f7468616e6b73282900000000000000000000000000000000000000000000000081525060080190506040518091039020604051602401604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b6020831061010c57805182526020820191506020810190506020830392506100e9565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d806000811461016c576040519150601f19603f3d011682016040523d82523d6000602084013e610171565b606091505b508092508193505050505000fea265627a7a72315820d976ace6a778821e28709e2710c20b2f218748110932b7e001740af96873f19264736f6c634300051000326080604052348015600f57600080fd5b5060cb8061001e6000396000f3fe608060405260043610601c5760003560e01c806373d98e39146021575b600080fd5b60276029565b005b7fbbbf55a6f5ae8ee75e6fb8f92a93e32841ed3055bf2139469c60bbc79a455da73334604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018281526020019250505060405180910390a156fea265627a7a723158202a752690fee21f8247bd5e92628da8244d755a66235b778e5d4f5751c35af8a664736f6c63430005100032"
  );
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    100000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("6080604052600060606000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f7468616e6b73282900000000000000000000000000000000000000000000000081525060080190506040518091039020604051602401604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b6020831061010c57805182526020820191506020810190506020830392506100e9565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d806000811461016c576040519150601f19603f3d011682016040523d82523d6000602084013e610171565b606091505b508092508193505050505000fea265627a7a72315820d976ace6a778821e28709e2710c20b2f218748110932b7e001740af96873f19264736f6c63430005100032" == 
    code
  );
}

TEST_CASE("Create contract using CREATE (4)", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes(
    "608060405234801561001057600080fd5b5060405161001d906100e8565b604051809103906000f080158015610039573d6000803e3d6000fd5b50600160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550604051610086906100f5565b604051809103906000f0801580156100a2573d6000803e3d6000fd5b50600260006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550610102565b61012f8061076a83390190565b6101138061089983390190565b610659806101116000396000f3fe608060405234801561001057600080fd5b50600436106100625760003560e01c80631003e2d214610067578063131e2f181461009557806365372147146100c357806374c1328a146100e1578063bf9ce952146101b0578063ec597128146101fa575b600080fd5b6100936004803603602081101561007d57600080fd5b8101908080359060200190929190505050610244565b005b6100c1600480360360208110156100ab57600080fd5b81019080803590602001909291905050506103df565b005b6100cb61057a565b6040518082815260200191505060405180910390f35b61019a600480360360208110156100f757600080fd5b810190808035906020019064010000000081111561011457600080fd5b82018360208201111561012657600080fd5b8035906020019184600183028401116401000000008311171561014857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610580565b6040518082815260200191505060405180910390f35b6101b86105d8565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6102026105fe565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b60006060600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106103585780518252602082019150602081019050602083039250610335565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d80600081146103b8576040519150601f19603f3d011682016040523d82523d6000602084013e6103bd565b606091505b508092508193505050826103d082610580565b146103da57600080fd5b505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106104f357805182526020820191506020810190506020830392506104d0565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d8060008114610553576040519150601f19603f3d011682016040523d82523d6000602084013e610558565b606091505b5080925081935050508261056b82610580565b1461057557600080fd5b505050565b60005481565b60008060008090505b83518110156105ce576001810184510360080260020a8482815181106105ab57fe5b602001015160f81c60f81b60f81c60ff1602820191508080600101915050610589565b5080915050919050565b600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820d08d7fcfdc1c26ae50de9280ac6374d2e9f6d31f2076bd58fe830923168cd30464736f6c63430005100032608060405234801561001057600080fd5b5061010f806100206000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b60008082141560ac576000808190555060d0565b60008260005402905082600054828160c057fe5b041460c757fe5b80600081905550505b600054905091905056fea265627a7a723158202ac29398a5a9046490687efd760134796902de10d0f2e515c1275c5fb3dbbb5a64736f6c63430005100032608060405234801561001057600080fd5b5060f48061001f6000396000f3fe6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b6000808260005401905060005481101560ad57fe5b8060008190555060005491505091905056fea265627a7a723158203a3ae6acef1fa218da2ab4e1ce82a7bdbd3ad1e2fd2a61fdf2b31c0c47f4735c64736f6c63430005100032"
  );
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    150000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("608060405234801561001057600080fd5b50600436106100625760003560e01c80631003e2d214610067578063131e2f181461009557806365372147146100c357806374c1328a146100e1578063bf9ce952146101b0578063ec597128146101fa575b600080fd5b6100936004803603602081101561007d57600080fd5b8101908080359060200190929190505050610244565b005b6100c1600480360360208110156100ab57600080fd5b81019080803590602001909291905050506103df565b005b6100cb61057a565b6040518082815260200191505060405180910390f35b61019a600480360360208110156100f757600080fd5b810190808035906020019064010000000081111561011457600080fd5b82018360208201111561012657600080fd5b8035906020019184600183028401116401000000008311171561014857600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610580565b6040518082815260200191505060405180910390f35b6101b86105d8565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6102026105fe565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b60006060600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106103585780518252602082019150602081019050602083039250610335565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d80600081146103b8576040519150601f19603f3d011682016040523d82523d6000602084013e6103bd565b606091505b508092508193505050826103d082610580565b146103da57600080fd5b505050565b60006060600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1660405180807f63616c63756c6174652875696e74323536290000000000000000000000000000815250601201905060405180910390208460405160240180828152602001915050604051602081830303815290604052907bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19166020820180517bffffffffffffffffffffffffffffffffffffffffffffffffffffffff83818316178352505050506040518082805190602001908083835b602083106104f357805182526020820191506020810190506020830392506104d0565b6001836020036101000a038019825116818451168082178552505050505050905001915050600060405180830381855af49150503d8060008114610553576040519150601f19603f3d011682016040523d82523d6000602084013e610558565b606091505b5080925081935050508261056b82610580565b1461057557600080fd5b505050565b60005481565b60008060008090505b83518110156105ce576001810184510360080260020a8482815181106105ab57fe5b602001015160f81c60f81b60f81c60ff1602820191508080600101915050610589565b5080915050919050565b600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600260009054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a72315820d08d7fcfdc1c26ae50de9280ac6374d2e9f6d31f2076bd58fe830923168cd30464736f6c63430005100032" == 
    code
  );

  REQUIRE(2 == external->emplaceSpy.size());

  std::string subcontract1 = external->emplaceSpy[0].second;
  std::string subcontract2 = external->emplaceSpy[1].second;

  CHECK("6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b6000808260005401905060005481101560ad57fe5b8060008190555060005491505091905056fea265627a7a723158203a3ae6acef1fa218da2ab4e1ce82a7bdbd3ad1e2fd2a61fdf2b31c0c47f4735c64736f6c63430005100032" == 
    subcontract2
  );

  CHECK("6080604052348015600f57600080fd5b506004361060325760003560e01c806365372147146037578063b9d92de8146053575b600080fd5b603d6092565b6040518082815260200191505060405180910390f35b607c60048036036020811015606757600080fd5b81019080803590602001909291905050506098565b6040518082815260200191505060405180910390f35b60005481565b60008082141560ac576000808190555060d0565b60008260005402905082600054828160c057fe5b041460c757fe5b80600081905550505b600054905091905056fea265627a7a723158202ac29398a5a9046490687efd760134796902de10d0f2e515c1275c5fb3dbbb5a64736f6c63430005100032" == 
    subcontract1
  );
}

TEST_CASE("Create contract using CREATE (5)", "[create]") {

  bytes_t codeBytes = Hex::hexToBytes(
    "608060405234801561001057600080fd5b5060405161001d9061007e565b604051809103906000f080158015610039573d6000803e3d6000fd5b506000806101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555061008a565b60978061021183390190565b610178806100996000396000f3fe60806040526004361061001e5760003560e01c80635c60da1b146100c7575b7ff2f626cd1d154bd3476dd84f60fcb3df6757a7685cb0afa181f43f6423eaf8cc5a6040518082815260200191505060405180910390a160008060009054906101000a900473ffffffffffffffffffffffffffffffffffffffff16905060405136600082376000803683855af450507ff2f626cd1d154bd3476dd84f60fcb3df6757a7685cb0afa181f43f6423eaf8cc5a6040518082815260200191505060405180910390a150005b3480156100d357600080fd5b506100dc61011e565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a7231582097002aaf5c7d7c386595e94c147702364b67536b0ee25c1e935ccb4748a41bf964736f6c634300051000326080604052348015600f57600080fd5b5060798061001e6000396000f3fe60806040527fe1f2fff362a4d171d703cc8eb57b9a51dfaa0c2eb2c706aa8ad32011aabf6d0b5a6040518082815260200191505060405180910390a16000604257fe5b00fea265627a7a7231582032423d6c27d3e2eb9e2afa78c5a73bbc112a163dd8f1d29f6a0b05237bfeac9964736f6c63430005100032"
  );
  env_t env = Utils::env();

  std::shared_ptr<Context> context = std::make_shared<Context>(
    env.chainId,
    env.blockNumber,
    env.timestamp,
    env.gasLimit,
    env.coinbase,
    env.difficulty,
    env.blockHash,
    uint256_t(0xea0e9a), /* address */
    uint256_t(0xf9313a), /* codeHash */
    uint256_t(0x193821), /* codeVersion */
    uint256_t(0xea0e9a), /* address */
    TestUtils::fromHex("cd1722f3947def4cf144679da39c4c32bdc35681"),
    uint256_t(0x1283fe), /* origin */
    150000,
    uint256_t(0),
    uint256_t(0),
    std::make_shared<bytes_t>(codeBytes),
    std::make_shared<bytes_t>()
  );

  std::shared_ptr<ExternalMock> external = std::make_shared<ExternalMock>();
  std::shared_ptr<std::vector<uint256_t>> stackItems = std::make_shared<std::vector<uint256_t>>();
  std::shared_ptr<StackMachine> stack = std::make_shared<StackMachine>(stackItems);
  std::shared_ptr<Gasometer> gasometer = std::make_shared<Gasometer>(context->gas);
  VM vm(stack, gasometer);
  std::shared_ptr<PendingState> pendingState = std::make_shared<PendingState>();
  std::shared_ptr<bytes_t> memoryBytes = std::make_shared<bytes_t>();
  std::shared_ptr<Memory> mem = std::make_shared<Memory>(memoryBytes);
  Operation operation = Operation();

  // when
  exec_result_t vm_result = vm.execute(0, operation, context, mem, pendingState, external);

  // then
  REQUIRE(ExecResult::DONE_RETURN == vm_result.first);

  NeedsReturn needsReturn = std::get<NeedsReturn>(vm_result.second);

  REQUIRE(true == needsReturn.apply);

  std::string code = mem->sliceAsString(needsReturn.offset, needsReturn.size);

  CHECK("60806040526004361061001e5760003560e01c80635c60da1b146100c7575b7ff2f626cd1d154bd3476dd84f60fcb3df6757a7685cb0afa181f43f6423eaf8cc5a6040518082815260200191505060405180910390a160008060009054906101000a900473ffffffffffffffffffffffffffffffffffffffff16905060405136600082376000803683855af450507ff2f626cd1d154bd3476dd84f60fcb3df6757a7685cb0afa181f43f6423eaf8cc5a6040518082815260200191505060405180910390a150005b3480156100d357600080fd5b506100dc61011e565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6000809054906101000a900473ffffffffffffffffffffffffffffffffffffffff168156fea265627a7a7231582097002aaf5c7d7c386595e94c147702364b67536b0ee25c1e935ccb4748a41bf964736f6c63430005100032" == 
    code
  );

  REQUIRE(1 == external->emplaceSpy.size());

  std::string subcontract1 = external->emplaceSpy[0].second;

  CHECK("60806040527fe1f2fff362a4d171d703cc8eb57b9a51dfaa0c2eb2c706aa8ad32011aabf6d0b5a6040518082815260200191505060405180910390a16000604257fe5b00fea265627a7a7231582032423d6c27d3e2eb9e2afa78c5a73bbc112a163dd8f1d29f6a0b05237bfeac9964736f6c63430005100032" == 
    subcontract1
  );
}