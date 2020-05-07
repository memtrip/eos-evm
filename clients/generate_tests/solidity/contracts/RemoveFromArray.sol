pragma solidity ^0.5.11;

contract RemoveFromArray {
  uint[] public values;

  constructor() public {
  }

  function find(uint value) private view returns(uint) {
    uint i = 0;
    while (values[i] != value) {
      i++;
    }
    return i;
  }

  function removeByValue(uint value) private {
    uint i = find(value);
    removeByIndex(i);
  }

  function removeByIndex(uint i) private {
    while (i<values.length-1) {
      values[i] = values[i+1];
      i++;
    }
    values.length--;
  }

  function getValues() private view returns(uint[] memory) {
    return values;
  }

  function test() public returns(uint[] memory) {
    values.push(10);
    values.push(20);
    values.push(30);
    values.push(40);
    values.push(50);
    removeByValue(30);
    return getValues();
  }
}