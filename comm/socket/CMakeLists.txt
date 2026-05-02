cmake_minimum_required(VERSION 4.0)
project(comm_socket C)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SOCKET_SRCS
    ${SRC_DIR}/tcp_socket_conn.c
)

add_executable(tcp_client
    ${SRC_DIR}/tcp_client.c
    ${SOCKET_SRCS}
)

add_executable(tcp_server
    ${SRC_DIR}/tcp_server.c
    ${SOCKET_SRCS}
)

# Include local headers
target_include_directories(tcp_client PRIVATE ${INC_DIR})
target_include_directories(tcp_server PRIVATE ${INC_DIR})

