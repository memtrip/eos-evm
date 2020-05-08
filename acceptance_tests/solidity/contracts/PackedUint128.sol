pragma solidity ^0.5.11;

contract PackedUint128 {
    uint128[] s;
    constructor() public {
        s.length = 4;
        s[0] = 0xAA;
        s[1] = 0xBB;
        s[2] = 0xCC;
        s[3] = 0xDD;
    }
}