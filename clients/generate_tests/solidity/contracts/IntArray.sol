pragma solidity ^0.5.11;


contract IntArray {
    uint256[5] numbers;

    function main() public returns (uint256[5] memory) {
        numbers[0] = 100;
        numbers[1] = 200;
        numbers[2] = 300;
        numbers[3] = 400;
        numbers[4] = 500;
        return numbers;
    }
}
