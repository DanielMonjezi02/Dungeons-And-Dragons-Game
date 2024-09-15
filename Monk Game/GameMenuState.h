#pragma once
#include "State.h"
#include "InitializeGameState.h"
#include "DifficultyMenuState.h"
#include "AboutGameState.h"

class GameMenuState : public State
{
public: 
	GameMenuState(vector<State*>*);
	virtual ~GameMenuState();

	//Functions
	void updateState();
	void displayGameMenuOptions();
	void getGameChoice(int);

private:
	// Variables 
	vector <State*>* states;
	Character* monk;
	DifficultyMenuState* difficultyMenuStateInstance;
};

