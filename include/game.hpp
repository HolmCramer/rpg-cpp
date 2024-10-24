#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include "character_classes.hpp"

int damage_calc(Characters *attacker, Characters *defender);

bool combat(Player *player, Enemy *enemy);

int story_screen(int *round);

int status_screen(int *round, Player *player);

int difficulty_option(int *difficulty);

int rest_option(Player *player, bool *rest_flag);

int route_screen
(
    int *round,
	int *difficulty,
	bool *rest_flag,
	Player *player
);

bool combat_screen
(
    int *round,
    int *difficulty,
    Player *player
);

int loot_level_screen(Player *player);

int run();

#endif //GAME_HPP
