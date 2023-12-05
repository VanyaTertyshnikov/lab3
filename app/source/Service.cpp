//
// Created by vanish2 on 04.12.23.
//
#include <iostream>
#include "Service.h"

void Service::move_player(std::pair<int, int> direction) {
    this->state->get_player().be_moved(
            {this->state->get_player().get_x() + direction.first,
            this->state->get_player().get_y() + direction.second}
            );
}

Service::Service(const std::shared_ptr<State>& state) : state(state) {}

void Service::take_ground(std::pair<int, int> direction) {
    int future_x = this->state->get_player().get_x() + direction.first;
    int future_y = this->state->get_player().get_y() + direction.second;
    if(!this->state->get_map().get_cells()[future_y][future_x]) {
        this->move_player(direction);
    }
}

