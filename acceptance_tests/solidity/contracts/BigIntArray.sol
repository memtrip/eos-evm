pragma solidity ^0.5.11;


contract BigIntArray {
    uint256[] numbers;

    constructor(uint256[] memory _numbers) public {
        for (uint256 i = 0; i < _numbers.length; i++) {
            numbers.push(_numbers[i]);
        }
    }
}
