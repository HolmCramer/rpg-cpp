#include "../include/item_classes.hpp"
#include <string>


Items::Items(){
	//public:
	int level = 1;
	Rarity rarity = COMMON;
	std::string name = "default";
	int weight = 1;
	std::string description = "default";
}

Items::Items(
	int level,
	Rarity rarity,
	std::string name,
	int weight,
	std::string description
){
	this->level = level;
	this->rarity = rarity;
	this->name = name;
	this->weight = weight;
	this->description = description;		
}

Potions::Potions(
	int level,
	Rarity rarity,
	std::string name,
	int weight,
	std::string description,
	int health_value
): Items(
	level,
	rarity,
	name,
	weight,
	description
)
{	
	this->health_value = health_value;
}

void Potions::abstract() {int test=0};

class Equipment: public Items {
	public:
		GearSlot gear_slot = HEAD;
		
		Equipment(){};

		Equipment(
			int level,
			Rarity rarity,
			std::string name,
			int weight,
			std::string description,
			GearSlot gear_slot
		): Items(
			level,
			rarity,
			name,
			weight,
			description
		)
		{
			this->gear_slot = gear_slot;
		}

		virtual void abstract() = 0;
};


class Armor: public Equipment {
	public:
		ArmorType armor_type = CLOTH;
		int armor_value = 1;

		Armor(){};

		Armor(
			int level,
			Rarity rarity,
			std::string name,
			int weight,
			std::string description,
			GearSlot gear_slot,
			ArmorType armor_type,
			int armor_value
		): Equipment(
			level,
			rarity,
			name,
			weight,
			description,
			gear_slot
		){
			this->armor_type = armor_type;
			this->armor_value = armor_value;
		}

		virtual void abstract() override {}
};


class Weapon: public Equipment {
	public:
		int weapon_damage;

		Weapon() {};

		Weapon(
			int level,
			Rarity rarity,
			std::string name,
			int weight,
			std::string description,
			GearSlot gear_slot,
			int weapon_damage
		): Equipment(
			level,
			rarity,
			name,
			weight,
			description,
			gear_slot
		)
		{
			this->weapon_damage = weapon_damage;
		}

		virtual void abstract() override {}
};
