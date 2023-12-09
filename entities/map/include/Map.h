//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_MAP_H
#define LAB3_MAP_H

#include <memory>
#include <vector>
#include "Cell.h"
#include "Potion.h"

class Map {
private:
    std::vector<std::vector<Cell>> data_;

public:
    Map() = default;

    std::vector<std::vector<Cell>>& get_cells();

    std::vector<std::shared_ptr<Potion>> get_all_potions();

    void be_loaded(const json& data);
};


#endif //LAB3_MAP_H
