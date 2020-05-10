pragma solidity ^0.5.11;

contract RevertChild {
  uint value;

  function setVars(uint valueArg) public {
    value = valueArg;
  }

  function setVarsRevert(uint valueArg) public {
    value = valueArg;
    revert("do not save this change");
  }

  function setVarsAssert(uint valueArg) public {
    value = valueArg;
    assert(false);
  }

  function setVarsRequire(uint valueArg) public {
    value = valueArg;
    assert(false);
  }

  function steal() public {
    selfdestruct(msg.sender);
  }
}

contract RevertStorage {
  uint value;

  RevertChild child;

  constructor() public {
    child = new RevertChild();
  }

  function setVars(uint value) public payable {
    (bool success, bytes memory data) = address(child).delegatecall(
      abi.encodeWithSignature("setVars(uint256)", value)
    );
  }

  function setVarsRevert(uint value) public payable {
    (bool success, bytes memory data) = address(child).delegatecall(
      abi.encodeWithSignature("setVarsRevert(uint256)", value)
    );
  }

  function setVarsAssert(uint value) public payable {
    (bool success, bytes memory data) = address(child).delegatecall(
      abi.encodeWithSignature("setVarsAssert(uint256)", value)
    );
  }

  function setVarsRequire(uint value) public payable {
    (bool success, bytes memory data) = address(child).delegatecall(
      abi.encodeWithSignature("setVarsRequire(uint256)", value)
    );
  }

  function dangerous() public {
    (bool success, bytes memory data) = address(child).delegatecall(
      abi.encodeWithSignature("steal()")
    );
  }
}