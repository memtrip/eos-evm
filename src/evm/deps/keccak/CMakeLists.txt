cmake_minimum_required(VERSION 3.5)

project(keccak)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)
include(EosioWasmToolchain)

file(GLOB SOURCES "src/*.cpp")

add_library(keccak STATIC
  ${SOURCES}
)

target_include_directories(keccak
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(keccak PRIVATE HAVE_CONFIG_H=1)