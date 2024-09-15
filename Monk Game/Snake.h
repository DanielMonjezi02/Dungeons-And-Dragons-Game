#pragma once
#include "Monster.h"

class Snake : public Monster
{
public:
	Snake();
	void displayDrawing();
	void performAbility(Character*);
};

