#ifndef CELL_H
#define CELL_H

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

#endif
