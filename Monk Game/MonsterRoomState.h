#pragma once
#include "pch.h"
#include "Room.h"
#include "Character.h"
// Monsters
#include "Goblin.h"
#include "Dragon.h"
#include "State.h"
#include "Snake.h"
#include "Eagle.h"
#include "Game.h"
#include "Knight.h"
#include "Wizard.h"
#include "Ghost.h"


class MonsterRoomState : public Room, public State
{
public:
	MonsterRoomState(Character*, vector <State*>*);

	//Functions 
	void updateState();
	void outputAction(int);
	void fight();
	Monster* generateMonster();
	void displayFinalScreen();
	void defeatScreen();
	void victoryScreen();

private:
	// Variables
	vector <State*>* states;
	Monster* monster = NULL;
	Character* monk;

};

