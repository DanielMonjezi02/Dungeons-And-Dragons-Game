#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player(string, string);
	void displayStats();
	void displayDrawing();

private:
	int prayers;

};

