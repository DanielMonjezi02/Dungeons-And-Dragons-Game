#pragma once
#include "pch.h"
#include "GameMenuState.h"

class MainMenuState : public State
{
	static MainMenuState* mainMenuStateInstance;

public:
	MainMenuState(vector<State*>*);
	virtual ~MainMenuState();

	// Functions 
	static MainMenuState* getMainMenuInstance(vector<State*>*);
	void updateState();
	void displayMainMenuOptions();
	void getGameChoice(int);

private:
	// Variables 
	vector <State*>* states;
};

