pragma solidity ^0.5.11;

import "./Child.sol";

contract Factory {
  struct ChildData {
    uint[] amounts;
  }
  mapping (address => ChildData) listOfData;

  function set(uint[] memory _amounts) public {
    listOfData[msg.sender] = ChildData(_amounts);
  }

  function make() public returns(address) {
    Child child = new Child();
    child.init(listOfData[msg.sender].amounts);
    return address(child);
  }
}