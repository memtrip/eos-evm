pragma solidity ^0.5.11;

contract Balance {

  constructor() public payable {
  }

  function getBalance() public returns(uint) {
    return address(this).balance;
  }

  function getAddressBalance(address value) public returns(uint) {
    return address(value).balance;
  }

  function getSenderBalance() public payable returns(uint) {
    return msg.sender.balance;
  }
}