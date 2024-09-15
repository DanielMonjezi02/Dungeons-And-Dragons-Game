#pragma once
#include "pch.h"
#include "Room.h"

class TreasureRoomState : public Room, public State
{
public: 
	TreasureRoomState(vector <State*>*);
	
	// Functions 
	void updateState();
private:
	// Variables
	vector <State*>* states;
};

