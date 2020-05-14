pragma solidity ^0.5.11;

contract Withdraw {

  constructor() public payable {
  }

  function withdraw() public {
    msg.sender.transfer(address(this).balance);
  }
}