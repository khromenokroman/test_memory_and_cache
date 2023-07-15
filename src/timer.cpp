#include "timer.hpp"

void Timer::start() {
  printf("Таймер запущен...\n");
  begin = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
  printf("Таймер остановлен!\n");
  end = std::chrono::high_resolution_clock::now();
  duration = end - begin;
  printf("Время выполнения %f сек.\n", duration.count());
  printf("--------------------\n");
}
