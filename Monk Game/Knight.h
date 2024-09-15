#pragma once
#include "Monster.h"

class Knight : public Monster
{
public:
	Knight();

	//Functions 
	void displayDrawing();
	void performAbility(Character*);
};



