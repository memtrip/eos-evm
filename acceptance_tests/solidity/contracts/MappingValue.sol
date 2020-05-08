pragma solidity ^0.5.11;

contract MappingValue {
  mapping(uint => uint) public objects;

  constructor() public {
    objects[0] = 42;
  }
}
