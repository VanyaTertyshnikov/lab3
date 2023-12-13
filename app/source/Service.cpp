//
// Created by vanish2 on 04.12.23.
//
#include <iostream>
#include "Service.h"
#include <thread>
#include <random>
#include <algorithm>

Service::Service(const std::shared_ptr<State>& state) : state(state) {}

int get_chest_index(const std::vector<Chest>& chests, std::pair<int, int> coords) {
    int index = -1;

    for(unsigned i = 0; i < chests.size(); i++) {
        if(chests[i].get_position() == coords) {
            index = int(i);
            break;
        }
    }

    return index;
}

int get_enemy_index(const std::vector<Enemy>& enemies, std::pair<int, int> coords) {
    int index = -1;

    for(unsigned i = 0; i < enemies.size(); i++) {
        if(enemies[i].get_position() == coords) {
            index = int(i);
            break;
        }
    }

    return index;
}

void Service::take_ground(std::pair<int, int> direction) {
    std::pair<int, int> future_position = this->state->get_player().get_position() + direction;

    if(get_chest_index(this->state->get_chests(), future_position) != -1) {
        if(this->state->get_player().get_key_amount() < 1)
            return;
        this->unlock(future_position);
        this->state->get_player().reduce_key_amount();
    }

    if(get_enemy_index(this->state->get_enemies(), future_position) != -1)
        return;

    if(!this->state->get_map().get_cells()[future_position.second][future_position.first]) {
        this->move_player(future_position);
    }
}


void Service::move_player(std::pair<int, int> future_position) {
    this->state->get_player().be_moved(future_position);
}

void Service::upgrade_parameter(int num_of_parameter) {
    if(this->state->get_player().get_upgrade_points()  < 1)
        return;
    Primary upgrade_struct;
    if(num_of_parameter == Parameters::Power) { // upgrade power
        upgrade_struct.power = 1;
    } else if(num_of_parameter == Parameters::Ability) { // upgrade ability
        upgrade_struct.ability = 1;
    } else if(num_of_parameter == Parameters::Endurance) { // upgrade endurance
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
    std::shared_ptr<Weapon> read_weapon = std::dynamic_pointer_cast<Weapon>(curr_floor.get_inner_object());
    if(read_weapon) {
        auto tmp = this->state->get_player().get_weapon().second;
        this->state->get_player().take_weapon(std::move(read_weapon));
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(tmp);
    }
}


bool was_potion_selected(const std::vector<std::pair<bool, std::shared_ptr<Potion>>>& potions){
    for(const auto& p : potions) {
        if(p.first) {
            return true;
        }
    }
    return false;
}

unsigned get_potion_selected_index(const std::vector<std::pair<bool, std::shared_ptr<Potion>>>& potions) {
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

    if(was_potion_selected(this->state->get_player().get_potions())) {
        unsigned index = get_potion_selected_index(this->state->get_player().get_potions());
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(
                this->state->get_player().throw_potion(index));
    }

    if(this->state->get_player().get_weapon().first) {
        this->state->get_map().get_cells()[player_y][player_x].set_inner_object(
                this->state->get_player().throw_weapon());
    }
}


void Service::drink() {
    if(!was_potion_selected(this->state->get_player().get_potions()))
        return;

    unsigned index = get_potion_selected_index(this->state->get_player().get_potions());
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
                if(!was_potion_selected(potions_data)) {
                    this->state->get_player().get_potions().at(index).first = true;
                }
            } else {
                this->state->get_player().get_potions().at(index).first = false;
            }
        }
    }
    if(mouse_touch.second >= 432 && mouse_touch.second <= 464) {
        if(mouse_touch.first >= 1290 && mouse_touch.first <= 1590) {
            if(!this->state->get_player().get_weapon().first) {
                this->state->get_player().get_weapon().first = true;
            } else {
                this->state->get_player().get_weapon().first = false;
            };
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

int get_random_int() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 3);
    return dist(gen);
}

std::pair<int, int> get_random_direction(const Enemy& enemy) {
    int future_x = enemy.get_x();
    int future_y = enemy.get_y();

    switch (get_random_int()) {
        case 0: // up
            future_y--;
            break;
        case 1: // left
            future_x--;
            break;
        case 2: //down
            future_y++;
            break;
        case 3:
            future_x++;
            break;
    }

    return {future_x, future_y};
}

void Service::update_all_enemies() {
    for(auto& enemy: this->state->get_enemies()) {
        this->update(enemy);
    }
}


bool Service::check_direction(std::pair<int, int> coords) {
    if(this->state->get_player().get_x() == coords.first && this->state->get_player().get_y() == coords.second)
        return true;
    return false;
}

void Service::update(Enemy& enemy) {
    std::pair<int, int> future_position = get_random_direction(enemy);

    this->hit_player(enemy);

    if(get_chest_index(this->state->get_chests(), future_position) != -1)
        return;

    if (!this->state->get_map().get_cells()[future_position.second][future_position.first])
        enemy.be_moved(future_position);
}

void Service::hit_player(Enemy &who) {
    int player_x = this->state->get_player().get_x();
    int player_y = this->state->get_player().get_y();

    if(check_direction({player_x, player_y - 1}) || check_direction({player_x, player_y + 1}) ||
            check_direction({player_x - 1, player_y}) || check_direction({player_x + 1, player_y})) {
        std::cout << this->state->get_player().get_primary().health << "\n";
    }
}





