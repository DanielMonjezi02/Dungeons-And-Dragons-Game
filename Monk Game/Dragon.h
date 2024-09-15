#pragma once
#include "Monster.h"

class Dragon : public Monster
{
public:
	Dragon();

	//Functions 
	void displayDrawing();
	void performAbility(Character*);
};

