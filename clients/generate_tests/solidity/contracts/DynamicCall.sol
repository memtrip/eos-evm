pragma solidity ^0.5.11;

contract DynamicCall {

  uint x = 0;

  function foo(uint _x) public {
    x = 10 + _x;
  }

  function bar() public returns(uint) {
    (bool a, bytes memory result) = address(this).call(abi.encode(bytes4(keccak256('foo(uint256)')), uint256(1)));
    return x; // returns 11
  }
}