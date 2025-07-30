#include <iostream>
#include <vector>

#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

class cell {
public:
  cell(bool alive, int row, int col) : m_alive{alive}, m_row{row}, m_col{col} {}

  ~cell() {}

  void print_state() {
    std::cout << "Cell is alive: ";
    std::cout << std::boolalpha;
    std::cout << this->m_alive << ".\n";
    return;
  }

  void alive() {
    this->m_alive = true;
    return;
  }

  void dead() {
    this->m_alive = false;
    return;
  }

  bool state() { return this->m_alive; }

private:
  bool m_alive;
  int m_row;
  int m_col;
};

class grid {
public:
  grid(int rows, int cols) {
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

  ~grid() {}

  // Print entire grid.
  // For every cell printed, "O" means alive and "." means dead
  void print() {
    for (int r = 0; r < this->m_rows; ++r) {
      for (int c = 0; c < this->m_cols; ++c) {
        (this->m_grid[r][c].state()) ? std::cout << "O" : std::cout << ".";
      }
      std::cout << "\n";
    }

    return;
  }

private:
  int m_rows;
  int m_cols;
  std::vector<std::vector<cell>> m_grid;
};

#endif
