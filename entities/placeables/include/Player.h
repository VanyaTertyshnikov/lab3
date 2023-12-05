//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_PLAYER_H
#define LAB3_PLAYER_H

#include "Moveable.h"
#include "Creature.h"

class Player : public Moveable, public Creature{
public:
    Player() = default;
    ~Player() override = default;

    explicit Player(std::pair<int, int> coords);

    void be_loaded(json data) override;

    [[nodiscard]] json be_saved() const override;

    void be_moved(std::pair<int, int> new_coords) override;
};

#endif //LAB3_PLAYER_H
