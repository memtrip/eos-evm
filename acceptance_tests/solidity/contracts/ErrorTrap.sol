pragma solidity ^0.5.11;

contract ErrorTrap {
    function foo(uint a) public pure returns(string memory, uint) {
        uint nullReturn;
        if(a < 100) {
            return('Too small', nullReturn);
        }
        uint b = 5;
        return ('', b);
    }
}