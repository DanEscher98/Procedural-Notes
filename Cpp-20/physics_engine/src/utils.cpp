#include <mutex>
#include <thread>
#include <fstream>
#include <vector>
#include <random>
#include <memory>
#include <nlohmann/json.hpp>
#include <SDL.h>
#include "lib.hpp"

using json = nlohmann::json;

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

int write_file(int num_threads) {
  auto data_mutex = std::make_shared<std::mutex>();
  std::vector<std::thread> threads;
  json data;

  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back([&, i]() {
      auto ret_data = random_string(16);

      std::lock_guard<std::mutex> lock(*data_mutex);
      data["threads"][fmt::to_string(i)] = std::move(ret_data);
    });
  }

  for (auto& thread : threads) {
    thread.join();
  }

  std::ofstream data_file("data/output.json");
  if (!data_file.is_open()) {
      fmt::print("Failed to open the file\n");
      return 1;
  }
  data_file << data.dump(4);

  return 0;
}

int mock(int num) {
  return num * 2;
}
