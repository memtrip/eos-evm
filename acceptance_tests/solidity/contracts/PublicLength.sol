pragma solidity ^0.5.11;

import "./LengthValue.sol";

contract PublicLength {
  LengthValue lengthValue;

  constructor() public {
    lengthValue = new LengthValue();
  }

  function test() public view returns (uint) {
    return lengthValue.getNumLength();
  }
}