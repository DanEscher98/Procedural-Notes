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

  static Args& getInstance(int argc = 0, char* argv[] = nullptr);
private:
  // Make the constructor private so that only getInstance can access it
  Args(int argc, char* argv[]);
};
