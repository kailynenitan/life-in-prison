#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <vector>

class cell {
public:
  cell(bool alive, int row, int col);

  ~cell();

  void print_state();

  void alive();

  void dead();

  bool state();

  void update_state();

private:
  bool m_alive;
  bool m_new_state;
  int m_row;
  int m_col;
};

class grid {
public:
  grid(int rows, int cols);

  ~grid();

  void update_grid();

  void populate(std::string filename);

  int census(int row, int col);

  void print();

private:
  int m_rows;
  int m_cols;
  std::vector<std::vector<cell>> m_grid;
};

#endif
