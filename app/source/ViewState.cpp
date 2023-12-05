//
// Created by vanish2 on 04.12.23.
//
#include "ViewState.h"
#include <iostream>

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

    std::pair<float, float> pos{this->state_->get_map().get_width() * 32, 0};
    this->player_info_view.set_position(pos);
    this->player_info_view.draw(window, this->state_->get_player());

    window->display();
}

void ViewState::load_map_view(const std::string &file_path) {
    this->map_view.be_loaded(file_path);
}

void ViewState::load_player_info_view(const std::string &file_path) {
    this->player_info_view.be_loaded(file_path);
}
