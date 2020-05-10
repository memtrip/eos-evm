pragma solidity ^0.5.11;

import "./SelfDestruct.sol";

contract SelfDestructChild {

  SelfDestruct child;

  constructor() payable public {
    child = (new SelfDestruct).value(msg.value)();
  }

  function exitChild() public {
    child.exit();
  }
}