pragma solidity ^0.5.11;

contract PackedBytes {
    bytes s;
    constructor() public {
        s.push(0xAA);
        s.push(0xBB);
        s.push(0xCC);
    }
}