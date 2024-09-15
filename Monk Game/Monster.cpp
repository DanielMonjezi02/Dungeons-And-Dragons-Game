#include "Monster.h"
#include "Character.h"

Monster::Monster(string name, string description, int health, int attackPoints, bool hasAbility, bool canDefend) : Character(name, description)
{
	this->name = name;
	this->description = description;
	this->health = health;
	this->maxHealth = health;
	this->attackPoint = attackPoints;
	this->hasAbility = hasAbility;
	this->canDefend = canDefend;
}

void Monster::displayStats()
{
	cout << "Monster's Details | Name: " + getName() + " | HP: " + to_string(getHealth()) + "/" + to_string(getMaxHealth()) + " | Attack Point: " + to_string(getAttackPoint()) << endl;
}

void Monster::performAbility(Character* character)
{

}