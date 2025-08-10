#include "grid.h"
#include <iostream>

int main() {
    grid testgrid(10, 10);

    testgrid.populate("input.txt");
    testgrid.print();

    std::cout << "\n";

    int row = 1;
    int col = 0;
    std::cout << "Number alive at (" << row << ", " << col
              << "): " << testgrid.census(row, col) << std::endl;

    return 0;
}
