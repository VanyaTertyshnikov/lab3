//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_WEAPON_H
#define LAB3_WEAPON_H


#include "Object.h"

class Weapon : public Object{
private:
    int damage_;

public:
    Weapon() = default;
    ~Weapon() override = default;

    [[nodiscard]] int get_damage() const;

    void be_loaded(json data) override;
};


#endif //LAB3_WEAPON_H
