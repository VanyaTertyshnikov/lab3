//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_EQUIPMENT_H
#define LAB3_EQUIPMENT_H


#include "Object.h"

class Equipment : public Object {
private:
    std::string placement_;
    int defence_;

public:
    Equipment() = default;
    ~Equipment() override = default;

    [[nodiscard]] std::string get_placement() const;

    [[nodiscard]] int get_defence() const;

    void be_loaded(json data) override;

    json be_saved() const override;
};


#endif //LAB3_EQUIPMENT_H
