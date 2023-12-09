//
// Created by vanish2 on 05.12.23.
//

#include <iostream>
#include <fstream>
#include "Map.h"

void Map::be_loaded(const json& data) {
    for(unsigned i = 0; i < 25; i++) {
        std::vector<Cell> new_line;
        for(unsigned j = 0; j < 40; j++) {
            new_line.push_back(Cell{{j, i}, false});
        }
        this->data_.push_back(new_line);
    }

    for(auto cell_data : data) {
        int x = cell_data["x"];
        int y = cell_data["y"];
        this->data_[y][x].be_loaded(cell_data);
    }
}

std::vector<std::vector<Cell>>& Map::get_cells() {
    return this->data_;
}

std::map<std::pair<int, int>, std::shared_ptr<Potion>> Map::get_all_potions() {
    std::shared_ptr<Potion> read_potion;
    std::map<std::pair<int, int>, std::shared_ptr<Potion>> all_potions;
    for(const auto& line : this->data_) {
        for(const auto& cell : line) {
            read_potion = std::dynamic_pointer_cast<Potion>(cell.get_inner_object());
            if(read_potion) {
                all_potions.insert({{cell.get_x(), cell.get_y()}, read_potion});
            }
        }
    }
    return all_potions;
}
