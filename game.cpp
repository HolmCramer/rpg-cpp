#include <iostream>
#include "character_classes.cpp"
#include "utils.cpp"
#include <random>
#include <cmath>

void damage_calc(Characters &attacker, Characters &defender) {
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	int roll = dist(engine);
	bool crit_flag = roll <= attacker.crit_chance ? true : false;
	float damage = crit_flag == true ? attacker.attackpower * attacker.crit_bonus / 100 : attacker.attackpower;
	damage = damage > defender.defense ? std::round(damage-defender.defense) : 1;
	//missing some more stuff...
}

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
	Enemies enemy = Enemies("Enemy", 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 15);
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

	std::cout << holmo.get_health_display_str();

	return 0;
}
