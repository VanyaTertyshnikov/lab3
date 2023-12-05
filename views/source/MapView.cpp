//
// Created by vanish2 on 05.12.23.
//

#include "MapView.h"
#include "CellView.h"

#include <iostream>

void MapView::draw(std::shared_ptr<sf::RenderWindow> &window, Map& map) {
    for(auto line : map.get_cells()) {
        for(auto& cell : line) {
            CellView cell_view;
            cell_view.set_sprite(this->texture, bool(cell));
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

void MapView::be_loaded(const std::string &file_path) {
    this->texture.loadFromFile(file_path);
}
