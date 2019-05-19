## i have cmake 3.5
cmake_minimum_required(VERSION 3.10)
project(cpp_zmq)

## use this to globally use C++11 with in our project
set(CMAKE_CXX_STANDARD 11)

## load in pkg-config support
find_package(PkgConfig)
## use pkg-config to get hints for 0mq locations
pkg_check_modules(PC_ZeroMQ QUIET zmq)

## use the hint from above to find where 'zmq.hpp' is located
find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
        )

## use the hint from about to find the location of libzmq
find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
        )

set(SOURCE_FILES main.cpp)
add_executable(cpp_zmq ${SOURCE_FILES})

## add the include directory to our compile directives
target_include_directories(cpp_zmq PUBLIC ${ZeroMQ_INCLUDE_DIR})
## at the 0mq library to our link directive
target_link_libraries(cpp_zmq PUBLIC ${ZeroMQ_LIBRARY})