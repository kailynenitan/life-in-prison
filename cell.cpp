#include "cell.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

cell::cell(bool alive, int row, int col)
    : m_alive{alive}, m_new_state{false}, m_row{row}, m_col{col} {}

cell::~cell() {}

void cell::print_state() {
    std::cout << "Cell is alive: ";
    std::cout << std::boolalpha;
    std::cout << this->m_alive << ".\n";
    return;
}

void cell::alive() {
    this->m_new_state = true;
    return;
}

void cell::dead() {
    this->m_new_state = false;
    return;
}

bool cell::state() { return this->m_alive; }

void cell::update_state() {
    this->m_alive = m_new_state;
    return;
}
