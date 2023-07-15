#include "matrix.hpp"
#include "timer.hpp"
#include <exception>

int main() {

  try {
    Matrix array;

    // array.show_array();
    // array.sum_array_in_order();
    array.sum_array_in_columns();
  } catch (std::exception const &ex) {
    printf("Ошибка при работе с классом!\n");
  } catch (...) {
    printf("Неожиданная ошибка!\n");
  }
}
