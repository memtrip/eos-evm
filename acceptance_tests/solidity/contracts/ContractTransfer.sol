pragma solidity ^0.5.11;

import "./PayableConstructor.sol";
import "./PayableFallbackContract.sol";

contract ContractTransfer {
  uint seedAmount;
  PayableConstructor child1;
  PayableFallbackContract child2;

  constructor() public payable {
    seedAmount = msg.value;
    child1 = (new PayableConstructor).value(seedAmount)();
    child2 = new PayableFallbackContract();
  }

  function transfer() public {
    child1.transfer(address(uint160(address(child2))), seedAmount);
  }

  function child2Balance() public returns(uint) {
    return child2.balance();
  }
}