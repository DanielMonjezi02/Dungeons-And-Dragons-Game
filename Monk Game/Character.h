#pragma once
#include "pch.h"

class Character
{

public:
	// Default Constructor 
	Character(string, string);

	// Functions 
	void createCharacter(Character*);
	void loseHealthPoints(int);
	void defend();
	virtual void displayStats();
	virtual void displayDrawing();

	// Getters
	const string& getName() const { return this->name; }
	const string& getDescription() const { return this->description; }
	const int& getHealth() const { return this->health; }
	const int& getMaxHealth() const { return this->maxHealth; }
	const int& getAttackPoint() const { return this->attackPoint; }
	const int& getPrayers() const { return this->prayers; }

	// Setters 
	void setName(string name) { this->name = name; }
	void setDescription(string description) { this->name = name; }
	void setHealth(int health) { this->health = health; }
	void setMaxHealth(int maxHealth) { this->maxHealth = maxHealth; }
	void setPrayers(int prayers) { this->prayers = prayers; }
	void setAttackPoints(int attackPoint) { this->attackPoint = attackPoint; }

protected:
	// Variables
	string name;
	string description;
	int health;
	int attackPoint;
	int maxHealth;
	int prayers; 
};


