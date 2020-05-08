pragma solidity ^0.5.11;

import "./PayableConstructor.sol";

contract PayableFactory {
  function payMake() payable public returns(uint) {
    PayableConstructor child = (new PayableConstructor).value(msg.value)();
    return child.balance();
  }

  function make(uint value) public returns(uint) {
    PayableConstructor child = (new PayableConstructor).value(value)();
    return child.balance();
  }
}