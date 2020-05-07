pragma solidity ^0.5.11;

contract Child {
  uint[] public amounts;

  function init(uint[] memory _amounts) public {
    amounts = _amounts;
  }
}