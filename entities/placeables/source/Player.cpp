//
// Created by vanish2 on 04.12.23.
//
#include "Player.h"

Player::Player(std::pair<int, int> coords) : Creature(coords) {}

void Player::be_loaded(json data) {
    Creature::be_loaded(data);
}

json Player::be_saved() const {
    return Creature::be_saved();
}

void Player::be_moved(std::pair<int, int> new_coords) {
    this->coords = new_coords;
}

