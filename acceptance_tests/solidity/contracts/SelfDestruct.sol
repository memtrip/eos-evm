pragma solidity ^0.5.11;

contract SelfDestruct {

  uint storage1;
  uint storage2;
  uint storage3;

  constructor() public payable {
    require(msg.value >= 1000000000000000);
    storage1 = 1;
    storage2 = 2;
    storage3 = 3;
  }

  function balance() public view returns (uint) {
    return address(this).balance;
  }

  function exit() public {
    return selfdestruct(msg.sender);
  }
}