#ifndef GRID_H
#define GRID_H

#include "cell.h"

#include <iostream>
#include <string>
#include <vector>

class grid {
    public:
    grid(int rows, int cols);

    ~grid();

    /**
     * update_grid()
     * Updates the state of all cells in the grid using the state transitions
     * from John Conway's Game of Life.
     */
    void update_grid();

    /**
     * populate()
     * Changes the states of cells in the grid to alive using input from a .txt
     * file.
     *
     * @param string filename: The title of the file to read input from. Every
     * line in the file specified must have the pattern 'x y' where x and y are
     * integers
     */
    void populate(std::string filename);

    /**
     * census()
     * Returns the number of cells neighboring a specific coordinate that have
     * the state alive.
     *
     * @param row: The row coordinate of the cell
     * @param cell: The column coordinate of the cell
     * @return: -1 when the coordinate entered is not valid
     * @return: An integer representing the amount of neighboring cells that are
     * alive
     */
    int census(int row, int col);

    /**
     * print()
     * Print the state of every cell in the grid where a live cell is '0' and a
     * dead cell is '.'
     */
    void print();

    private:
    int m_rows;
    int m_cols;
    std::vector<std::vector<cell>> m_grid;

    void mark_alive(int row, int col);

    void mark_dead(int row, int col);
};

#endif
