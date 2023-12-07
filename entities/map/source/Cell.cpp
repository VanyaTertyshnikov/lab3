//
// Created by vanish2 on 05.12.23.
//

#include "Cell.h"
#include "Potion.h"
#include <iostream>

Cell::Cell(std::pair<int, int> coords) : Placeable(coords) {}

Cell::Cell(std::pair<int, int> coords, bool is_wall) : Placeable(coords) {
    this->is_wall_ = is_wall;
}

Cell::operator bool() const {
    return this->is_wall_;
}

void Cell::change_state(bool state) {
    this->is_wall_ = state;
}

std::shared_ptr<Object> Cell::get_inner_object() const {
    return this->inner_object;
}

void Cell::set_inner_object(const std::shared_ptr<Object>& new_inner_object) {
    this->inner_object = new_inner_object;
}

void Cell::be_loaded(json data) {
    Placeable::be_loaded(data);
    if(data["type"].get<std::string>() == "wall") {
        this->is_wall_ = true;
    } else if(data["type"].get<std::string>() == "floor") {
        if(data["container"]["type"].get<std::string>() == "potion") {
            this->inner_object = std::make_shared<Potion>();
            this->inner_object->be_loaded(data["container"]["data"]);
        }
    }
}
