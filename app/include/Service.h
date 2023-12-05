//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_SERVICE_H
#define LAB3_SERVICE_H

#include <memory>
#include <utility>

#include "State.h"

class Service {
private:
    std::shared_ptr<State> state = std::make_shared<State>();

public:
    Service() = default;
    explicit Service(const std::shared_ptr<State>& state);
    void take_ground(std::pair<int, int> direction);
    void move_player(std::pair<int, int> direction);
    void upgrade_parameter(int num_of_parameter);
};

#endif //LAB3_SERVICE_H
