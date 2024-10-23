#include "../include/item_classes.hpp"
#include <string>


Items::Items()
{
	int level = 1;
	Rarity rarity = COMMON;
	std::string name = "default";
	int weight = 1;
	std::string description = "default";
}

Items::Items
(
	int level,
	Rarity rarity,
	std::string name,
	int weight,
	std::string description
)
{
	this->level = level;
	this->rarity = rarity;
	this->name = name;
	this->weight = weight;
	this->description = description;
}

Items::~Items() {}

Potions::Potions
(
	int level,
	Rarity rarity,
	std::string name,
	int weight,
	std::string description,
	int health_value
): Items
(
	level,
	rarity,
	name,
	weight,
	description
)
{	
	this->health_value = health_value;
}

Potions::~Potions() {}

Equipment::Equipment()
{
	GearSlot gear_slot = HEAD;
};

Equipment::Equipment
(
	int level,
	Rarity rarity,
	std::string name,
	int weight,
	std::string description,
	GearSlot gear_slot
): Items
(
	level,
	rarity,
	name,
	weight,
	description
)
{
	this->gear_slot = gear_slot;
}

Equipment::~Equipment() {};

Armor::Armor()
{
	ArmorType armor_type = CLOTH;
	int armor_value = 1;
};

Armor::Armor
(
	int level,
	Rarity rarity,
	std::string name,
	int weight,
	std::string description,
	GearSlot gear_slot,
	ArmorType armor_type,
	int armor_value
): Equipment
(
	level,
	rarity,
	name,
	weight,
	description,
	gear_slot
)
{
	this->armor_type = armor_type;
	this->armor_value = armor_value;
}

Armor::~Armor() {}

Weapon::Weapon()
{
	int weapon_damage;
};

Weapon::Weapon
(
	int level,
	Rarity rarity,
	std::string name,
	int weight,
	std::string description,
	GearSlot gear_slot,
	int weapon_damage
): Equipment
(
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

Weapon::~Weapon() {}
