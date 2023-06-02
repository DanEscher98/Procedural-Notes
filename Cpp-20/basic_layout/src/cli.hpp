#include <cxxopts.hpp>
#include <fmt/core.h>
#include "lib.hpp"

class Args {
public:
  const std::string name;
  const int threads;
  const std::optional<int> optionalField;

  // Delete the copy constructor and assignment operator to prevent copying
  Args(const Args&) = delete;
  Args& operator=(const Args&) = delete;

  // This static method ensures that Args instance is initialized only once and is thread-safe
  static const Args& getInstance(int argc = 0, char* argv[] = nullptr) {
    static Args instance(argc, argv);
    return instance;
  }

private:
  // Make the constructor private so that only getInstance can access it
  Args(int argc, char* argv[]) :
    name(parseOption<std::string>("n,name", "Name to greet", "World", argc, argv)),
    threads(parseOption<int>("t,threads", "Number of threads", 4, argc, argv)),
    optionalField(parseOptionalOption("o,optional", "Optional integer field", argc, argv))
  {}

  // Helper function to setup and parse options
  template<typename T>
  auto setupAndParseOptions(const std::string& option, const std::string& description, int argc, char* argv[], const T& defaultValue = T()) {
    cxxopts::Options options("helloworld", fmt::format("A hello world program with options: {}", description));
    options.add_options()(option, description, cxxopts::value<T>()->default_value(defaultValue));
    options.add_options()("h,help", "Print usage");
    auto result = options.parse(argc, argv);

    if (result.count("help")) {
      fmt::print("{}", options.help());
      exit(0);
    }

    return result[option];
  }

  // Template function to parse options
  template<typename T>
  T parseOption(const std::string& option, const std::string& description, const T& defaultValue, int argc, char* argv[]) {
    return setupAndParseOptions<T>(option, description, argc, argv, defaultValue).as<T>();
  }

  // Function to parse optional integer option
  std::optional<int> parseOptionalOption(const std::string& option, const std::string& description, int argc, char* argv[]) {
    auto result = setupAndParseOptions<int>(option, description, argc, argv);
    if (result.count()) {
      return result.as<int>();
    } else {
      return std::nullopt;
    }
  }
};
