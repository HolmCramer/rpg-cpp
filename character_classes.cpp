#include <string>
#include <iostream>
using namespace std;

class Gear {
	public:
	string head;
	string shoulders;
	string chest;
	string legs;
	string feet;
	string mainhand;
	string offhand;

	bool is_equipped() {
		bool bool_result = false;
		return bool_result;
	}
};

class Characters {
	public:
	string name = "default";
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
		string a,
		int b,
		int c,
		int d,
		int e,
		int f,
		int g,
		int h,
		int i,
		int j,
		int k,
		int l,
		int m,
		int n,
		int o,
		int p
		)
		{
		name = a;
		level = b;
		skillpoints = c;
		xp = d;
		capacity = e;
		stamina = f;
		max_health = g;
		current_health = h;
		max_rage = i;
		current_rage = j;
		energy = k;
		strength = l;
		crit_chance = m;
		crit_bonus = n;
		attackpower = o;
		defense = p;
	}
	
	virtual void abstract() = 0;

	void print_name() {
		cout << name << "\n";
	}
};

class Enemies: Characters {
	public:
	string name = "Enemy";

	Enemies (
		int b,
		int c,
		int d,
		int e,
		int f,
		int g,
		int h,
		int i,
		int j,
		int k,
		int l,
		int m,
		int n,
		int o,
		int p
		)
		{
		level = b;
		skillpoints = c;
		xp = d;
		capacity = e;
		stamina = f;
		max_health = g;
		current_health = h;
		max_rage = i;
		current_rage = j;
		energy = k;
		strength = l;
		crit_chance = m;
		crit_bonus = n;
		attackpower = o;
		defense = p;
	}
	
	virtual void abstract() override {};

	void print_name() {
		cout << name << "\n";
	}
};


class Player: public Characters {
	public:
	using Characters::Characters;

	virtual void abstract() override {};
	void print_name() {
		cout << name << "\n";
	}
};
