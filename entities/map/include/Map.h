//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_MAP_H
#define LAB3_MAP_H

#include <vector>
#include "Cell.h"

class Map {
private:
    unsigned width = 0, height = 0;
    std::vector<std::vector<Cell>> data_;

public:
    Map() = default;

    std::vector<std::vector<Cell>>& get_cells();

    bool get_wall(std::pair<int, int> coords);
    void be_loaded(const std::string& file_path);

};


#endif //LAB3_MAP_H
