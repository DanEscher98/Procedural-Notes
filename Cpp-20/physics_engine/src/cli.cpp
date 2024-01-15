#include "cli.hpp"

void version_info() {
  #ifdef __clang__
    auto compiler = "Clang";
    auto major = __clang_major__;
    auto minor = __clang_minor__;
    auto patchlevel = __clang_patchlevel__;
    auto cplusplus = __cplusplus;
  #elif defined(__GNUC__)
    auto compiler = "GCC";
    auto major = __GNUC__;
    auto minor = __GNUC_MINOR__;
    auto patchlevel = __GNUC_PATCHLEVEL__;
    auto cplusplus = __cplusplus;
  #else
    std::cout << "Compiler information not available." << std::endl;
    exit(1);
  #endif

  fmt::println("Compiler: {} {}.{}.{}", compiler, major, minor, patchlevel);
  fmt::println("Standard: C++ {}", cplusplus);
}

Args& Args::getInstance(int argc, char* argv[]) {
  static Args instance(argc, argv);
  return instance;
}

Args::Args(int argc, char* argv[]) {
  cxxopts::Options options("helloworld", "A hello world program");

  options.add_options()
    ("n,name", "Name to greet", cxxopts::value<std::string>()->default_value("World"))
    ("t,threads", "Number of threads", cxxopts::value<int>()->default_value("4"))
    ("o,optional", "Optional integer field", cxxopts::value<int>())
    ("h,help", "Print usage")
    ("version", "Version and compilation information")
  ;

  auto result = options.parse(argc, argv);
  if (result.count("help")) {
    fmt::print("{}", options.help());
    exit(0);
  }
  if (result.count("version")) {
    version_info();
    exit(0);
  }

  name = result["name"].as<std::string>();
  threads = result["threads"].as<int>();

  // If the optional field was given, store its value
  if (result.count("optional")) {
    optionalField = result["optional"].as<int>();
  }
}
