#include "grid.h"
#include <iostream>

int main() {
  grid test(10, 10);

  test.mark(0, 0, true);
  test.mark(0, 1, true);
  test.mark(0, 2, true);
  test.mark(1, 0, true);
  test.mark(1, 2, true);
  test.mark(2, 0, true);
  test.mark(2, 1, true);
  test.mark(2, 2, true);

  auto num_alive = [&test](int row, int col) {
    std::cout << "Number of cells alive at (" << row << ", " << col << "): ";
    std::cout << test.census(row, col) << std::endl;
  };

  num_alive(1, 1);
  num_alive(1, 2);
  num_alive(0, 0);
  num_alive(9, 9);
  num_alive(0, 9);
  num_alive(9, 0);

  test.print();
  return 0;
}
