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

int get_chest_index(const std::vector<Chest>& chests, std::pair<int, int> coords) {
    int index = -1;

    for(unsigned i = 0; i < chests.size(); i++) {
        if(chests[i].get_x() == coords.first && chests[i].get_y() == coords.second) {
            index = int(i);
            break;
        }
    }

    return index;
}

void Service::take_ground(std::pair<int, int> direction) {
    int future_x = this->state->get_player().get_x() + direction.first;
    int future_y = this->state->get_player().get_y() + direction.second;

    if(get_chest_index(this->state->get_chests(), {future_x, future_y}) != -1) {
        if(this->state->get_player().get_key_amount() < 1)
            return;
        this->unlock({future_x, future_y});
        this->state->get_player().reduce_key_amount();
    }

    if(!this->state->get_map().get_cells()[future_y][future_x]) {
        this->move_player(direction);
    }
}

void Service::upgrade_parameter(int num_of_parameter) {
    if(this->state->get_player().get_upgrade_points()  < 1)
        return;
    Primary upgrade_struct;
    if(num_of_parameter == 1) { // upgrade power
        upgrade_struct.power = 1;
    } else if(num_of_parameter == 2) { // upgrade ability
        upgrade_struct.ability = 1;
    } else if(num_of_parameter == 3) { // upgrade endurance
        upgrade_struct.endurance = 1;
    }
    this->state->get_player().upgrade_primary(upgrade_struct);
}

void Service::try_take() {
    auto player_x = this->state->get_player().get_x();
    auto player_y = this->state->get_player().get_y();
    auto curr_floor = this->state->get_map().get_cells()[player_y][player_x];
    if(curr_floor.get_inner_object() == nullptr)
        return;
    std::shared_ptr<Potion> read_potion = std::dynamic_pointer_cast<Potion>(curr_floor.get_inner_object());
    if(read_potion) {
        unsigned max_potions_size = this->state->get_player().get_secondary().consumable_limit;
        unsigned curr_potions_size = this->state->get_player().get_potions().size();
        if(curr_potions_size < max_potions_size) {
            this->state->get_player().take_potion(std::move(read_potion));
            this->state->get_map().get_cells()[player_y][player_x].set_inner_object(nullptr);
        }
    }
    std::shared_ptr<Key> read_key = std::dynamic_pointer_cast<Key>(curr_floor.get_inner_object());
    if(read_key) {
        this->state->get_player().inc_key_amount(read_key->get_amount());
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(nullptr);
    }
}



bool was_selected(const std::vector<std::pair<bool, std::shared_ptr<Potion>>>& potions){
    for(const auto& p : potions) {
        if(p.first) {
            return true;
        }
    }
    return false;
}

unsigned get_selected_index(const std::vector<std::pair<bool, std::shared_ptr<Potion>>>& potions) {
    unsigned index = 0;
    for(unsigned i = 0; i < potions.size(); i++) {
        if(potions[i].first) {
            index = i;
            break;
        }
    }
    return index;
}

void Service::try_throw() {
    auto player_x = this->state->get_player().get_x();
    auto player_y = this->state->get_player().get_y();
    auto curr_floor = this->state->get_map().get_cells()[player_y][player_x];
    if(curr_floor.get_inner_object() != nullptr)
        return;

    if(!was_selected(this->state->get_player().get_potions()))
        return;

    unsigned index = get_selected_index(this->state->get_player().get_potions());
    this->state->get_map().get_cells()[player_y][player_x].set_inner_object(
            this->state->get_player().throw_potion(index));
}


void Service::drink() {
    if(!was_selected(this->state->get_player().get_potions()))
        return;

    unsigned index = get_selected_index(this->state->get_player().get_potions());
    std::cout << index << "\n";
    this->state->get_player().drink(index);
}

void Service::select(std::pair<int, int> mouse_touch) {
    if(mouse_touch.second >= 400 && mouse_touch.second <= 432) {
        if(mouse_touch.first >= 1290 && mouse_touch.first <= 1590) {
            unsigned index = (mouse_touch.first - 1290) / 32;
            auto potions_data = this->state->get_player().get_potions();

            if(potions_data.empty()) return;
            if(index >= potions_data.size()) index = potions_data.size() - 1;

            if(!potions_data.at(index).first) {
                if(!was_selected(potions_data)) {
                    this->state->get_player().get_potions().at(index).first = true;
                }
            } else {
                this->state->get_player().get_potions().at(index).first = false;
            }
        }
    }
}

void Service::unlock(std::pair<int, int> coords) {
    int index = get_chest_index(this->state->get_chests(), coords);
    if(index == -1) return;

    int resist_points = this->state->get_chests().at(index).get_level() * 5;
    int unlocking_points = this->state->get_player().get_secondary().unlocking * 3 + 10;
    if(resist_points > unlocking_points) {
        this->state->get_player().reduce_key_amount();
    } else {
        this->state->get_map().get_cells()[coords.first][coords.second].set_inner_object(
                this->state->get_chests()[index].get_inner_object()
                );
        this->state->get_chests().erase(this->state->get_chests().begin() + index,
                                        this->state->get_chests().begin() + index + 1);
    }
}




