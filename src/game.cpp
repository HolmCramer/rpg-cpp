#include <iostream>
#include "../include/character_classes.hpp"
#include "../include/utils.hpp"
#include <random>
#include <cmath>
#include "abilities.hpp"

int damage_calc(Characters* attacker, Characters* defender) {
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	int roll = dist(engine);
	bool crit_flag = roll <= attacker->crit_chance ? true : false;
	float raw_damage = crit_flag == true ? attacker->attackpower * attacker->crit_bonus / 100 : attacker->attackpower;
	int damage = raw_damage > defender->defense ? std::round(raw_damage-defender->defense) : 1;
	defender->update_current_health(-damage);
	if (crit_flag)
	{
		std::cout << attacker->name + " dealt *" + std::to_string(damage) + "* !CRITICAL DAMAGE! to " + defender->name + " bringing his HP down to " + defender->get_health_display_str() << std::endl;
	}
	else
	{
		std::cout << attacker->name + " dealt (" + std::to_string(damage) + ") Damage to " + defender->name + " bringing his HP down to " + defender->get_health_display_str() << std::endl;
	}
	return EXIT_SUCCESS;
}

bool combat(Player* player, Enemy* enemy)
{
	bool result = false;
	int ability;
	while (true)
	{
		player->print_stats();
		enemy->print_stats();
		ability = player->choose_ability();
		damage_calc(player, enemy);
		if (enemy->get_current_health() <= 0)
		{
			player->add_xp(enemy->get_xp());
			result = true;
			std::cout << "You defeated " << enemy->name << "!" << std::endl;
			break;
		}
		continue_promt();
		print_screen_seperator();
		enemy->print_stats();
		enemy->choose_ability();
		damage_calc(enemy, player);
		if (player->get_current_health() <= 0)
		{
			result = false;
			std::cout << "You were defeated by " << enemy->name << "!" << std::endl;
			break;
		}
		continue_promt();
		print_screen_seperator();
	}
	return result;
}

int story_screen(int* round)
{
	print_screen_seperator();
	std::cout << "It's round " << std::to_string(*round) << ", story will be added!" << std::endl;
	continue_promt();
	return EXIT_SUCCESS;
}

int status_screen(int* round, Player* player)
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

int difficulty_option(int* difficulty)
{
	std::string input;
	std::cout << "The current difficulty level is at " << std::to_string(*difficulty) << std::endl;
	std::cout << "Choose the difficulty level for the next round:\n\t+\t: increase the difficulty level\n\t-\t: lower the difficulty level\n\tEnter\t: remain at current level\n>>> " << std::flush;
	while (true)
	{
		getline(std::cin, input);
		if (std::cin.good())
		{
			if (input.length() == 1 && input[0] == '+')
			{
				*difficulty += 1;
				std::cout << "You raised the difficulty level to " << std::to_string(*difficulty) << std::endl;
				return EXIT_SUCCESS;
			}
			else if (input.length() == 1 && input[0] == '-')
			{
				*difficulty -= 1;
				std::cout << "You lowered the difficulty level to " << std::to_string(*difficulty) << std::endl;
				return EXIT_SUCCESS;
			}
			else if (input.length() == 0)
			{
				std::cout << "You remain at the difficulty level of " << std::to_string(*difficulty) << std::endl;
				return EXIT_SUCCESS;
			}
			else
			{
				std::cout << "Enter a valid option:\n>>> " << std::flush;
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter a valid option:\n>>> " << std::flush;
		}
	}
}

int rest_option(Player* player, bool* rest_flag)
{
	std::string input;
	std::cout << "Do you want to rest and heal to full health?(y/n):\n>>> " << std::flush;
	while (true)
	{
		
		getline(std::cin, input);
		if (std::cin.good())
		{
			if (input.length() == 1 && input[0] == 'y')
			{
				player->set_current_health_to_max_health();
                *rest_flag = true;
                return EXIT_SUCCESS;
			}
			else if (input.length() == 1 && input[0] == 'n')
			{
				*rest_flag = false;
                return EXIT_SUCCESS;
			}
			else
			{
				std::cout << "Enter either y or n!\n>>> " << std::flush;
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter either y or n!\n>>> " << std::flush;
		}
	}
}

int route_screen
(
	int* round,
	int* difficulty,
	bool* rest_flag,
	Player* player
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
			difficulty_option(difficulty);
		}
		return EXIT_SUCCESS;
	}
}

int combat_screen(int* round, int* difficulty, Player* player, Enemy* enemy, bool* alive_flag)
{
	print_screen_seperator();
	*alive_flag = combat(player, enemy);
	continue_promt();
	return EXIT_SUCCESS;
}

int loot_level_screen(Player* player)
{
	print_screen_seperator();
	player->skill_up();
	continue_promt();
	return EXIT_SUCCESS;
}

bool quit_or_continue(bool* run)
{
	std::string input;
	while (true)
	{
		getline(std::cin, input);
		if (std::cin.good())
		{
			if (input.length() == 1 && input[0] == 'q')
			{
				std::cout << "You quit the game!" << std::endl;
				*run = false;
				return EXIT_SUCCESS;
			}
			else if (input.length() == 0)
			{
				return EXIT_SUCCESS;
			}
			else
			{
				std::cout << "Press q to quit or enter to continue!\n>>> " << std::flush;
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter q or press enter!:\n>>> " << std::flush;
		}
	}
}

int run() {
	bool run = true;
	Player player;
	int round = 1;
	bool rest_flag = false;
	int difficulty = 0;
	bool alive_flag = true;
	Enemy enemy;

	player.prompt_set_player_name();

	Ability normal_attack = Ability("[Normal Attack]", 0, 20, 0, 0);
	Ability heavy_attack = Ability("[Heavy Attack]", 30, 0, 5, 1.2);

	while (run)
	{
		// clr_scr();
		// story_screen(&round);
		status_screen(&round, &player);
		route_screen(&round, &difficulty, &rest_flag, &player);
		if (rest_flag == false)
		{
			enemy = gen_enemy(&round, &difficulty);
			combat_screen(&round, &difficulty, &player, &enemy, &alive_flag);
			if (alive_flag == false)
			{
				std::cout << "You lost!" << std::endl;
				break;
			}
			loot_level_screen(&player);
		}
		round++;
		
		std::cout << "gameloop_input, press q to quit or enter to continue:\n>>> " << std::flush;
		
		quit_or_continue(&run);
	}
	return EXIT_SUCCESS;
}
