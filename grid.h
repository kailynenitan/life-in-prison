#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

class cell {
  public:
    cell(bool alive, int row, int col)
        : m_alive{alive}, m_row{row}, m_col{col} {}

    void print_state() { std::cout << "Cell is alive: " << this->m_alive; }

  private:
    bool m_alive;
    int m_row;
    int m_col;
}

#endif
