pragma solidity ^0.5.11;

contract Proposal {
  mapping (address => bool) approvals;
  bytes32 public approvalMask;
  bytes32 public approver1;
  bytes32 public approver2;
  bytes32 public target;
  
  constructor(address thirdParty) public {
    approver1 = bytes32(uint256(thirdParty));
    approver2 = bytes32(uint256(msg.sender));
    target = approver1 | approver2;
  }
  
  function approve(address approver) public {
    approvalMask |= bytes32(uint256(approver));
    approvals[approver] = true;
  }
  
  function isApproved() public view returns(bool) {
    return approvalMask == target;
  }
}