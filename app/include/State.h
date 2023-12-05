//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_STATE_H
#define LAB3_STATE_H

#include "Player.h"
#include "Cell.h"
#include "Map.h"

class State {
private:
    Player player{};
    Map map{};
    Cell cell{{10, 0}, true};

public:
    State() = default;

    Player& get_player();

    Map& get_map();

    void load_player(const std::string& file_path);

    void save_player(const std::string& file_path);

    void load_map(const std::string& file_path);
};

#endif //LAB3_STATE_H
