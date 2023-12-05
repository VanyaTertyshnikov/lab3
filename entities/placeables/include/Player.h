//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_PLAYER_H
#define LAB3_PLAYER_H

#include "Moveable.h"
#include "Creature.h"

class Player : public Moveable, public Creature{
private:
    int max_exp = 0, level = 0, upgrade_points = 0;

public:
    Player() = default;
    ~Player() override = default;

    explicit Player(std::pair<int, int> coords);

    int get_max_exp() const;

    int get_level() const;

    int get_upgrade_points() const;

    void upgrade_primary(Primary upgrade_value);

    void inc_exp(int inc_value);

    void be_loaded(json data) override;

    [[nodiscard]] json be_saved() const override;

    void be_moved(std::pair<int, int> new_coords) override;
};

#endif //LAB3_PLAYER_H
