pragma solidity ^0.5.11;

import "./MappingValue.sol";

contract PublicMapping {
    // insert address of deployed First here
    MappingValue mappingValue;

    constructor() public {
      mappingValue = new MappingValue();
    }

    function get() public view returns(uint) {
        return mappingValue.objects(0);
    }
}