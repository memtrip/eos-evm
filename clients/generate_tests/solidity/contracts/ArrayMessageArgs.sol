pragma solidity ^0.5.11;

import "./A.sol";


contract ArrayMessageArgs {
    uint256[] numbers;

    function makeA() public returns (uint256) {
        numbers.push(10);

        A a = new A(numbers);

        return a.numbers(0);
    }
}
