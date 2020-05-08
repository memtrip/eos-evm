pragma solidity ^0.5.11;

contract SelfDestruct {

  constructor() public payable {
    require(msg.value >= 1000000000000000);
  }

  function balance() public view returns (uint) {
    return address(this).balance;
  }

  function exit() public {
    return selfdestruct(msg.sender);
  }
}