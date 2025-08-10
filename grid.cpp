#include "grid.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


grid::grid(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;

    // Fill entire grid with dead cells
    for (int r = 0; r < m_rows; ++r) {
        std::vector<cell> append_row;
        for (int c = 0; c < m_cols; ++c) {
            append_row.push_back(cell(false, r, c));
        }

        m_grid.push_back(append_row);
    }

    return;
}

grid::~grid() {}

void grid::update_grid() {
    for (int r = 0; r < this->m_rows; ++r) {
        for (int c = 0; c < this->m_cols; ++c) {
            this->m_grid[r][c].update_state();
        }
    }
    return;
}

// Marks cells as alive according to a .txt file that is read line by line
void grid::populate(std::string filename) {
    std::ifstream file_in(filename);

    if (!file_in.is_open()) {
        std::cout << "ERROR: Unable to open file.\n";
        return;
    }

    std::string line;
    while (std::getline(file_in, line)) { // Iterate through every line and mark
                                          // alive if it's a valid coord
        std::stringstream coord(line);
        int row;
        int col;

        if (!(coord >> row >> col)) {
            std::cout << "ERROR: Error parsing line: " << line << std::endl;
            return;
        }

        if (row < 0 || row >= m_rows || col < 0 || col >= m_cols) {
            std::cout << "ERROR: Out of bounds coordinate: " << line
                      << std::endl;
            return;
        }

        this->m_grid[row][col].alive();
    }

    update_grid();

    file_in.close();

    return;
}

// (int) Return the number of cells that are alive and neighboring the cell at
// coords (row, col) Returns -1 upon error
int grid::census(int row, int col) {
    if (row < 0 || row > m_rows - 1 || col < 0 || col > m_cols - 1) {
        return -1;
    }

    auto cell_alive = [this](int r, int c) {
        return this->m_grid[r][c].state();
    };

    // (int) Returns the number of alive cells among (r, c - 1), (r, c), and (r,
    // c + 1) in this->m_grid
    auto census_row = [this, cell_alive](int r, int c) {
        int counter = 0;

        if (c > 0 && cell_alive(r, c - 1)) { // left cell
            ++counter;
        }

        if (cell_alive(r, c)) { // middle cell
            ++counter;
        }

        if ((c < this->m_cols) && cell_alive(r, c + 1)) { // right cell
            ++counter;
        }

        return counter;
    };

    int num_alive = 0;

    if (row > 0) {
        num_alive += census_row(row - 1, col);
    }

    num_alive += census_row(row, col);
    if (cell_alive(row, col)) {
        --num_alive;
    }

    if (row < this->m_rows - 1) {
        num_alive += census_row(row + 1, col);
    }

    return num_alive;
}

// Print entire grid.
// For every cell printed, "O" means alive and "." means dead
void grid::print() {
    for (int r = 0; r < this->m_rows; ++r) {
        for (int c = 0; c < this->m_cols; ++c) {
            (this->m_grid[r][c].state()) ? std::cout << "O" : std::cout << ".";
        }
        std::cout << "\n";
    }

    return;
}
