pragma solidity ^0.5.11;

contract PayableFallbackContract {

  uint money;

  function() external payable { 
    money += msg.value;
  }

  function balance() public view returns (uint) {
    return money;
  }
}