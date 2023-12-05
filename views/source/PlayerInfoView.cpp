//
// Created by vanish2 on 05.12.23.
//

#include "PlayerInfoView.h"

void PlayerInfoView::be_loaded(const std::string &file_path) {
    this->font.loadFromFile(file_path);
}

void PlayerInfoView::set_position(std::pair<float, float> new_position) {
    this->position = new_position;
}

void PlayerInfoView::draw(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    sf::Text health(
            std::string("HP:\t") + std::to_string(player.get_primary().health)
            + std::string("/") + std::to_string(player.get_primary().health_limit),
            this->font,
            15);

    sf::Text power(
            std::string("POW:\t") + std::to_string(player.get_primary().power),
            this->font,
            15);

    sf::Text ability(
            std::string("ABL:  \t") + std::to_string(player.get_primary().ability),
            this->font,
            15);

    sf::Text endurance(
            std::string("END: \t") + std::to_string(player.get_primary().endurance),
            this->font,
            15);

    sf::Text bonus_damage(
            std::string("BDMG: \t") + std::to_string(player.get_secondary().bonus_damage),
            this->font,
            15);

    sf::Text bonus_defence(
            std::string("BDFN: \t") + std::to_string(player.get_secondary().bonus_defence),
            this->font,
            15);

    sf::Text unlocking(
            std::string("UNLC: \t") + std::to_string(player.get_secondary().unlocking),
            this->font,
            15);

    sf::Text consumable_limit(
            std::string("CLMT: \t") + std::to_string(player.get_secondary().consumable_limit),
            this->font,
            15);

    health.setPosition(this->position.first + 10, this->position.second + 10);
    window->draw(health);

    power.setPosition(this->position.first + 10, this->position.second + 60);
    window->draw(power);

    ability.setPosition(this->position.first + 10, this->position.second + 80);
    window->draw(ability);

    endurance.setPosition(this->position.first + 10, this->position.second + 100);
    window->draw(endurance);

    bonus_damage.setPosition(this->position.first + 10, this->position.second + 150);
    window->draw(bonus_damage);

    bonus_defence.setPosition(this->position.first + 10, this->position.second + 170);
    window->draw(bonus_defence);

    unlocking.setPosition(this->position.first + 10, this->position.second + 190);
    window->draw(unlocking);

    consumable_limit.setPosition(this->position.first + 10, this->position.second + 210);
    window->draw(consumable_limit);
}


