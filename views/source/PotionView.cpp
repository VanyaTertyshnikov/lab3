//
// Created by vanish2 on 09.12.23.
//

#include "PotionView.h"

void PotionView::set_sprite(const sf::Texture& potion_asset, std::shared_ptr<Potion> data) {
    this->sprite.setTexture(potion_asset);
    this->sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
}

sf::Sprite PotionView::get_sprite() const {
    return this->sprite;
}

