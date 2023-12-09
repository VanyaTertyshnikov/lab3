//
// Created by vanish2 on 09.12.23.
//

#include "PlayerInvView.h"
#include "PotionView.h"

#define LEFT_CORNER_X 1290
#define LEFT_CORNER_Y 400

void PlayerInvView::draw(std::shared_ptr<sf::RenderWindow> &window, Player& player) {
    PotionView potion_view;
    auto potions = player.get_potions();
    for(unsigned i = 0; i < potions.size(); i++) {
        potion_view.set_sprite(this->potions_asset, potions[i].second);
        sf::Sprite potion_sprite = potion_view.get_sprite();
        float x_position = LEFT_CORNER_X + i * 32;
        float y_position = LEFT_CORNER_Y;

        sf::RectangleShape layout;
        layout.setSize({32, 32});
        if(potions[i].first) {
            layout.setFillColor(sf::Color::Green);
        } else {
            layout.setFillColor(sf::Color::Black);
        }
        layout.setPosition({x_position, y_position});

        potion_sprite.setPosition(
                x_position,
                y_position
                );
        window->draw(layout);
        window->draw(potion_sprite);
    }
}

void PlayerInvView::load_potions_asset(const std::string &file_path) {
    this->potions_asset.loadFromFile(file_path);
}

void PlayerInvView::load_font(const std::string &file_path) {
    this->font.loadFromFile(file_path);
}
