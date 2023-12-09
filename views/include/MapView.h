//
// Created by vanish2 on 05.12.23.
//

#ifndef LAB3_MAPVIEW_H
#define LAB3_MAPVIEW_H

#include <SFML/Graphics.hpp>
#include "Map.h"

#include <memory>

class MapView {
private:
    sf::Texture cell_texture;
    sf::Texture potions_texture;

    void draw_cells_layer(std::shared_ptr<sf::RenderWindow>& window, Map& map);

    void draw_potion_layer(std::shared_ptr<sf::RenderWindow>& window,
                           const std::map<std::pair<int, int>, std::shared_ptr<Potion>>& potions);



public:
    MapView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, Map& map);

    void load_cells_asset(const std::string& file_path);

    void load_potions_asset(const std::string& file_path);

    void be_loaded(const std::string& file_path);
};


#endif //LAB3_MAPVIEW_H
