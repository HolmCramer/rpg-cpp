#include <iostream>
#include "../include/character_classes.hpp"
#include "../include/utils.hpp"
#include <random>
#include <cmath>

int damage_calc(Characters *attacker, Characters *defender) {
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	int roll = dist(engine);
	bool crit_flag = roll <= attacker->crit_chance ? true : false;
	float damage = crit_flag == true ? attacker->attackpower * attacker->crit_bonus / 100 : attacker->attackpower;
	damage = damage > defender->defense ? std::round(damage-defender->defense) : 1;
	defender->update_current_health(-damage);
	if (crit_flag) 
	{
		std::cout << attacker->name + " dealt *" + std::to_string(damage) + "* !CRITICAL DAMAGE! to " + defender->name + "bringing his HP down to " + defender->get_health_display_str();
	}
	else 
	{
		std::cout << attacker->name + " dealt (" + std::to_string(damage) + ") Damage to " + defender->name + "bringing his HP down to " + defender->get_health_display_str(); 
	}
	return EXIT_SUCCESS;
}

bool combat(Player *player, Enemy *enemy)
{
	bool result = false;
	int ability;
	while (true)
	{
		player->print_stats();
		enemy->print_stats();
		ability = player->choose_ability();
		damage_calc(player, enemy);
		continue_promt();
		if (enemy->get_current_health() <= 0)
		{
			player->add_xp(enemy->get_xp());
			result = true;
			std::cout << "You defeated " << enemy->name << "!\n";
			break;
		}
		print_screen_seperator();
		enemy->print_stats();
		enemy->choose_ability();
		damage_calc(enemy, player);
		continue_promt();
		if (player->get_current_health() <= 0)
		{
			result = false;
			std::cout << "You were defeated by " << enemy->name << "!\n";
			break;
		}
		print_screen_seperator();
	}
	return result;
}

int story_screen(int *round)
{
	print_screen_seperator();
	std::cout << "It's round " << std::to_string(*round) << ", story will be added!\n";
	continue_promt();
	return EXIT_SUCCESS;
}

int status_screen(int *round, Player *player)
{
	print_screen_seperator();
	player->print_stats();
	if (*round == 1)
	{
		player->skill_up();
	}
	player->print_inventory_names();
	continue_promt();
	return EXIT_SUCCESS;
}

int difficulty_option(int *difficulty)
{
	std::string input;
	Difficulty option;
	std::cout << "The current difficulty level is at " << std::to_string(*difficulty) << "\n";
	while (true)
	{
		std::cout << "Choose the difficulty level for the next round:\n + : increase the difficulty level\n - : lower the difficulty level\n Enter : remain at current level\n";
		std::cin >> input;
		if (input == "+")
		{
			*difficulty += 1;
			std::cout << "You raised the difficulty level to " << std::to_string(*difficulty) << "\n";
			return EXIT_SUCCESS;
		}
		else if (input == "-")
		{
			*difficulty -= 1;
			std::cout << "You lowered the difficulty level to " << std::to_string(*difficulty) << "\n";
			return EXIT_SUCCESS;
		}
		else if (input == "")
		{
			std::cout << "You remain at the difficulty level of " << std::to_string(*difficulty) << "\n";
            return EXIT_SUCCESS;
		}
		else
		{
			std::cout << "Enter a valid option!\n";
		}
	}
}

int rest_option(Player *player, bool *rest_flag)
{
	std::string input;
	while (true)
	{
		std::cout << "Do you want to rest and heal to full health?(y/n)\n";
		std::cin >> input;
		if (input == "y")
		{
			player->set_current_health_to_max_health();
			*rest_flag = true;
			return EXIT_SUCCESS;
		}
		else if (input == "n")
		{
			*rest_flag = false;
			return EXIT_SUCCESS;
		}
		else
		{
			std::cout << "Enter a valid input!\n";
		}
	}
}

int route_screen
(
	int *round,
	int *difficulty,
	bool *rest_flag,
	Player *player
)
{
	if (*round == 1)
	{
		*rest_flag = false;
		return EXIT_SUCCESS;
	}
	print_screen_seperator();
	player->print_stats();
	if (*rest_flag == true)
	{
		*rest_flag = false;
		difficulty_option(difficulty);
		return EXIT_SUCCESS;
	}
	else
	{
		rest_option(player, rest_flag);
		if (*rest_flag == false)
		{
			*difficulty = difficulty_option(difficulty);
		}
		return EXIT_SUCCESS;
	}
}

bool combat_screen(int *round, int *difficulty, Player *player)
{
	print_screen_seperator();
	Enemy enemy = gen_enemy(round, difficulty);
	bool result = combat(player, &enemy);
	return result;
}

int loot_level_screen(Player *player)
{
	print_screen_seperator();
	player->skill_up();
	continue_promt();
	return EXIT_SUCCESS;
}

int run() {
	Player player = Player("holmo", 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 15);
	//Player holmo = Player();
	Enemy enemy = Enemy("Enemy", 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 15);
	int difficulty = 0;
	int round = 0;
	bool rest_flag = false;
	while(true)
	{
		clr_scr();
		story_screen(&round);
		status_screen(&round, &player);
		route_screen(&round , &difficulty , &rest_flag, &player);
		combat_screen(&round, &difficulty, &player);
		loot_level_screen(&player);
		player.print_name();
		enemy.print_name();
		std::cin.get();
		break;
	}

	std::cout << player.get_health_display_str();

	return 0;
}
