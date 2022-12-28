#include <iostream>
#include <string_view>
#include <optional>
#include "../extern/fmt/include/fmt/color.h"
#include "../extern/cxxopts/include/cxxopts.hpp"

struct Args {
  std::optional<std::string> name;
};

auto parseArgs(int argc, char* argv[]) -> Args {
  Args args;
  cxxopts::Options options(
    "basiclayout",
    "A simple program that reads flags from the command line"
  );
  options.add_options()
    ("n,name", "Name to greet", cxxopts::value<std::string>())
    ("h,help", "Print this help message");

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    std::exit(0);
  }
  if (result.count("name")) {
    args.name = result["name"].as<std::string>();
  }
  return args;
}

int main(int argc, char* argv[]) {
  auto args = parseArgs(argc, argv);

  if (args.name) {
    fmt::print(
      "Hello {}!\n",
      fmt::styled(*args.name, fmt::fg(fmt::color::green))
    );
  } else {
    fmt::print("Hello world!\n");
  }

  return 0;
}
