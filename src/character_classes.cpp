#include "../include/character_classes.hpp"
#include <optional>
#include <string>
#include <iostream>
#include "../include/item_classes.hpp"
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <array>
#include "../include/utils.hpp"


Gear::Gear(){}

Gear::Gear
(
	Armor head,
	Armor shoulders,
	Armor chest,
	Armor legs,
	Armor feet,
	Weapon mainhand,
	Weapon offhand
)
{
	this->head = head;
	this->shoulders = shoulders;
	this->chest = chest;
	this->legs = legs;
	this->feet = feet;
	this->mainhand = mainhand;
	this->offhand = offhand;
}

bool Gear::is_equipped(GearSlot gear_slot)
{
	bool bool_result = false;
	switch (gear_slot)
	{
		case HEAD:
			if (head.has_value())
			{
				bool_result = true;
			}
			break;
		case SHOULDERS:
			if (shoulders.has_value())
			{
				bool_result = true;
			}
			break;
		case CHEST:
			if (chest.has_value())
			{
				bool_result = true;
			}
			break;
		case LEGS:
			if (legs.has_value())
			{
				bool_result = true;
			}
			break;
		case FEET:
			if (feet.has_value())
			{
				bool_result = true;
			}
			break;
		case MAINHAND:
			if (mainhand.has_value())
			{
				bool_result = true;
			}
			break;
		case OFFHAND:
			if (offhand.has_value())
			{
				bool_result = true;
			}
			break;
		default:
			std::cout << "Couldn't match inputtype with any equipment..." << std::endl;
	}
	return bool_result;
}

Equipment* Gear::get_gear(GearSlot gear_slot)
{
	Equipment* gear_object = nullptr;
	switch (gear_slot)
	{
		case HEAD:
			if (this->head.has_value())
			{
				gear_object = &this->head.value();
			}
			break;
		case SHOULDERS:
			if (this->shoulders.has_value())
			{
				gear_object = &this->shoulders.value();
			}
			break;
		case CHEST:
			if (this->chest.has_value())
			{
				gear_object = &this->chest.value();
			}
			break;
		case LEGS:
			if (this->legs.has_value())
			{
				gear_object = &this->legs.value();
			}
			break;
		case FEET:
			if (this->feet.has_value())
			{
				gear_object = &this->feet.value();
			}
			break;
		case MAINHAND:
			if (this->mainhand.has_value())
			{
				gear_object = &this->mainhand.value();
			}
			break;
		case OFFHAND:
			if (this->offhand.has_value()) 
			{
				gear_object = &this->offhand.value();
			}
			break;
		default:
			std::cout << "Couldn't match inputtype with any equipment..." << std::endl;
	}
	return gear_object;
}


Characters::Characters()
{
	this->name = "default";
	this->level = 1;
	this->skillpoints = 1;
	this->xp = 10;
	this->capacity = 100;
	this->stamina = 1;
	this->max_health = 10;
	this->current_health = 10;
	this->max_rage = 100;
	this->current_rage = 0;
	this->energy = 100;
	this->strength = 1;
	this->crit_chance = 1;
	this->crit_bonus = 200;
	this->attackpower = 2;
	this->defense = 0;
	this->gear = Gear();
	this->inventory;
	this->abilities.push_back("Normal Attack");
	this->abilities.push_back("Hard Attack");
	this->update_atp();
	this->update_max_health();
	this->update_crit();
}

Characters::Characters
(
	std::string name,
	int level,
	int skillpoints,
	int xp,
	int capacity,
	int stamina,
	int max_health,
	int current_health,
	int max_rage,
	int current_rage,
	int energy,
	int strength,
	int crit_chance,
	int crit_bonus,
	int attackpower,
	int defense
)
{
	this->name = name;
	this->level = level;
	this->skillpoints = skillpoints;
	this->xp = xp;
	this->capacity = capacity;
	this->stamina = stamina;
	this->max_health = max_health;
	this->current_health = current_health;
	this->max_rage = max_rage;
	this->current_rage = current_rage;
	this->energy = energy;
	this->strength = strength;
	this->crit_chance = crit_chance;
	this->crit_bonus = crit_bonus;
	this->attackpower = attackpower;
	this->defense = defense;
	this->update_atp();
	this->update_max_health();
	this->update_crit();
}

Characters::Characters
(
	std::string name,
	int level,
	int skillpoints,
	int xp,
	int stamina,
	int strength,
	int crit_chance
)
{
	this->name = name;
	this->level = level;
	this->skillpoints = skillpoints;
	this->xp = xp;
	this->capacity = 100;
	this->stamina = stamina;
	this->max_health = 10 * stamina;
	this->current_health = max_health;
	this->max_rage = 100;
	this->current_rage = 0;
	this->energy = 100;
	this->strength = strength;
	this->attackpower = 2 * strength;
	this->crit_chance = crit_chance;
	this->crit_bonus = 200;
	this->defense = 0;
	this->gear = Gear();
	this->inventory;
	this->abilities.push_back("Normal Attack");
	this->abilities.push_back("Hard Attack");
	this->update_atp();
	this->update_max_health();
	this->update_crit();
}

void Characters::print_name()
{
	std::cout << name << std::endl;
}

void Characters::update_atp()
{
	this->attackpower = this->strength * 2;
}

void Characters::calc_crit()
{
	if (this->crit_chance > 50)
	{
		this->crit_chance -= this->crit_chance - 50;
	}
}

void Characters::calc_crit_bonus()
{
	if (this->crit_chance > 50)
	{
		this->crit_bonus += this->crit_chance - 50;
	}
}

void Characters::update_crit()
{
	this->calc_crit_bonus();
	this->calc_crit();
}

void Characters::increment_capacity()
{
	this->capacity += 1;
}

void Characters::increment_level()
{
	this->level += 1;
	if (this->level % 2 == 0)
	{
		this->increment_capacity();
	}
}

int Characters::get_skillpoints()
{
	return this->skillpoints;
}

void Characters::increment_skillpoints()
{
	this->skillpoints += 1;
}

void Characters::decrement_skillpoints()
{
	this->skillpoints = this->skillpoints - 1 >= 1 ? this->skillpoints - 1 : 0;
}

int Characters::get_xp()
{
	return this->xp;
}

void Characters::add_xp(int xp)
{
	this->xp += xp;
	if (this->xp / 10 > this->level)
	{
		this->increment_level();
		this->increment_skillpoints();
	}
}

int Characters::get_stamina()
{
	return this->stamina;
}

void Characters::increment_stamina()
{
	this->stamina += 1;
}

int Characters::get_max_health()
{
	return this->max_health;
}

void Characters::update_max_health()
{
	this->max_health = 10 * this->stamina;
}

int Characters::get_current_health()
{
	return this->current_health;
}

void Characters::set_current_health_to_max_health()
{
	this->current_health = this->max_health;
}

void Characters::update_current_health(int value)
{
	if (this->current_health + value >= this->max_health)
	{
		this->current_health = this->max_health;
	}
	else if (this->current_health + value < 0)
	{
		this->current_health = 0;
	}
	else
	{
		this->current_health += value;
	}
}

std::string Characters::get_health_display_str()
{
	std::string health_display = "(" + std::to_string(this->current_health) + "/" + std::to_string(this->max_health) + ")";
	return health_display;
}

int Characters::get_max_rage()
{
	return this->max_rage;
}

void Characters::add_max_rage(int rage)
{
	this->max_rage += rage;
}

int Characters::get_current_rage()
{
	return this->current_rage;
}

void Characters::modify_current_rage(int rage)
{
	if (this->current_rage + rage <= this->max_rage && this->current_rage + rage >= 0)
	{
		this->current_rage += rage;
	}
	else if (this->current_rage + rage < 0)
	{
		this->current_rage = 0;
	}
	else if (this->current_rage + rage > this->max_rage)
	{
		this->current_rage = this->max_rage;
	}
}

void Characters::print_equipment()
{
	for (int i = 0; i < static_cast<int>(GearSlot::GEAR_SLOT_COUNT); i++)
	{
		GearSlot slot = static_cast<GearSlot>(i);
		if (this->gear.is_equipped(slot))
		{
			//std::cout << 
		}
	}
}

std::vector<Items*> Characters::get_inventory()
{
	return this->inventory;
}

void Characters::add_to_inventory(Items* item)
{
	this->inventory.push_back(item);
	std::cout << item->name + " has been added to the inventory" << std::endl;
}

void Characters::print_inventory_names()
{
	std::cout << "Inventory: " << std::endl;
	if (this->inventory.size() == 0)
	{
		std::cout << "\tempty" << std::endl;
	}
	for (Items* item: this->inventory)
	{
		std::cout << "\t" << item->name << std::endl;
	}
}

void Characters::print_stats()
{
	std::cout << "Name: " + this->name + ", Level: " + std::to_string(this->level) + ", XP: " + std::to_string(this->xp) + ", Capacity: " + std::to_string(this->capacity) + ", Attackpower: " + std::to_string(this->attackpower) + ", Health: " + this->get_health_display_str() + ", Energy: " + std::to_string(this->energy) + ", Stamina: " + std::to_string(this->stamina) + ", Strength: " + std::to_string(this->strength) + ", Crit chance: " + std::to_string(this->crit_chance) + "%, Crit damage bonus: " + std::to_string(this->crit_bonus) + "%" << std::endl;
}


Enemy::Enemy(){}

Enemy::Enemy
(
	std::string name,
	int level,
	int skillpoints,
	int xp,
	int capacity,
	int stamina,
	int max_health,
	int current_health,
	int max_rage,
	int current_rage,
	int energy,
	int strength,
	int crit_chance,
	int crit_bonus,
	int attackpower,
	int defense
): Characters
(
	name,
	level,
	skillpoints,
	xp,
	capacity,
	stamina,
	max_health,
	current_health,
	max_rage,
	current_rage,
	energy,
	strength,
	crit_chance,
	crit_bonus,
	attackpower,
	defense
) {}

Enemy::Enemy
(
	std::string name,
	int level,
	int skillpoints,
	int xp,
	int stamina,
	int strength,
	int crit_chance
): Characters
(
	name,
	level,
	skillpoints,
	xp,
	stamina,
	strength,
	crit_chance
) {}

void Enemy::print_name()
{
	std::cout << name << "\n";
}

int Enemy::choose_ability()
{
	std::cout << this->name + " is choosing its Ability!" << std::endl;
	std::string ability_text = "";
	for (int i = 0; i < this->abilities.size(); i++) 
	{
		ability_text.append("\t" + std::to_string(i+1) + " - " + this->abilities[i] + "\n");
	}
	std::cout << ability_text;
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(0, this->abilities.size()-1);
	int attack_roll = dist(engine);
	std::cout << std::to_string(attack_roll + 1) << std::endl;
	std::cout << std::to_string(attack_roll + 1) + " - " + this->abilities[attack_roll] + " is used!" << std::endl;
	return attack_roll;
}



Player::Player(){}

Player::Player(std::string name): Characters() {this->name = name;}

Player::Player
(
	std::string name,
	int level,
	int skillpoints,
	int xp,
	int capacity,
	int stamina,
	int max_health,
	int current_health,
	int max_rage,
	int current_rage,
	int energy,
	int strength,
	int crit_chance,
	int crit_bonus,
	int attackpower,
	int defense
): Characters
(
	name,
	level,
	skillpoints,
	xp,
	capacity,
	stamina,
	max_health,
	current_health,
	max_rage,
	current_rage,
	energy,
	strength,
	crit_chance,
	crit_bonus,
	attackpower,
	defense
) {}

void Player::print_name()
{
	std::cout << name << std::endl;
}

void Player::prompt_set_player_name()
{
	std::cout << "Enter your nickname: ";
	std::cin >> this->name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Player::skill_up()
{
	int player_input;
	while (this->skillpoints > 0)
	{
		std::cout << "Choose Attribute to level up:\n 1 : Increase current Stamina[" + std::to_string(this->stamina) + "] by 1\n 2 : Increase current Strength[" + std::to_string(this->strength) + "] by 1\n 3 : Increase current Crit chance[" + std::to_string(this->crit_chance) + "%] by 1%" << std::endl;
		std::cin >> player_input;
		std::cin.ignore();
		switch (player_input)
		{
			case 1:
				this->increment_stamina();
				this->update_max_health();
				this->update_current_health(10);
				this->decrement_skillpoints();
				std::cout << "You increased your Stamina to " << std::to_string(this->stamina) << " resulting in " << std::to_string(this->max_health) << " max HP" << std::endl;
				break;
			case 2:
				this->strength += 1;
				this->update_atp();
				this->decrement_skillpoints();
				std::cout << "You increased your Strength to " << std::to_string(this->strength) << " resulting in " << std::to_string(this->attackpower) << " ATP" << std::endl;
				break;
			case 3:
				this->crit_chance += 1;
				this->update_crit();
				this->decrement_skillpoints();
				std::cout << "You increased your Crit chance to " << std::to_string(this->crit_chance) << "%" << " and " << std::to_string(this->crit_bonus) << "%" << " Crit damage bonus" << std::endl;
				break;
			default:
				std::cout << "Enter a valid number!" << std::endl;
				break;
		}
	}
}

int Player::choose_ability()
{
	std::cout << "How do you want to attack?" << std::endl;
	std::string ability_text = "";
	std::array<int,6> options;
	for (int i = 0; i < this->abilities.size(); i++)
	{
		ability_text.append("\t" + std::to_string(i+1) + " - " + this->abilities[i] + "\n");
		options[i] = i+1;
	}
	char input;
	int attack;
	while (true)
	{
		std::cout << ability_text;
		std::cin.get(input);
		std::cin.ignore();
		attack = char_to_int(input);
		if (std::find(options.begin(), options.end(), attack) != options.end())
		{
			break;
		}
		else 
		{
			std::cout << "Enter a valid number!" << std::endl;
		}
	}
	std::cout << std::to_string(attack) << " - " << this->abilities[attack-1] << " is used!" << std::endl;
	return attack;
}
