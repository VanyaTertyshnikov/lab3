//
// Created by vanish2 on 07.12.23.
//

#ifndef LAB3_ALLPOTIONSVIEW_H
#define LAB3_ALLPOTIONSVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "Potion.h"
#include <vector>

class AllPotionsView {
private:
    sf::Texture common_texture;

public:
    AllPotionsView() = default;

    void draw(std::shared_ptr<sf::RenderWindow>& window, std::vector<std::shared_ptr<Potion>> potions);

    void be_load(const std::string& file_path);
};


#endif //LAB3_ALLPOTIONSVIEW_H
