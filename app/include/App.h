//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_APP_H
#define LAB3_APP_H

#include <memory>
#include <SFML/Graphics.hpp>

#include <Controller.h>
#include <Service.h>
#include <State.h>

class App {
private:
    std::shared_ptr<sf::RenderWindow> window
    = std::make_shared<sf::RenderWindow>(sf::VideoMode(1600, 800), "Lab 3");

    std::shared_ptr<Controller> controller;

public:
    App() = default;
    void run();
};

#endif //LAB3_APP_H
