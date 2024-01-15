cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME mytemplate)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Os")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/target)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(BUILD_TESTING "Build tests" OFF)

add_executable(${PROJECT_NAME}
  src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/extern
  ${CMAKE_CURRENT_SOURCE_DIR}/extern/reactphysics3d
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  reactphysics3d
)
