cmake_minimum_required(VERSION 3.5)

project(intx)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)
include(EosioWasmToolchain)

add_library(intx STATIC
  src/div.cpp
  src/div.hpp
)

add_library(intx::intx ALIAS intx)

target_include_directories(intx
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(intx PRIVATE HAVE_CONFIG_H=1)