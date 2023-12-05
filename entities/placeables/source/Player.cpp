//
// Created by vanish2 on 04.12.23.
//
#include "Player.h"

Player::Player(std::pair<int, int> coords) : Creature(coords) {}

void Player::be_loaded(json data) {
    Creature::be_loaded(data);
    this->max_exp = data["max_exp"].get<int>();
    this->level = data["level"].get<int>();
    this->upgrade_points = data["upgrade_points"].get<int>();
}

json Player::be_saved() const {
    json save_object =  Creature::be_saved();
    save_object["max_exp"] = this->max_exp;
    save_object["level"] = this->level;
    save_object["upgrade_points"] = this->upgrade_points;
    return save_object;
}

void Player::be_moved(std::pair<int, int> new_coords) {
    this->coords = new_coords;
}

void Player::inc_exp(int inc_value) {
    this->exp += inc_value;
    if(this->exp >= this->max_exp) {
        while(this->exp >= this->max_exp) {
            this->exp -= this->max_exp;
            this->max_exp += 25;
            this->level++;
            this->upgrade_points *= 5;
        }
    }
}

void Player::upgrade_primary(Primary upgrade_value) {
    this->primary = this->primary + upgrade_value;
    this->compute_secondary();
    this->reduce_upgrade_points();
}

int Player::get_max_exp() const {
    return this->max_exp;
}

int Player::get_level() const {
    return this->level;
}

int Player::get_upgrade_points() const {
    return this->upgrade_points;
}

void Player::reduce_upgrade_points() {
    this->upgrade_points--;
}
