//
// Created by vanish2 on 04.12.23.
//

#include <iostream>
#include "Controller.h"

void Controller::process_input(const std::shared_ptr<sf::RenderWindow>& window) {
    sf::Event event{};
    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window->close();
        }

        if(event.type == sf::Event::KeyPressed) {
            if(event.key.scancode == sf::Keyboard::Scan::W) {
                this->service_->take_ground({0, -1});
            }
            if(event.key.scancode == sf::Keyboard::Scan::A) {
                this->service_->take_ground({-1, 0});
            }
            if(event.key.scancode == sf::Keyboard::Scan::S) {
                this->service_->take_ground({0, 1});
            }
            if(event.key.scancode == sf::Keyboard::Scan::D) {
                this->service_->take_ground({1, 0});
            }
            if(event.key.scancode == sf::Keyboard::Scan::Q) {
                this->service_->try_take();
            }
            if(event.key.scancode == sf::Keyboard::Scan::Z) {
                this->service_->upgrade_parameter(1);
            }
            if(event.key.scancode == sf::Keyboard::Scan::X) {
                this->service_->upgrade_parameter(2);
            }
            if(event.key.scancode == sf::Keyboard::Scan::C) {
                this->service_->upgrade_parameter(3);
            }
        }

        if(event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Left) {
                std::cout << event.mouseButton.x << " " << event.mouseButton.y << "\n";

            }
        }
    }
}

Controller::Controller(const std::shared_ptr<Service> &service, const std::shared_ptr<ViewState>& view_state)
: service_(service), view_state(view_state) {}

void Controller::set_service(const std::shared_ptr<Service> &service) {
    this->service_ = service;
}

void Controller::trigger_redraw(std::shared_ptr<sf::RenderWindow> &window) {
    this->view_state->redraw(window);
}
