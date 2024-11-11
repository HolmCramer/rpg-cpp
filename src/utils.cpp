#include "../include/utils.hpp"
#include <iostream>
#include "../include/character_classes.hpp"
#include <random>
#include <cmath>


void print_screen_seperator()
{
	std::string seperator = "-";
	for (int i = 0; i < 115; i++)
	{
		seperator.append("-");
	}
	std::cout << seperator << "\n";
}

void clr_scr()
{
	std::cout << "\x1B[2J"; //cls
}

void set_terminal_size()
{
	std::cout << "\x1B[=18h";
}

void continue_promt()
{
	std::cout << "Press enter to continue: " << std::flush;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Enemy gen_enemy(int* round, int* difficulty)
{
	int level = *round + *difficulty;
	int skillpoints = level;
	int xp = level * 10;
	int capacity = 10 + (level / 2);
	int stamina = 1;
	int energy = 10;
	int strength = 1;
	int crit_chance = 1;
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(0, 2);
	int roll;
	dist(engine);
	while (skillpoints > 0)
	{
		switch (roll = dist(engine))
		{
			case 0:
				stamina += 1;
                skillpoints -= 1;
				break;
			case 1:
				strength += 1;
                skillpoints -= 1;
				break;
			case 2:
				crit_chance += 1;
                skillpoints -= 1;
				break;
			default:
				std::cout << "error assigning mob skillpoints" << std::endl;
		}
	}
	Enemy enemy = Enemy("Enemy", level, skillpoints, xp, capacity, stamina, strength, crit_chance);
	return enemy;
}
