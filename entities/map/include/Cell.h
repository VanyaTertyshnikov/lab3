//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_CELL_H
#define LAB3_CELL_H

#include "Placeable.h"

class Cell : public Placeable {
private:
    bool is_wall_ = false;

public:
    Cell() = default;
    explicit Cell(std::pair<int, int> coords);
    Cell(std::pair<int, int> coords, bool is_wall);
    explicit operator bool() const;
    void change_state(bool state);
};


#endif //LAB3_CELL_H
