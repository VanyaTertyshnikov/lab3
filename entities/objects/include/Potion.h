//
// Created by vanish2 on 06.12.23.
//

#ifndef LAB3_POTION_H
#define LAB3_POTION_H


#include "Object.h"
#include "Drinkable.h"

class Potion : public Object, public Drinkable{
private:
    Primary potion_effect;

public:
    Potion() = default;
    Potion(const std::string& name, Primary new_potion_effect);
    ~Potion() override = default;

    [[nodiscard]] Primary get_potion_effect() const;

    void set_potion_effect(Primary new_potion_effect);

    void be_loaded(json data) override;

    [[nodiscard]] json be_saved() const override;

    Primary be_drunk() override;
};


#endif //LAB3_POTION_H
