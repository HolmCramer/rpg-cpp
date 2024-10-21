#include <optional>
#include <string>
#include <iostream>
#include "item_classes.cpp"
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
	
	Gear(){}

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

	bool is_equipped(GearSlot gear_slot) {
		bool bool_result = false;
		switch (gear_slot) {
			case HEAD:
				if (head.has_value()) {
					bool_result = true;
				}
				break;
			case SHOULDERS:
				if (shoulders.has_value()) {
					bool_result = true;
				}
				break;
			case CHEST:
				if (chest.has_value()) {
					bool_result = true;
				}
				break;
			case LEGS:
				if (legs.has_value()) {
					bool_result = true;
				}
				break;
			case FEET:
				if (feet.has_value()) {
					bool_result = true;
				}
				break;
			case MAINHAND:
				if (mainhand.has_value()) {
					bool_result = true;
				}
				break;
			case OFFHAND:
				if (offhand.has_value()) {
					bool_result = true;
				}
				break;
			default:
				std::cout << "Couldn't match inputtype with any equipment...";
		}
		return bool_result;
	}

	Equipment* get_gear(GearSlot gear_slot) {
		Equipment* gear_object = nullptr;
		switch (gear_slot) {
			case HEAD:
				if (this->head.has_value()) {
					gear_object = &this->head.value();
				}
				break;
			case SHOULDERS:
				if (this->shoulders.has_value()) {
					gear_object = &this->shoulders.value();
				}
				break;
			case CHEST:
				if (this->chest.has_value()) {
					gear_object = &this->chest.value();
				}
				break;
			case LEGS:
				if (this->legs.has_value()) {
					gear_object = &this->legs.value();
				}
				break;
			case FEET:
				if (this->feet.has_value()) {
					gear_object = &this->feet.value();
				}
				break;
			case MAINHAND:
				if (this->mainhand.has_value()) {
					gear_object = &this->mainhand.value();
				}
				break;
			case OFFHAND:
				if (this->offhand.has_value()) {
					gear_object = &this->offhand.value();
				}
				break;
			default:
				std::cout << "Couldn't match inputtype with any equipment...";
		}
		return gear_object;
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
	Gear gear;
	std::vector<Items> inventory;
	
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

	void update_atp() {
		this->attackpower = this->strength * 2;
	}

	void calc_crit() {
		if (this->crit_chance > 50) {
			this->crit_chance -= this->crit_chance - 50;
		}
	}

	void calc_crit_bonus() {
		if (this->crit_chance > 50) {
			this->crit_bonus += this->crit_chance - 50;
		}
	}

	void update_crit() {
		this->calc_crit_bonus();
		this->calc_crit();
	}

	void increment_capacity() {
		this->capacity += 1;
	}

	void increment_level() {
		this->level += 1;
		if (this->level % 2 == 0) {
			this->increment_capacity();
		}
	}

	int get_skillpoints() {
		return this->skillpoints;
	}

	void increment_skillpoints() {
		this->skillpoints += 1;
	}

	void decrement_skillpoints() {
		this->skillpoints = this->skillpoints - 1 >= 1 ? this->skillpoints - 1 : 0;
	}

	int get_xp() {
		return this->xp;
	}

	void add_xp(int xp) {
		this->xp += xp;
		if (this->xp / 10 > this->level) {
			this->increment_level();
			this->increment_skillpoints();
		}
	}

	int get_stamina() {
		return this->stamina;
	}

	void increment_stamina() {
		this->stamina += 1;
	}

	int get_max_health() {
		return this->max_health;
	}

	void update_max_health() {
		this->max_health = 10 * this->stamina;
	}

	int get_current_health() {
		return this->current_health;
	}

	void set_current_health_to_max_health() {
		this->current_health = this->max_health;
	}

	void update_current_health(int value) {
		if (this->current_health + value >= this->max_health) {
			this->current_health = this->max_health;
		}
		else if (this->current_health + value < 0) {
			this->current_health = 0;
		}
		else {
			this->current_health += value;
		}
	}

	std::string get_health_display_str() {
		std::string health_display = "(" + std::to_string(this->current_health) + "/" + std::to_string(this->max_health) + ")";
		return health_display;
	}

	int get_max_rage() {
		return this->max_rage;
	}

	void add_max_rage(int rage) {
		this->max_rage += rage;
	}

	int get_current_rage() {
		return this->current_rage;
	}

	void modify_current_rage(int rage) {
		if (this->current_rage + rage <= this->max_rage && this->current_rage + rage >= 0) {
			this->current_rage += rage;
		}
		else if (this->current_rage + rage < 0) {
			this->current_rage = 0;
		}
		else if (this->current_rage + rage > this->max_rage) {
			this->current_rage = this->max_rage;
		}
	}

	void print_equipment() {
		for (int i; i < static_cast<int>(GearSlot::GEAR_SLOT_COUNT); i++) {
			GearSlot slot = static_cast<GearSlot>(i);
			if (this->gear.is_equipped(slot)) {
				//std::cout << 
			}
		}
	}

	std::vector<Items> get_inventory() {
		std::vector<Items> result_ptr = this->inventory;
		return this->inventory;
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
