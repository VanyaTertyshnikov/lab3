//
// Created by vanish2 on 05.12.23.
//

#include "MapView.h"
#include "CellView.h"
#include "PotionView.h"

#include <iostream>

void MapView::draw(std::shared_ptr<sf::RenderWindow> &window, Map& map) {
    this->draw_cells_layer(window, map);
    this->draw_potion_layer(window, map.get_all_potions());
}

void MapView::be_loaded(const std::string &file_path) {
    this->cell_texture.loadFromFile(file_path);
}

void MapView::draw_cells_layer(std::shared_ptr<sf::RenderWindow> &window, Map &map) {
    for(auto line : map.get_cells()) {
        for(auto& cell : line) {
            CellView cell_view;
            cell_view.set_sprite(this->cell_texture, bool(cell));
            sf::Sprite cell_sprite = cell_view.get_sprite();
            float x_position = cell.get_x() * 32;
            float y_position = cell.get_y() * 32;

            cell_sprite.setPosition(
                    x_position,
                    y_position);
            window->draw(cell_sprite);
        }
    }
}

void MapView::draw_potion_layer(std::shared_ptr<sf::RenderWindow> &window,
                                const std::map<std::pair<int, int>, std::shared_ptr<Potion>> &potions) {
    PotionView potion_view;
    for(const auto& potion : potions) {
        potion_view.set_sprite(this->potions_texture, potion.second);
        sf::Sprite potion_sprite = potion_view.get_sprite();
        float x_position = potion.first.first * 32;
        float y_position = potion.first.second * 32;

        potion_sprite.setPosition(
                x_position,
                y_position
        );
        window->draw(potion_sprite);
    }
}


void MapView::load_cells_asset(const std::string &file_path) {
    this->cell_texture.loadFromFile(file_path);
}

void MapView::load_potions_asset(const std::string &file_path) {
    this->potions_texture.loadFromFile(file_path);
}


