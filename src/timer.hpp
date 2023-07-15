#pragma once
#include <chrono>
#include <cstdio>

class Timer final {

  Timer(Timer &&other) noexcept = default;
  Timer(const Timer &other) = delete;
  Timer &operator=(const Timer &other) = delete;

private:
  // run program
  std::chrono::_V2::system_clock::time_point begin;

  // stop program
  std::chrono::_V2::system_clock::time_point end;

  // duration
  std::chrono::duration<float> duration;

public:
  Timer() = default;
  ~Timer() = default;
  void start();
  void stop();
};