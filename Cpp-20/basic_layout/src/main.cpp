#include "cli.hpp"
#include "lib.hpp"

#include <vector>
#include <ranges>


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

  std::vector<std::thread> threads;
  for (int i=0; i < args.num; i++) {
    threads.push_back(std::thread(say_hello, i+1));
  }

  std::ranges::for_each(threads, [](auto& t) { t.join(); });
  fmt::print("All threads completed.\n");

  return 0;
}
