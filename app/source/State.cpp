//
// Created by vanish2 on 04.12.23.
//
#include <fstream>
#include "State.h"

#include <iostream>

Player &State::get_player() {
    return this->player;
}

Map &State::get_map() {
    return this->map;
}

void State::load(const std::string &file_path) {
    std::ifstream file(file_path);
    if(!file.is_open())
        throw std::invalid_argument("Can not load from file, because it does not exist.");
    json data = json::parse(file);
    file.close();

    this->player.be_loaded(data["player"]);
    this->map.be_loaded(data["map"]);
}



