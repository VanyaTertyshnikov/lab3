//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_ENCHANTED_H
#define LAB3_ENCHANTED_H

#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Enchanted{
private:
    std::string target_trait_;
    std::string avoid_trait_;
    int best_{};
    int worst_{};

public:
    Enchanted() = default;
    virtual ~Enchanted() = default;

     [[nodiscard]] std::string get_target_trait() const;

     [[nodiscard]] std::string get_avoid_trait() const;

     [[nodiscard]] int get_best() const;

     [[nodiscard]] int get_worst() const;

     int get_factor(const std::string& trait);

     void be_loaded(json data);
};


#endif //LAB3_ENCHANTED_H
