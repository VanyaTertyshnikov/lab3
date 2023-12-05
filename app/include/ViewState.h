//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_VIEWSTATE_H
#define LAB3_VIEWSTATE_H

#include <memory>
#include "PlayerView.h"
#include "CellView.h"
#include "State.h"
#include "MapView.h"
#include "PlayerInfoView.h"

#include <SFML/Graphics.hpp>

class ViewState {
private:
    PlayerView player_view{};
    CellView cell_view{};
    MapView map_view{};
    PlayerInfoView player_info_view{};
    std::shared_ptr<State> state_;

public:
    ViewState() = default;

    void set_state(const std::shared_ptr<State>& state);

    void redraw(std::shared_ptr<sf::RenderWindow>& window);

    void load_player_view(const std::string& file_path);

    void load_map_view(const std::string& file_path);

    void load_player_info_view(const std::string& file_path);
};

#endif //LAB3_VIEWSTATE_H
