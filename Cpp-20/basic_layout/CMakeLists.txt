cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Os")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/target)


project(basiclayout CXX)
# Set the source files and executable
add_executable(basiclayout src/main.cpp src/cli.cpp)

# Add cxxopts library
add_subdirectory(extern/cxxopts)
add_subdirectory(extern/fmt)

# Add main.cpp and include directory
target_include_directories(basiclayout PRIVATE extern)

# Link cxxopts library to basiclayout target
target_link_libraries(basiclayout PRIVATE cxxopts fmt)
