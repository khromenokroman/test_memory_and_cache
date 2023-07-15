#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstdint>

class Timer {
private:
  // run program
  std::chrono::_V2::system_clock::time_point start;

  // stop program
  std::chrono::_V2::system_clock::time_point end;

  // duration
  std::chrono::duration<float> duration;

public:
  Timer() {
    printf("Timer is started...\n");
    start = std::chrono::high_resolution_clock::now();
  }
  ~Timer() {
    printf("Timer is stoped...\n");
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    printf("Func is running %f\n", duration.count());
		printf("--------------------\n");
  }
};

// fill array
void fill_array(long long *array, long long size) {

  printf("Fill array...\n");
  Timer t;
  for (long long i = 0; i < size; i++) {
    array[i] = std::rand() % 10;
  }
}

// show array easy
inline void show_array_easy(const long long *const array, const long long rows,
                            const long long columns) noexcept {

  printf("Print array in order easy:\n");

  long long size = rows * columns;
  for (long long i = 0; i < size; i++) {
    printf("%llu\t", array[i]);
  }
  printf("\n");
  printf("--------------------\n");
}

// show array in order
inline void show_array_in_order(const long long *const array, const long long rows,
                                const long long columns) noexcept {

  printf("Print array in order:\n");

  for (long long r = 0; r < rows; r++) {
    for (long long c = 0; c < columns; c++) {
      printf("%llu\t", array[r * rows + c]);
    }
  }
  printf("\n");
  printf("--------------------\n");
}

// show array in 2d
inline void show_array_in_2d_mass(const long long *const array, const long long rows,
                                  const long long columns) noexcept {

  printf("Print array in 2d:\n");
  long long size = rows * columns;
  for (long long i = 0; i < size; i++) {
    if ((i % columns == 0) & (i != 0))
      printf("\n");
    printf("%llu\t", array[i]);
  }
  printf("\n");
  printf("--------------------\n");
}

// show array in columns
inline void show_array_in_columns(const long long *const array, const long long rows,
                                  const long long columns) noexcept {

  printf("Print array in columns:\n");

  for (long long c = 0; c < columns; c++) {
    for (long long r = 0; r < rows; r++) {
      printf("%llu\t", array[r * rows + c]);
    }
  }
  printf("\n");
  printf("--------------------\n");
}

// sum array in order
inline void sum_array_in_order(const long long *const array, const long long rows,
                               const long long columns) noexcept {

  printf("Sum array in order...\n");

	Timer t;
  long long sum = 0;

  for (long long r = 0; r < rows; r++) {
    for (long long c = 0; c < columns; c++) {
      sum += array[r * rows + c];
    }
  }

  printf("Sum full elements is %llu\n", sum);
}

// sum array in columns
inline void sum_array_in_columns(const long long *const array, const long long rows,
                                 const long long columns) noexcept {

  printf("Sum array in columns:\n");

	Timer t;
  long long sum = 0;

  for (long long c = 0; c < columns; c++) {
    for (long long r = 0; r < rows; r++) {
      sum += array[r * rows + c];
    }
  }

  printf("Sum full elements is %llu\n", sum);
}

int main() {

  constexpr long long ROWS = 20000;
  constexpr long long COLUMNS = 20000;
  constexpr long long MAX_SIZE = ROWS * COLUMNS;

  // int array
  long long  *array = new long long[MAX_SIZE];

  printf("size array %llu bytes\n",MAX_SIZE);

  fill_array(array, MAX_SIZE);

  // show_array_easy(array, ROWS, COLUMNS);
  // show_array_in_2d_mass(array, ROWS, COLUMNS);

  // show_array_in_order(array, ROWS, COLUMNS);
  // 
  (array, ROWS, COLUMNS);

  // show_array_in_columns(array, ROWS, COLUMNS);
  sum_array_in_columns(array, ROWS, COLUMNS);
  delete [] array;
}
