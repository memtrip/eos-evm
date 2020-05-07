pragma solidity ^0.5.11;


contract StringArray {
    string[] strings;

    constructor() public {
        strings.push("hi");
        strings.push("bye");
    }

    function bar() public view returns (string memory) {
        return strings[1];
    }
}
