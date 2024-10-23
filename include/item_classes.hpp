#ifndef ITEM_CLASSES_HPP
#define ITEM_CLASSES_HPP
#include <string>

enum ArmorType
{
	CLOTH,
	LEATHER,
	MAIL,
	PLATE,
	ARMOR_TYPE_COUNT
};

enum Rarity
{
	COMMON,
	RARE,
	EPIC,
	LEGENDARY,
	RARITY_COUNT
};

enum GearSlot
{
	HEAD,
	SHOULDERS,
	CHEST,
	LEGS,
	FEET,
	MAINHAND,
	OFFHAND,
	GEAR_SLOT_COUNT
};

class Items
{
	public:
	int level;
	Rarity rarity;
	std::string name;
	int weight;
	std::string description;

	Items();

	Items(
	int level,
	Rarity rarity,
	std::string name,
	int weight,
	std::string description
	);

	virtual void abstract() = 0;
};


class Potions: public Items
{
	public:
	int health_value;

	Potions
	(
		int level,
		Rarity rarity,
		std::string name,
		int weight,
		std::string description,
		int health_value
	);

	void abstract() override;
};


class Equipment: public Items
{
	public:
	GearSlot gear_slot;
		
	Equipment();

	Equipment
	(
		int level,
		Rarity rarity,
		std::string name,
		int weight,
		std::string description,
		GearSlot gear_slot
	);
};


class Armor: public Equipment
{
	public:
	ArmorType armor_type;
	int armor_value;

	Armor();

	Armor(
		int level,
		Rarity rarity,
		std::string name,
		int weight,
		std::string description,
		GearSlot gear_slot,
		ArmorType armor_type,
		int armor_value
	);

	void abstract() override;
};


class Weapon: public Equipment
{
	public:
	int weapon_damage;

	Weapon();

	Weapon(
		int level,
		Rarity rarity,
		std::string name,
		int weight,
		std::string description,
		GearSlot gear_slot,
		int weapon_damage
	);

	void abstract() override;
};

#endif //ITEM_CLASSES_HPP
