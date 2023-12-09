//
// Created by vanish2 on 04.12.23.
//
#include "ViewState.h"
#include <iostream>
#include <fstream>

void ViewState::set_state(const std::shared_ptr<State> &state) {
    this->state_ = state;
}

void ViewState::load_player_view(const std::string &file_path) {
    this->player_view.be_loaded(file_path);
}

/*void ViewState::load_map_view(const std::string &file_path) {
    this->map_view.be_load(file_path);
    this->map_view.fill(this->state_->get_map());
}*/

void ViewState::redraw(std::shared_ptr<sf::RenderWindow>& window) {
    window->clear();

    this->map_view.draw(window, this->state_->get_map());

    this->player_view.draw(window, this->state_->get_player());

    this->player_info_view.set_position({0, 0});
    this->player_info_view.draw(window, this->state_->get_player());

    window->display();
}

void ViewState::load_map_view(const std::string &file_path) {
    this->map_view.be_loaded(file_path);
}

void ViewState::load_player_info_view(const std::string &file_path) {
    this->player_info_view.be_loaded(file_path);
}

void ViewState::load(const std::string &file_path) {
    std::ifstream file(file_path);
    if(!file.is_open())
        throw std::invalid_argument("Can not load from file, because it does not exist.");
    json data = json::parse(file);
    file.close();

    this->player_view.be_loaded(data["player"].get<std::string>());
    this->player_info_view.be_loaded(data["font"].get<std::string>());
    this->map_view.load_cells_asset(data["map"].get<std::string>());
    this->map_view.load_potions_asset(data["potions"].get<std::string>());
}
