pragma solidity ^0.5.11;


contract A {
    uint256[] public numbers;

    constructor(uint256[] memory _numbers) public {
        for (uint256 i = 0; i < _numbers.length; i++) {
            numbers.push(_numbers[i]);
        }
    }

    function get() public view returns (uint256[] memory) {
        return numbers;
    }
}
