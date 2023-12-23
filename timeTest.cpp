//
// Created by vanish2 on 23.12.23.
//

#include <stdexcept>
#include <iostream>

#include <vector>
#include "entities/placeables/include/Enemy.h"

int main() {
    try{
       std::vector<Enemy> enemies;



    } catch(const std::bad_alloc& ba) {
        std::cout << "Not enough memory." << std::endl;
        return 1;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}