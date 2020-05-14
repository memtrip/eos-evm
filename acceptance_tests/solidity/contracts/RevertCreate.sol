pragma solidity ^0.5.11;

contract RevertMe {
  constructor() public payable {
  }
}

contract RevertCreateChild {

  RevertMe revertMe;

  constructor() public {
  }

  function create() public payable {
    revertMe = (new RevertMe).value(msg.value)();
    revert("do not create the RevertMe contract");
  }
}

contract RevertCreate {

  RevertCreateChild child;

  constructor() public payable {
    child = new RevertCreateChild();
  }

  function createChild() public {
    child.create.value(address(this).balance);
  }
}