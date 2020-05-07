pragma solidity ^0.5.11;

contract LengthValue {
  uint[] public nums;

  constructor() public {
    nums.push(10);
    nums.push(20);
    nums.push(30);
    nums.push(40);
    nums.push(50);
  }

  function getNumLength() public view returns(uint) {
    return nums.length;
  }
}
