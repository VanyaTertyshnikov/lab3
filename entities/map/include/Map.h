//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_MAP_H
#define LAB3_MAP_H

#include <memory>
#include <vector>
#include <map>
#include "Cell.h"
#include "Potion.h"
#include "Key.h"

class Map {
private:
    std::vector<std::vector<Cell>> data_;

public:
    Map() = default;

    std::vector<std::vector<Cell>>& get_cells();

    std::map<std::pair<int, int>, std::shared_ptr<Potion>> get_all_potions();

    std::map<std::pair<int, int>, std::shared_ptr<Key>> get_all_keys();

    void be_loaded(const json& data);
};


#endif //LAB3_MAP_H
