//
// Created by vanish2 on 04.12.23.
//
#include <fstream>
#include "State.h"

#include <iostream>

Player &State::get_player() {
    return this->player;
}

void State::load_player(const std::string& file_path) {
    std::ifstream file(file_path);
    if(!file.is_open())
        throw std::invalid_argument("File do not exist.");
    json data = json::parse(file);
    file.close();

    this->player.be_loaded(data);
}

void State::save_player(const std::string &file_path) {
    std::ofstream file(file_path);
    file << this->player.be_saved();
    file.close();
}


void State::load_map(const std::string &file_path) {
    this->map.be_loaded(file_path);
}

Map &State::get_map() {
    return this->map;
}


/*void State::load_map(const std::string &file_path) {
    this->map.be_load(file_path);
}

Map &State::get_map() {
    return this->map;
}*/


