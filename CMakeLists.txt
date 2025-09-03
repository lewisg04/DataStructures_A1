# CMakeList.txt : CMake project for DataStructures_A1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project ("DataStructures_A1")
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/incl)
#main executable
add_executable (main src/main.cpp src/prime.cpp incl/prime.hpp)

# Add test executable
add_executable (tests tests/test.cpp src/prime.cpp incl/prime.hpp incl/catch.hpp)


# TODO: Add tests and install targets if needed.
