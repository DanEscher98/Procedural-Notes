# A Basic C++20 Template

## directory layout
```
 .
├──  build                 # CMake produced files
├──  data                  # files/data to be used by the program
├──  docs                  # Doxygen output
├──  extern                # manual downloaded libraries
├──  target                # binary outputs
├──  compile_commands.json # file to get LSP completitions
├──  CMakeLists.txt        # the CMake config file
├──  Doxygen
├──  Justfile              # a convienent set of commands
└──  src
   ├──  main.cpp
   ├──  lib.hpp
   ├──  cli.hpp            # defined an Args class, with `cxxopts`
   ├──  utils.cpp
   ├──  utils.hpp
   └──  test.cpp           # a simple test using `gtest`
```

## libraries included
- [fmt](https://fmt.dev/latest/index.html): a modern formatting library
- [cxxotps](https://github.com/jarro2783/cxxopts): a lightweight parsing library for command line arguments
- [googletest](https://google.github.io/googletest/): the Google's testing framework
- [json](https://json.nlohmann.me/): a modern library to handle `json` files

## tools used for this worklfow
- [Cmake](https://cmake.org/cmake/help/latest/guide/tutorial/index.html): a build system generator for `C++`
- [`just`](https://just.systems/man/en/): a handy way to save and run project-specific commands
- [Clang](https://clang.llvm.org/docs/UsersManual.html): a `C` language family frontend for `LLVM`
- [Doxygen](https://www.doxygen.nl/manual/starting.html): a documentation generator and static analysis tool
