#include <mutex>
#include <thread>
#include <fstream>
#include <vector>
#include <random>
#include "lib.hpp"

namespace {
  // A private function to return random alphanumeric strings
  auto random_string(int size) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, 35);
  
    std::string line;
    for (int j = 0; j < size; ++j) {
      int c = uni(rng);
      if (c < 10) {
        line.push_back(c + '0');
      } else {
        line.push_back(c - 10 + 'A');
      }
    }
    return line;
  }
}

int write_file(int num_threds) {
  auto file = std::make_shared<std::mutex>();
  std::vector<std::thread> threads;
  std::ofstream ofs("data/output.txt");

  if (!ofs) {
      fmt::print("Failed to open the file\n");
      return 1;
  }

  for (int i = 0; i < num_threds; ++i) {
    threads.emplace_back([&, i]() {
      std::lock_guard<std::mutex> lock(*file);
      ofs << fmt::format("Thread {}: {}\n", i, random_string(16));
    });
  }

  for (auto& thread : threads) {
    thread.join();
  }

  return 0;
}
