#include "lib.hpp"
#include "../extern/fmt/include/fmt/color.h"

void say_hello(int thread_num) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(10, 100);
  int delay = dis(gen);

  std::this_thread::sleep_for(std::chrono::milliseconds(delay));
  fmt::print("The thread {} slept {} millis\n",
             fmt::styled(thread_num, fmt::fg(fmt::color::green)),
             fmt::styled(delay, fmt::fg(fmt::color::blue)));
}
