#include <evm/return_data.h>

ReturnData::ReturnData() {
  mem = bytes_t();
  offset = 0;
  size = 0;
}

 void ReturnData::set(bytes_t memArg, uint16_t offsetArg, uint16_t sizeArg) {
   offset = offsetArg;
   size = sizeArg;
   mem.clear();
   mem.insert(mem.begin(), memArg.begin(), memArg.end());
 }