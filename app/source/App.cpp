//
// Created by vanish2 on 04.12.23.
//
#include "App.h"
#include "ViewState.h"
#include <iostream>

void App::run() {
    std::shared_ptr<State> state = std::make_shared<State>();
    state->load_player("files/player.json");
    state->load_map("files/map.json");

    std::shared_ptr<ViewState> view_state = std::make_shared<ViewState>();
    view_state->load_player_view("images/player.png");
    view_state->set_state(state);
    view_state->load_map_view("images/map.png");
    view_state->load_player_info_view("fonts/open_sans/OpenSans-Semibold.ttf");

    std::shared_ptr<Service> service = std::make_shared<Service>(state);

    this->controller = std::make_shared<Controller>(service, view_state);

    while (this->window->isOpen()) {
        this->controller->process_input(this->window);
        this->controller->trigger_redraw(this->window);
    }
}