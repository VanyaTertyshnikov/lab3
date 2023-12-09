//
// Created by vanish2 on 04.12.23.
//
#include "App.h"
#include "ViewState.h"
#include <iostream>
#include <thread>

constexpr int fps = 60;
constexpr auto refresh_rate = std::chrono::microseconds(1000) / fps;


void App::run() {
    std::shared_ptr<State> state = std::make_shared<State>();
    state->load("files/state_init.json");

    std::shared_ptr<ViewState> view_state = std::make_shared<ViewState>();
    view_state->set_state(state);
    view_state->load("files/view_state.json");

    std::shared_ptr<Service> service = std::make_shared<Service>(state);

    this->controller = std::make_shared<Controller>(service, view_state);

    while (this->window->isOpen()) {
        this->controller->process_input(this->window);
        this->controller->trigger_redraw(this->window);
        std::this_thread::sleep_for(refresh_rate);
    }
}
