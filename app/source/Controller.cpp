//
// Created by vanish2 on 04.12.23.
//

#include <iostream>
#include "Controller.h"

constexpr sf::Int64 tick_time = 5 * 20000;

void Controller::process_input(const std::shared_ptr<sf::RenderWindow>& window, sf::Clock& clock) {
    sf::Event event{};
    bool event_worked = false;

    while(clock.getElapsedTime().asMicroseconds() < tick_time) {

        if(window->pollEvent(event)) {
            if(event_worked)
                continue;

            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::W) {
                    this->service_->take_ground({0, -1});
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::A) {
                    this->service_->take_ground({-1, 0});
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::S) {
                    this->service_->take_ground({0, 1});
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::D) {
                    this->service_->take_ground({1, 0});
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::Q) {
                    this->service_->try_take();
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::E) {
                    this->service_->try_throw();
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::R) {
                    this->service_->drink();
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::Z) {
                    this->service_->upgrade_parameter(Parameters::Power);
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::X) {
                    this->service_->upgrade_parameter(Parameters::Ability);
                    event_worked = true;
                }
                if (event.key.scancode == sf::Keyboard::Scan::C) {
                    this->service_->upgrade_parameter(Parameters::Endurance);
                    event_worked = true;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    this->service_->select({event.mouseButton.x, event.mouseButton.y});
                    event_worked = true;
                }
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

void Controller::trigger_update() {
    this->service_->update_all_enemies();
}
