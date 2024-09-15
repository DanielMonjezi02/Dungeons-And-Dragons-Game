#pragma once
#include "State.h"

class DifficultyMenuState : public State
{
	static DifficultyMenuState* difficultyMenuStateInstance;

public:
	// Functions 
	static DifficultyMenuState* getDifficultyMenuStateInstance();
	void displayDifficultyMenuOptions();
	void getDifficultyChoice(int);
	void updateState();

	// Getters
	const string& getDifficulty() const { return this->difficulty; }

	// Setters
	void setDifficulty(string name) { this->difficulty = name; }

private:
	// Variables
	string difficulty = "Medium";
	vector <State*>* states;

};

