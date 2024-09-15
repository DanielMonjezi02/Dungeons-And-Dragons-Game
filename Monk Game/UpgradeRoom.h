#pragma once
#include "Room.h"
#include "Character.h"
#include "State.h"

class UpgradeRoom : public Room, public State
{
public: 
	UpgradeRoom(Character* monk);

	// Functions
	virtual void updateState();
	void outputAction();
	void increaseHealth();
	void increaseAttackPoints();

private:
	Character* monk;
};

