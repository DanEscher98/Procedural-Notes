#include "lib.hpp"
#include "cli.hpp"
#include "utils.hpp"

int main(int argc, char* argv[]) {
  Args& args = Args::getInstance(argc, argv);

  fmt::print("Hi there {}!\n",
             fmt::format(fg(fmt::color::green), "{}", args.name)
  );

  write_file(args.threads);

  Args& args_1 = Args::getInstance();
  fmt::print("Singleton {} = {}!\n",
             fmt::format(fg(fmt::color::cyan), "{}", args_1.name),
             fmt::format(fg(fmt::color::aqua), "{}", args.name)
  );

  return 0;
}
