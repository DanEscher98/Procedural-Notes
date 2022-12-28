#include "cli.hpp"

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
