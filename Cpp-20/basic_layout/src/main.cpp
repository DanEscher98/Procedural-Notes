#include "lib.hpp"
#include "cli.hpp"
#include "utils.hpp"

int main(int argc, char* argv[]) {
  Args& args = Args::getInstance(argc, argv);

  fmt::print("Hi there {}!", fmt::format(fg(fmt::color::green), "{}", args.name));

  write_file(args.threads);
  return 0;
}
