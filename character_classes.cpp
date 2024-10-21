#include <optional>
#include <string>
#include <iostream>
#include "item_classes.cpp"

class Gear {
	public:
	std::optional<Armor> head;
	std::optional<Armor> shoulders;
	std::optional<Armor> chest;
	std::optional<Armor> legs;
	std::optional<Armor> feet;
	std::optional<Weapon> mainhand;
	std::optional<Weapon> offhand;
	
	Gear(){};

	Gear(
		Armor head,
		Armor shoulders,
		Armor chest,
		Armor legs,
		Armor feet,
		Weapon mainhand,
		Weapon offhand
	){
		this->head = head;
		this->shoulders = shoulders;
		this->chest = chest;
		this->legs = legs;
		this->feet = feet;
		this->mainhand = mainhand;
		this->offhand = offhand;

	}

	bool is_equipped(GearSlot gearslot) {
		bool bool_result = false;
		switch (gearslot) {
			case HEAD:
				bool_result = head.has_value() ? true : false; 
				break;
			case SHOULDERS:
				bool_result = shoulders.has_value() ? true : false; 
				break;
			case CHEST:
				bool_result = chest.has_value() ? true : false; 
				break;
			case LEGS:
				bool_result = legs.has_value() ? true : false; 
				break;
			case FEET:
				bool_result = feet.has_value() ? true : false; 
				break;
			case MAINHAND:
				bool_result = mainhand.has_value() ? true : false; 
				break;
			case OFFHAND:
				bool_result = offhand.has_value() ? true : false; 
				break;
			default:
				std::cout << "Couldn't match inputtype with any equipment...";
		}
		return bool_result;
	}
};

class Characters {
	public:
	std::string name = "default";
	int level = 1;
	int skillpoints = 1;
	int xp = 10;
	int capacity = 100;
	int stamina = 1;
	int max_health = 10;
	int current_health = 10;
	int max_rage = 100;
	int current_rage = 0;
	int energy = 100;
	int strength = 1;
	int crit_chance = 1;
	int crit_bonus = 200;
	int attackpower = 2;
	int defense = 0;
	
	Characters () {}

	Characters (
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
	}
	
	virtual void abstract() = 0;

	void print_name() {
		std::cout << name << "\n";
	}
};

class Enemies: Characters {
	public:

	Enemies(){}

	Enemies(
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
		): Characters(
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
		)
		{
		}
	
	virtual void abstract() override {};

	void print_name() {
		std::cout << name << "\n";
	}
};


class Player: public Characters {
	public:

	Player(){}

	Player(
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
		): Characters(
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
		){
		}

	virtual void abstract() override {};
	void print_name() {
		std::cout << name << "\n";
	}
};
