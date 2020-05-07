pragma solidity ^0.5.11;

contract LongByteArray {
    bytes s;
    constructor() public {
        s.length = 32 * 4;
        s[31] = bytes1(uint8(0x1));
        s[63] = bytes1(uint8(0x2));
        s[95] = bytes1(uint8(0x3));
        s[127] = bytes1(uint8(0x4));
    }
}