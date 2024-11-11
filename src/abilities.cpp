#include "abilities.hpp"

Ability::Ability() {}

Ability::Ability(
    std::string name,
    int resource_cost,
    int resource_generation_amount,
    int base_damage,
    float damage_multplier)
    {
    this->name = name;
    this->resource_cost = resource_cost;
    this->resource_generation_amount= resource_generation_amount;
    this->base_damage = base_damage;
    this->damage_multplier = damage_multplier;
    }