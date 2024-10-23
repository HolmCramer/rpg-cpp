#ifndef GAME_HPP
#define GAME_HPP
#include "character_classes.hpp"

void damage_calc(Characters &attacker, Characters &defender);

bool combat(Player player, Enemy enemy);

int story_screen();

int status_screen();

int route_screen();

int combat_screen();

int loot_level_screen();

int run();

#endif //GAME_HPP
