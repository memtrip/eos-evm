cmake_minimum_required(VERSION 3.5)

project(eos_evm)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_subdirectory(evm)
link_libraries(evm)

add_contract(eos_evm eos_evm eos_evm.cpp)

target_include_directories( 
  eos_evm PUBLIC 
  ${CMAKE_SOURCE_DIR}/../include 
)
#target_ricardian_directory( eos_evm ${CMAKE_SOURCE_DIR}/../ricardian )
