//
// Created by vanish2 on 06.12.23.
//

#ifndef LAB3_OBJECT_H
#define LAB3_OBJECT_H


#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Object {
protected:
    std::string name;

public:
    Object() = default;
    virtual ~Object() = default;

    explicit Object(const std::string &name);

    [[nodiscard]] std::string get_name() const;

    void set_name(const std::string& new_name);

    virtual void be_loaded(json data);

    [[nodiscard]] virtual json be_saved() const;
};


#endif //LAB3_OBJECT_H
