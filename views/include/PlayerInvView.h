//
// Created by vanish2 on 09.12.23.
//

#ifndef LAB3_PLAYERINVVIEW_H
#define LAB3_PLAYERINVVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"

class PlayerInvView {
private:
    sf::Texture potions_asset;
    sf::Font font;

public:
    PlayerInvView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, Player& inventory);

    void load_potions_asset(const std::string& file_path);

    void load_font(const std::string& file_path);
};


#endif //LAB3_PLAYERINVVIEW_H
