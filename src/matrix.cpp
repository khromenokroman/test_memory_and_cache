#include "matrix.hpp"

Matrix::Matrix() {

  printf("Создаю массив на %llu байт...\n", MAX_SIZE);
  // Выделение на куче массива
  array = new long long[MAX_SIZE];

  printf("Массив создан!\n");
  printf("--------------------\n");
  fill_array();
  printf("--------------------\n");
}

Matrix::~Matrix() {

  // Очистка ресурсов
  delete[] array;

  printf("Ресурсы очищены!\n");
}

void Matrix::fill_array() {

  printf("Заполнение массива...\n");
  for (long long i = 0; i < MAX_SIZE; i++) {
    array[i] = std::rand() % 10;
  }
  printf("Массив заполнен!\n");
}

void Matrix::sum_array_in_columns() {
  printf("Суммирование по колонкам (прыжки по памяти)\n");

  timer.start();
  long long sum = 0;

  for (long long c = 0; c < COLUMNS; c++) {
    for (long long r = 0; r < ROWS; r++) {
      
      sum += array[r * ROWS + c];
    }
  }
  
  printf("Сумма всех элементов в массиве %llu\n", sum);
  timer.stop();
}

void Matrix::sum_array_in_order() {
  printf("Суммирование по порядку (последовательный доступ)\n");

  timer.start();
  long long sum = 0;

  for (long long r = 0; r < ROWS; r++) {
    for (long long c = 0; c < COLUMNS; c++) {
      sum += array[r * ROWS + c];
    }
  }
  
  printf("Сумма всех элементов в массиве %llu\n", sum);
  timer.stop();
}

void Matrix::show_array(){
  printf("Вывожу массив на экран:\n");

  for (long long r = 0; r < ROWS; r++) {
    for (long long c = 0; c < COLUMNS; c++) {
      printf("%llu\t", array[r * ROWS + c]);
    }
  }
  printf("\n");
  printf("--------------------\n");
}