#include <string>
using namespace std;

enum ArmorType {
	CLOTH,
	LEATHER,
	MAIL,
	PLATE
};

enum Rarity {
	COMMON,
	RARE,
	EPIC,
	LEGENDARY	
};

enum GearSlot {
	HEAD,
	SHOULDERS,
	CHEST,
	LEGS,
	FEET,
	MAINHAND,
	OFFHAND
};

class Items {
	public:
		int level = 1;
		Rarity rarity = COMMON;
		string name = "default";
		int weight = 1;
		string description = "default";
		
		Items(){}

		Items(
			int level,
			Rarity rarity,
			string name,
			int weight,
			string description
		){
			this->level = level;
			this->rarity = rarity;
			this->name = name;
			this->weight = weight;
			this->description = description;		
		}

		virtual void abstract() = 0;
};


class Potions: public Items {
	public:
		int health_value;
		Potions (
			int level,
			Rarity rarity,
			string name,
			int weight,
			string description,
			int health_value
		){
			this->level = level;
			this->rarity = rarity;
			this->name = name;
			this->weight = weight;
			this->description = description;		
			this->health_value = health_value;
		}

		virtual void abstract() override {};
};


class Equipment: public Items {
	public:
		GearSlot gear_slot = HEAD;
		
		Equipment(){};

		Equipment (
			int level,
			Rarity rarity,
			string name,
			int weight,
			string description,
			GearSlot gear_slot
		){
			this->level = level;
			this->rarity = rarity;
			this->name = name;
			this->weight = weight;
			this->description = description;		
			this->gear_slot = gear_slot;
		}

		virtual void abstract() = 0;
};


class Armor: public Equipment {
	public:
		ArmorType armor_type = CLOTH;
		int armor_value = 1;
	
		Armor(){};

		Armor (
			int level,
			Rarity rarity,
			string name,
			int weight,
			string description,
			GearSlot gear_slot,
			ArmorType armor_type,
			int armor_value
		){
			this->level = level;
			this->rarity = rarity;
			this->name = name;
			this->weight = weight;
			this->description = description;		
			this->gear_slot = gear_slot;
			this->armor_type = armor_type;
			this->armor_value = armor_value;
		}

		virtual void abstract() override {};
};


class Weapon: public Equipment {
	public:
		int level = 1;
		Rarity rarity = COMMON;
		string name = "default";
		int weight = 1;
		string description = "default";

		Weapon() {};

		Weapon (
			int level,
			Rarity rarity,
			string name,
			int weight,
			string description
		){
			this->level = level;
			this->rarity = rarity;
			this->name = name;
			this->weight = weight;
			this->description = description;		
		}

		virtual void abstract() override {};
};
