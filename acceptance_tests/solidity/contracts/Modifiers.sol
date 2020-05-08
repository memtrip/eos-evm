pragma solidity ^0.5.11;

contract Modifiers {

  bool locked = false;

  modifier greaterThan(uint value, uint limit) {
    if(value <= limit) { assert(false); }
    _;
  }

  modifier lock() {
    if (locked) {
      locked = true;
      _;
      locked = false;
    }
  }

  function g(uint a) public greaterThan(a, 10) {}
  function refund() public lock {
    msg.sender.send(0);
  }
}