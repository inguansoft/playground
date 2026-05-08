cmake_minimum_required(VERSION 4.0)
project(bitwise C)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(INC_DIR 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(bitwise_data ${SRC_DIR}/bitwise_data.c)
add_executable(bitwiseop ${SRC_DIR}/bitwiseop.c)
add_executable(reg_bit ${SRC_DIR}/reg_bit.c)

# Include local headers
target_include_directories(bitwise_data PRIVATE ${INC_DIR})
target_include_directories(bitwiseop PRIVATE ${INC_DIR})
target_include_directories(reg_bit PRIVATE ${INC_DIR})