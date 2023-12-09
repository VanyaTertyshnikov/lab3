//
// Created by vanish2 on 04.12.23.
//

#ifndef LAB3_PLAYER_H
#define LAB3_PLAYER_H

#include "Moveable.h"
#include "Creature.h"

#include <vector>
#include <memory>

#include <utility>

#include "Potion.h"

struct Inventory{
    std::vector<std::pair<bool, std::shared_ptr<Potion>>> potions;
};

class Player : public Moveable, public Creature{
private:
    int max_exp = 0, level = 0, upgrade_points = 0;

    //std::vector<std::shared_ptr<Potion>> potions;
    Inventory inv;

    void reduce_upgrade_points();
public:
    Player() = default;
    ~Player() override = default;

    explicit Player(std::pair<int, int> coords);

    [[nodiscard]] int get_max_exp() const;

    [[nodiscard]] int get_level() const;

    [[nodiscard]] int get_upgrade_points() const;

    [[nodiscard]] std::vector<std::pair<bool, std::shared_ptr<Potion>>>& get_potions();

    void take_potion(std::shared_ptr<Potion>&& potion);

    std::shared_ptr<Potion> throw_potion(unsigned index);

    void drink(unsigned index);

    void upgrade_primary(Primary upgrade_value);

    void inc_exp(int inc_value);

    void be_loaded(json data) override;

    [[nodiscard]] json be_saved() const override;

    void be_moved(std::pair<int, int> new_coords) override;
};

#endif //LAB3_PLAYER_H
