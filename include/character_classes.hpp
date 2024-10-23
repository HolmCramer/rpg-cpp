#ifndef CHARACTER_CLASSES_HPP
#define CHARACTER_CLASSES_HPP
#include <optional>
#include "item_classes.hpp"
#include <string>
#include <vector>

class Gear {
	public:
	std::optional<Armor> head;
	std::optional<Armor> shoulders;
	std::optional<Armor> chest;
	std::optional<Armor> legs;
	std::optional<Armor> feet;
	std::optional<Weapon> mainhand;
	std::optional<Weapon> offhand;
	
	Gear();

	Gear(
		Armor head,
		Armor shoulders,
		Armor chest,
		Armor legs,
		Armor feet,
		Weapon mainhand,
		Weapon offhand
	);

	bool is_equipped(GearSlot gear_slot);

	Equipment* get_gear(GearSlot gear_slot);
};

class Characters {
	public:
	std::string name;
	int level;
	int skillpoints;
	int xp;
	int capacity;
	int stamina;
	int max_health;
	int current_health;
	int max_rage;
	int current_rage;
	int energy;
	int strength;
	int crit_chance;
	int crit_bonus;
	int attackpower;
	int defense;
	Gear gear;
	std::vector<Items*> inventory;
	std::string abilities[8];
	
	Characters();

	Characters(
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
		);

	Characters(
			std::string name,
			int level,
			int skillpoints,
			int xp,
			int stamina,
			int strength,
			int crit_chance
		);

	//virtual void abstract();

	void print_name();

	void update_atp();

	void calc_crit();

	void calc_crit_bonus();

	void update_crit();

	void increment_capacity();

	void increment_level();

	int get_skillpoints();

	void increment_skillpoints();

	void decrement_skillpoints();

	int get_xp();

	void add_xp(int xp);

	int get_stamina();

	void increment_stamina();

	int get_max_health();

	void update_max_health();

	int get_current_health();

	void set_current_health_to_max_health();

	void update_current_health(int value);

	std::string get_health_display_str();

	int get_max_rage();

	void add_max_rage(int rage);

	int get_current_rage();

	void modify_current_rage(int rage);

	void print_equipment();

	std::vector<Items*> get_inventory();

	void add_to_inventory(Items* item);

	void print_inventory_names();

	void print_stats();
};

class Enemy: public Characters {
	public:
	Enemy();

	Enemy(
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
		);

		Enemy(
		std::string name,
		int level,
		int skillpoints,
		int xp,
		int stamina,
		int strength,
		int crit_chance
		);
	
	//virtual void abstract();

	void print_name();

	int choose_ability();
};


class Player: public Characters {
	public:
	Player();

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
		);

	//virtual void abstract();

	void print_name();

	void skill_up();

	int choose_ability();
};

#endif //CHARACTER_CLASSES_HPP
