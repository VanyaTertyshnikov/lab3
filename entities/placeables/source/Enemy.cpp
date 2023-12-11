//
// Created by vanish2 on 11.12.23.
//

#include "Enemy.h"

void Enemy::be_moved(std::pair<int, int> new_coords) {
    this->coords = new_coords;
}
