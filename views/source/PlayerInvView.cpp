//
// Created by vanish2 on 09.12.23.
//

#include "PlayerInvView.h"
#include "PotionView.h"
#include "WeaponView.h"
#include "EquipmentView.h"

constexpr int font_size =  15;

#define LEFT_CORNER_X 1290
#define LEFT_CORNER_Y 400

void PlayerInvView::draw(std::shared_ptr<sf::RenderWindow> &window, Player& player) {
    sf::Text logo(
            "Inventory",
            this->font,
            font_size
    );
    logo.setPosition(LEFT_CORNER_X, LEFT_CORNER_Y);
    window->draw(logo);

    this->draw_potions(window, player);
    this->draw_weapon(window, player);
    this->draw_equipment(window, player);
}

void PlayerInvView::load_potions_asset(const std::string &file_path) {
    this->potions_asset.loadFromFile(file_path);
}

void PlayerInvView::load_font(const std::string &file_path) {
    this->font.loadFromFile(file_path);
}

void PlayerInvView::draw_potions(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    PotionView potion_view;
    auto potions = player.get_potions();
    for(unsigned i = 0; i < potions.size(); i++) {
        potion_view.set_sprite(this->potions_asset, potions[i].second);
        sf::Sprite potion_sprite = potion_view.get_sprite();
        float x_position = LEFT_CORNER_X + i * 32;
        float y_position = LEFT_CORNER_Y + 24;

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

void PlayerInvView::draw_weapon(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    if(player.get_weapon().second == nullptr)
        return;
    WeaponView weapon_view;
    weapon_view.set_sprite(this->weapon_asset, player.get_weapon().second);
    sf::Sprite weapon_sprite = weapon_view.get_sprite();

    float x_position = LEFT_CORNER_X;
    float y_position = LEFT_CORNER_Y + 32 + 24;

    sf::RectangleShape layout;
    layout.setSize({32, 32});
    if(player.get_weapon().first) {
        layout.setFillColor(sf::Color::Green);
    } else {
        layout.setFillColor(sf::Color::Black);
    }
    layout.setPosition({x_position, y_position});

    weapon_sprite.setPosition(
            x_position,
            y_position
    );
    window->draw(layout);
    window->draw(weapon_sprite);
}

void PlayerInvView::load_weapon_asset(const std::string &file_path) {
    this->weapon_asset.loadFromFile(file_path);
}

void PlayerInvView::draw_equipment(std::shared_ptr<sf::RenderWindow> &window, Player &player) {
    EquipmentView equipment_view;
    auto equipments = player.get_equipments();
    for(unsigned i = 0; i < equipments.size(); i++) {
        equipment_view.set_sprite(this->equipment_asset, equipments[i].second);
        sf::Sprite equipment_sprite = equipment_view.get_sprite();

        float x_position = LEFT_CORNER_X + i * 32;
        float y_position = LEFT_CORNER_Y + 64 + 24;

        sf::RectangleShape layout;
        layout.setSize({32, 32});
        if(equipments[i].first) {
            layout.setFillColor(sf::Color::Green);
        } else {
            layout.setFillColor(sf::Color::Black);
        }
        layout.setPosition({x_position, y_position});

        equipment_sprite.setPosition(
                x_position,
                y_position
        );
        window->draw(layout);
        window->draw(equipment_sprite);
    }
}

void PlayerInvView::load_equipment_asset(const std::string &file_path) {
    this->equipment_asset.loadFromFile(file_path);
}
