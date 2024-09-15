#pragma once
#include "pch.h"
#include "State.h"

class Room
{
public:
	Room(string, string, string);

	// Functions 
	int generateRandomNumber(int, int);

	// Getters 
	const string& getRoomDrawing() const { return this->roomDrawing; }
	const string& getRoomColour() const { return this->roomColor; }

protected:
	string roomType;
	string roomDrawing;
	string roomColor;
};

