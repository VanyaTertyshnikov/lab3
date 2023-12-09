//
// Created by vanish2 on 10.12.23.
//

#ifndef LAB3_KEY_H
#define LAB3_KEY_H


#include <string>
#include <nlohmann/json.hpp>
using json =  nlohmann::json;

#include "Object.h"

class Key : public Object {
private:
    int amount_{};

public:
    Key() = default;
    ~Key() override = default;

    [[nodiscard]] int get_amount() const;

    void be_loaded(json data) override;

    json be_saved() const override;
};


#endif //LAB3_KEY_H
