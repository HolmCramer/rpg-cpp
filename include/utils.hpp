#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP
#include "character_classes.hpp"

enum Difficulty {
	LOWER = -1,
	NORMAL = 0,
	HIGHER = 1
};

void print_screen_seperator();

void clr_scr();

void set_terminal_size();

void continue_promt();

Enemy gen_enemy(int* round, int* difficulty);

int char_to_int(char c);

#endif //UTILS_HPP
