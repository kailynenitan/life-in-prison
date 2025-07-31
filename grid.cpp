#include "grid.h"

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

  test.print();
  return 0;
}
