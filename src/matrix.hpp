#pragma once
#include "timer.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

class Matrix final {
  Matrix(Matrix &&other) noexcept = default;
  Matrix(const Matrix &other) = delete;
  Matrix &operator=(const Matrix &other) = delete;

private:
  const long long ROWS = 20000;
  const long long COLUMNS = 20000;
  const long long MAX_SIZE = ROWS * COLUMNS;
  Timer timer;

  void fill_array();

  long long *array = nullptr;

public:
  Matrix();
  ~Matrix();
  void show_array();
  
  void sum_array_in_order();
  void sum_array_in_columns();
};