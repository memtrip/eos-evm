cmake_minimum_required(VERSION 3.5)

project(evm)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)
include(EosioWasmToolchain)

add_subdirectory(deps/intx)
link_libraries(intx)

add_subdirectory(deps/keccak)
link_libraries(keccak)

add_subdirectory(deps/secp256k1)
link_libraries(secp256k1)

file(GLOB SOURCES "src/*.cpp")

add_library(evm STATIC
  ${SOURCES}
)

target_include_directories(evm
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(evm PRIVATE HAVE_CONFIG_H=1)