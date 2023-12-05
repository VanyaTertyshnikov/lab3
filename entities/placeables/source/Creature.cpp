//
// Created by vanish2 on 04.12.23.
//
#include "Creature.h"

Primary Primary::operator+(const Primary &other) const {
    Primary result;
    result.power = this->power + other.power;
    result.ability = this->ability + other.ability;
    result.endurance = this->endurance + other.endurance;
    result.health_limit = this->health_limit + other.health_limit;
    result.health = this->health + other.health;
    return result;
}


Creature::Creature(std::pair<int, int> coords) : Placeable(coords) {}

Primary Primary::operator-(const Primary &other) const {
    Primary result;
    result.power = this->power - other.power;
    result.ability = this->ability - other.ability;
    result.endurance = this->endurance - other.endurance;
    result.health_limit = this->health_limit - other.health_limit;
    result.health = this->health - other.health;
    return result;
}

Primary Creature::get_primary() const { return this->primary; }

Primary Creature::get_influence() const { return this->influence; }

Secondary Creature::get_secondary() const { return this->secondary; }

void Creature::compute_secondary() {
    Primary with_influence = this->primary + this->influence;
    this->secondary.bonus_damage = with_influence.power / 5;
    this->secondary.bonus_defence = with_influence.ability / 5;
    this->secondary.unlocking = with_influence.ability / 5;
    this->secondary.consumable_limit = with_influence.endurance / 5;
}

void Creature::be_loaded(json data) {
    Placeable::be_loaded(data);
    const auto& primary_data = data["primary"];
    this->primary.power = primary_data["power"].get<int>();
    this->primary.ability = primary_data["ability"].get<int>();
    this->primary.endurance = primary_data["endurance"].get<int>();
    this->primary.health_limit = primary_data["health_limit"].get<int>();
    this->primary.health = primary_data["health"].get<int>();
    this->exp = data["exp"].get<int>();
    this->compute_secondary();
}

json Creature::be_saved() const {
    json save_object = Placeable::be_saved();
    save_object["primary"]["power"] = this->primary.power;
    save_object["primary"]["ability"] = this->primary.ability;
    save_object["primary"]["endurance"] = this->primary.endurance;
    save_object["primary"]["health_limit"] = this->primary.health_limit;
    save_object["primary"]["health"] = this->primary.health;
    save_object["exp"] = this->exp;
    return save_object;
}

int Creature::get_exp() const {
    return this->exp;
}


