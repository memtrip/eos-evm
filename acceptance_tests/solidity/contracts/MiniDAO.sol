pragma solidity ^0.5.11;

contract MiniDAO {
    mapping (address => uint) balances;

    function deposit() public payable {
        balances[msg.sender] += msg.value;
    }

    function balance() public view returns(uint) {
      return balances[msg.sender];
    }

    function withdraw(uint amount) public {
        if(balances[msg.sender] < amount) assert(false);
        bool status;
        bytes memory response;
        (status, response) = msg.sender.call.value(amount)("");
        if (status) {
          balances[msg.sender] -= amount;
        } else {
          assert(false);
        }
    }
}