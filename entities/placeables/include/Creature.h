//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_CREATURE_H
#define LAB3_CREATURE_H

#include "Placeable.h"

struct Primary {
    int power = 0,
        ability = 0,
        endurance = 0,
        health_limit = 0,
        health = 0;

    Primary operator+(const Primary& other) const;
    Primary operator-(const Primary& other) const;
};

struct Secondary {
    int bonus_damage = 0,
        bonus_defence = 0,
        unlocking = 0,
        consumable_limit = 0;
};

class Creature : public  Placeable {
protected:
    Primary primary;
    Primary influence;
    Secondary secondary;

    void compute_secondary();


public:
    Creature() = default;
    explicit Creature(std::pair<int, int> coords);
    ~Creature() override = default;

    [[nodiscard]] Primary get_primary() const;

    [[nodiscard]] Primary get_influence() const;

    [[nodiscard]] Secondary get_secondary() const;

    void be_loaded(json data) override;

    json be_saved() const override;
};

#endif //LAB3_CREATURE_H
