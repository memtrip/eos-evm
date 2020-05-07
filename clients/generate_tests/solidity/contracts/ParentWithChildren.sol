pragma solidity ^0.5.11;

import "./Child.sol";

contract ParentWithChildren {
  struct ChildData {
    uint[] amounts;
  }
  mapping (address => ChildData) listOfData;

  Child public child0;
  Child public child1;
  Child public child2;

  constructor() public {
    child0 = new Child();
    child1 = new Child();
    child2 = new Child();
  }
}