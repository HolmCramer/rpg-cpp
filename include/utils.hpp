#ifndef UTILS
#define UTILS
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

Enemy gen_enemy(int round, int difficulty);

#endif //UTILS