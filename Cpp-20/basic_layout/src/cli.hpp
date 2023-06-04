#include <cxxopts.hpp>
#include <fmt/core.h>
#include "lib.hpp"

class Args {
public:
  std::string name;
  int threads;
  std::optional<int> optionalField;

  // Delete the copy constructor and assignment operator to prevent copying
  Args(const Args&) = delete;
  Args& operator=(const Args&) = delete;

  static Args& getInstance(int argc = 0, char* argv[] = nullptr) {
    static Args instance(argc, argv);
    return instance;
  }

private:
  // Make the constructor private so that only getInstance can access it
  Args(int argc, char* argv[]) {
    cxxopts::Options options("helloworld", "A hello world program");

    options.add_options()
      ("n,name", "Name to greet", cxxopts::value<std::string>()->default_value("World"))
      ("t,threads", "Number of threads", cxxopts::value<int>()->default_value("4"))
      ("o,optional", "Optional integer field", cxxopts::value<int>())
      ("h,help", "Print usage")
    ;

    auto result = options.parse(argc, argv);
    if (result.count("help")) {
      fmt::print("{}", options.help());
      exit(0);
    }

    name = result["name"].as<std::string>();
    threads = result["threads"].as<int>();

    // If the optional field was given, store its value
    if (result.count("optional")) {
      optionalField = result["optional"].as<int>();
    }
  }
};
