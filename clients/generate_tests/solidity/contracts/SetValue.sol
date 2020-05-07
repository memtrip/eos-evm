pragma solidity ^0.5.11;

import "./Value.sol";

contract SetValue{
    constructor() public {
        Value v = new Value();
        v.setMsg.value(0)("test");
    }
}