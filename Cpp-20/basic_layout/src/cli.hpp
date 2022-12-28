#include <iostream>
#include <optional>

#include "../extern/fmt/include/fmt/color.h"
#include "../extern/cxxopts/include/cxxopts.hpp"


struct Args {
  std::optional<std::string> name;
};

auto parseArgs(int argc, char* argv[]) -> Args;
