#include <iostream>
#include "character_classes.cpp"
#include "utils.cpp"
using namespace std;

int story_screen() {
	return 0;
}

int status_screen() {
	return 0;
}

int route_screen() {
	return 0;
}

int combat_screen() {
	return 0;
}

int loot_level_screen() {
	return 0;
}

int run() {
	Player holmo = Player("holmo", 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 15);
	Enemies enemy = Enemies(1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 15);
	int difficulty = 0;
	int round = 0;
	bool rest_flag = false;
	while(true) {
		clr_scr();
		story_screen();
		status_screen();
		route_screen();
		combat_screen();
		loot_level_screen();
		holmo.print_name();
		enemy.print_name();
		break;
	}
	return 0;
}
