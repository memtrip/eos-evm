pragma solidity ^0.5.11;

import "./LengthValue.sol";

contract PublicLengthPersist {
  LengthValue lengthValue;
  uint value;

  constructor() public {
    lengthValue = new LengthValue();
  }

  function test() public {
    value = lengthValue.getNumLength();
  }
}