#pragma once
#include "pch.h"
#include "Character.h"

class Monster : public Character
{
public:
	Monster(string, string, int, int, bool, bool);

	// Functions
	void displayStats();
	virtual void performAbility(Character*);

	// Getters
	const bool& getAbility() const { return this->hasAbility; }
	const bool& getDefend() const { return this->canDefend; }

	// Setters 
	void setAbility(bool ability) { this->hasAbility = ability; }


private: 
	bool hasAbility;
	bool canDefend;
};
