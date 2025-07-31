#include "grid.h"
#include <iostream>

int main() {
  grid testgrid(10, 10);

  testgrid.populate("input.txt");

  testgrid.print();
  return 0;
}
