pragma solidity ^0.5.11;

contract Tuple {
  function tuple() private pure returns(uint, string memory) {
    return (1, "Hi");
  }

  function getOne() public pure returns(uint) {
    uint a;
    (a,) = tuple();
    return a;
  }
}