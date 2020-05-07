pragma solidity ^0.5.11;


contract BasicToken {
    mapping(address => uint256) balances;

    constructor() public {
        balances[msg.sender] = 15000000;
    }

    function transfer(address recipient, uint256 value) public {
        balances[msg.sender] -= value;
        balances[recipient] += value;
    }

    function balanceOf(address account) public view returns (uint256) {
        return balances[account];
    }
}
