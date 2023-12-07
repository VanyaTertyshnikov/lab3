//
// Created by vanish2 on 05.12.23.
//

#include <iostream>
#include <fstream>
#include "Map.h"

bool Map::get_wall(std::pair<int, int> coords) {
    for(const auto& line : this->data_) {
        for(const auto& cell : line) {
            if(cell.get_x() == coords.first && cell.get_y() == coords.second) {
                return bool(cell);
            }
        }
    }
    return false;
}

void Map::be_loaded(const std::string &file_path) {
    std::ifstream file(file_path);
    json data = json::parse(file);
    file.close();

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
