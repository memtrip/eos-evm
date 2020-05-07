pragma solidity ^0.5.11;

contract SendEth {

  function send(address payable recipient) public {
    recipient.send(1 ether);
  }

  function callIgnoreResult(address payable recipient) public {
    recipient.send(1 ether);
  }

  function callWithResult(address payable recipient) public {
    bool success;
    (success,) = recipient.call.value(1 ether)("");
    if(!success) assert(false);
  }
}