//
// Created by vanish2 on 06.12.23.
//
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Potion.h"

#include <iostream>

TEST_CASE("PotionConstructor") {
    SECTION("Default") {
        Potion p;
        REQUIRE(p.get_name().empty());
        Primary params;
        REQUIRE(p.get_potion_effect() == params);
    }
}

TEST_CASE("PotionMethods") {
    SECTION("Setters"){
        Potion p;
        Primary params = {0, 0, 1, 1, 0};
        p.set_potion_effect(params);
        REQUIRE(p.get_potion_effect() == params);
    }
    SECTION("Loading") {
        std::ifstream file("files/potion.json");
        json data = json::parse(file);
        file.close();

        Primary params = {0, 0, 0, 10, 0};



        Potion p;
        p.be_loaded(data);

        /*std::cout <<
        p.get_potion_effect().power << " " <<
        p.get_potion_effect().ability << " " <<
        p.get_potion_effect().endurance << " " <<
        p.get_potion_effect().health << " " <<
        p.get_potion_effect().health_limit << " " <<
        std::endl;*/

        REQUIRE(p.get_name() == "Healing potion");
        REQUIRE(p.get_potion_effect() == params);
    }
}

