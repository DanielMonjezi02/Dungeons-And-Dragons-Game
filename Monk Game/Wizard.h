#pragma once
#include "Monster.h"

class Wizard : public Monster
{
public:
	Wizard();

	//Functions 
	void displayDrawing();
	void performAbility(Character*);
};


