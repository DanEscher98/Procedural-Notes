#include "cli.hpp"

auto parseArgs(int argc, char* argv[]) -> Args {
  Args args;
  cxxopts::Options options(
    "basiclayout",
    "A simple program that reads flags from the command line"
  );
  options.add_options()
    ("n,name", "Name to greet", cxxopts::value<std::string>())
    ("t,threads", "Number of threads", cxxopts::value<int>())
    ("h,help", "Print this help message");

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    std::exit(0);
  }
  if (result.count("name")) {
    args.name = result["name"].as<std::string>();
  }
  if (result.count("threads")) {
    args.num = result["threads"].as<int>();
  } else {
    std::cout << options.help() << std::endl;
    std::exit(0);
  }
  return args;
}
