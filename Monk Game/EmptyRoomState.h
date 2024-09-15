#pragma once
#include "Character.h"
#include "Room.h"

class EmptyRoomState : public Room, public State
{
public: 
	EmptyRoomState(Character* monk);

	// Functions 
	void updateState();
	void outputAction();
	void restoreHealth();

private:
	// Variables
	Character* monk;
};

