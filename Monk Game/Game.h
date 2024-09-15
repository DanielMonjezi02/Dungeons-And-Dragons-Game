#pragma once
#include "MainMenuState.h"
#include "GameLogger.h"
#include <time.h>

class Game 
{
	static Game* gameInstance;

public:
	Game();

	// Functions
	static Game* getGameInstance();
	void createGame();
	void createGameLog();

	// Getters
	const bool& getQuit() const { return this->quit; }

	// Setters 
	void setRoomsEncountered(int roomsEncountered) { this->roomsEncountered = roomsEncountered; }

private: 
	// Variables 
	vector <State*> states;
	bool quit = false;
	int roomsEncountered = 0;
	GameLogger* gameLogger;
	string gameStatus;
};

