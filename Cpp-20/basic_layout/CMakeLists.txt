cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME mytemplate)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Os")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/target)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(BUILD_TESTING "Build tests" OFF)

# Set the source files and executable
add_executable(${PROJECT_NAME}
  src/main.cpp
  src/utils.cpp
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/extern
  ${CMAKE_CURRENT_SOURCE_DIR}/extern/cxxopts/include
  ${CMAKE_CURRENT_SOURCE_DIR}/extern/fmt/include
)

add_subdirectory(extern/cxxopts)
add_subdirectory(extern/fmt)

# include(FetchContent)
# FetchContent_Declare(
#   json
#   URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
#   DOWNLOAD_EXTRACT_TIMESTAMP true
# )
# FetchContent_MakeAvailable(json)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
  cxxopts
  fmt
  #  nlohmann_json::nlohmann_json
)

if(BUILD_TESTING)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
  )
  
  # For Windows: Prevent overriding the parent projects compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
  
  enable_testing()
  add_executable(unittests src/test.cpp)
  target_link_libraries(unittests GTest::gtest_main)
endif()
