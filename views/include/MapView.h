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
    sf::Texture texture;

public:
    MapView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, Map& map);

    void be_loaded(const std::string& file_path);
};


#endif //LAB3_MAPVIEW_H
