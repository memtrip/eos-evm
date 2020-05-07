pragma solidity ^0.5.11;

contract Value {
  string public word;

  function setMsg(string memory whatever) public payable {
    word = whatever;
  }
}