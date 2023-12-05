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
            std::string("Health") + std::to_string(player.get_primary().health)
            + std::string("/") + std::to_string(player.get_primary().health_limit),
            this->font,
            20);

    health.setPosition(this->position.first + 10, this->position.second + 10);
    window->draw(health);
}


