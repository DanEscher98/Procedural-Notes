cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME MyTemplate)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(${PROJECT_NAME} CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Os")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/target)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(BUILD_TESTING "Build tests" OFF)

# Set the source files and executable
include_directories(include)
add_executable(${PROJECT_NAME}
  src/main.cpp
  src/utils.cpp
  src/cli.cpp
)

include(FetchContent)

FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY  https://github.com/jarro2783/cxxopts.git
  GIT_TAG         v3.1.1
)

FetchContent_Declare(
  json
  GIT_REPOSITORY  https://github.com/nlohmann/json.git
  GIT_TAG         v3.11.3
)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY  https://github.com/fmtlib/fmt.git
  GIT_TAG         10.2.1
)

FetchContent_Declare(
  result
  GIT_REPOSITORY  https://github.com/bitwizeshift/result.git
  GIT_TAG         v1.0.0
) # NOTE: expect

FetchContent_Declare(
  glog
  GIT_REPOSITORY  https://github.com/google/glog.git
  GIT_TAG         v0.6.0
)

# sdl2
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL
    GIT_TAG         release-2.28.5
    GIT_PROGRESS    TRUE
)

# sdl2_image
FetchContent_Declare(
    SDL2_IMAGE
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL_image
    GIT_TAG         release-2.8.2 
    GIT_PROGRESS    TRUE
)

FetchContent_Declare(
    SDL2_TTF
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL_ttf
    GIT_TAG         release-2.20.2 
    GIT_PROGRESS    TRUE
)


FetchContent_MakeAvailable(fmt cxxopts json result glog SDL2 SDL2_IMAGE)

#set(SDL2IMAGE_INSTALL OFF)
set(BUILD_SHARED_LIBS FALSE)
set(SDL_LIBRARIES ${SDL_LIBRARIES} SDL2main SDL2 SDL2_image)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/extern
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
  cxxopts
  fmt
  nlohmann_json::nlohmann_json
  Result::Result
  glog::glog
  ${SDL_LIBRARIES}
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

  FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.6
  )
  FetchContent_MakeAvailable(catch2)
  
  enable_testing()
  add_executable(UnitTests tests/test.cpp src/utils.cpp)
  target_link_libraries(UnitTests PRIVATE
    fmt
    GTest::gtest_main
    Catch2::Catch2
    nlohmann_json::nlohmann_json
  )
  add_test(MyUnitTestBasic MyUnitTests)
endif()
