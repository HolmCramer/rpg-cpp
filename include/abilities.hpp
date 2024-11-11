#pragma once
#include <string>

class Ability {
    public:
    std::string name;
    int resource_cost;
    int resource_generation_amount;
    int base_damage;
    float damage_multiplier;

    Ability();

    Ability(
        std::string name,
        int resource_cost,
        int resource_generation_amount,
        int base_damage,
        float damage_multiplier);
};