cmake_minimum_required(VERSION 3.5)

project(eos_evm)

include(ExternalProject)
# if no cdt root is given use default path
if(EOSIO_CDT_ROOT STREQUAL "" OR NOT EOSIO_CDT_ROOT)
  find_package(eosio.cdt)
endif()

ExternalProject_Add(
  eos_evm
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/src
  CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=${EOSIO_CDT_ROOT}/lib/cmake/eosio.cdt/EosioWasmToolchain.cmake
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  TEST_COMMAND ""
  INSTALL_COMMAND ""
  BUILD_ALWAYS 1
)