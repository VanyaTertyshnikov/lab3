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
}

void Map::be_loaded(const std::string& file_path) {
    std::ifstream file(file_path);

    file >> this->width >> this->height;

    for(unsigned i = 0; i < this->height; i++) {
        std::vector<Cell> new_line;
        for(unsigned j = 0; j < this->width; j++) {
            new_line.push_back(Cell{{j, i}, false});
        }
        this->data_.push_back(new_line);
    }

    std::string read_line;
    bool first_line = true;

    while(getline(file, read_line)) {
        if(first_line) {
            first_line = false;
            continue;
        }

        auto space_pos = read_line.find(' ');
        int read_x = std::stoi(read_line.substr(0, space_pos));
        int read_y = std::stoi(read_line.substr(space_pos));

        this->data_[read_y][read_x].set_x(read_x);
        this->data_[read_y][read_x].set_y(read_y);
        this->data_[read_y][read_x].change_state(true);
    }

    file.close();
}

std::vector<std::vector<Cell>>& Map::get_cells() {
    return this->data_;
}
