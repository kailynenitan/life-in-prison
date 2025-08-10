#include "grid.h"

#include <iostream>

int main() {
    grid testgrid(10, 10);

    testgrid.populate("input.txt");
    testgrid.print();

    for (int i = 0; i < 5; ++i) {
        std::cout << "\n\n";
        testgrid.update();
        testgrid.refresh();
        testgrid.print();
    }

    return 0;
}
