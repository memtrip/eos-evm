
pragma solidity ^0.5.11;

contract Frame6 {
  function next(uint value) public {
    log0(bytes32(uint256(msg.sender)));
  }
}

contract Frame5 {
  function next(uint value) public {
    Frame6 frame = new Frame6();
    (bool success, bytes memory data) = address(frame).delegatecall(
      abi.encodeWithSignature("next(uint256)", 1)
    );
  }
}

contract Frame4 {
  function next(uint value) public {
    Frame5 frame = new Frame5();
    (bool success, bytes memory data) = address(frame).delegatecall(
      abi.encodeWithSignature("next(uint256)", 1)
    );
  }
}

contract Frame3 {
  function next(uint value) public {
    Frame4 frame = new Frame4();
    (bool success, bytes memory data) = address(frame).delegatecall(
      abi.encodeWithSignature("next(uint256)", 1)
    );
  }
}

contract Frame2 {
  function next(uint value) public {
    Frame3 frame = new Frame3();
    (bool success, bytes memory data) = address(frame).delegatecall(
      abi.encodeWithSignature("next(uint256)", 1)
    );
  }
}

contract Frame1 {
  function next(uint value) public {
    Frame2 frame = new Frame2();
    (bool success, bytes memory data) = address(frame).delegatecall(
      abi.encodeWithSignature("next(uint256)", 1)
    );
  }
}

contract Frame {
  function next(uint value) public {
    Frame1 frame = new Frame1();
    (bool success, bytes memory data) = address(frame).delegatecall(
      abi.encodeWithSignature("next(uint256)", 1)
    );
  }
}

contract StackDepth {
  function depthCharge() public {
    Frame frame = new Frame();
    (bool success, bytes memory data) = address(frame).delegatecall(
      abi.encodeWithSignature("next(uint256)", 1)
    );
  }
}