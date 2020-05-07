pragma solidity ^0.5.11;

contract PayableConstructor {

  uint money;

  constructor() public payable {
    require(msg.value >= 1000000000000000);
    money = msg.value;
  }

  function balance() public view returns (uint) {
    return address(this).balance;
  }

  function getAddressPayable() public view returns (address payable) {
    return address(uint160(address(this)));
  }

  function transfer(address payable recipient, uint amount) public {
    assert(money >= amount);
    money -= amount;
    recipient.send(amount);
  }
}