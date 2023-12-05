//
// Created by vanish2 on 05.12.23.
//

#include "Cell.h"

Cell::Cell(std::pair<int, int> coords) : Placeable(coords) {}

Cell::Cell(std::pair<int, int> coords, bool is_wall) : Placeable(coords) {
    this->is_wall_ = is_wall;
}

Cell::operator bool() const {
    return this->is_wall_;
}

void Cell::change_state(bool state) {
    this->is_wall_ = state;
}
