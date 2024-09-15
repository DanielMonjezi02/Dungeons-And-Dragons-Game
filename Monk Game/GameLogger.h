#pragma once
#include "pch.h"

class GameLogger
{
	static GameLogger* gameLoggerInstance;

public:

	// Functions
	static GameLogger* getGameLoggerInstance();
	void createFile();
	void writeToFile(string);

	const bool& getGameLoggerActive() const { return this->gameLoggerActive; }

private:
	// Variables
	fstream file;
	bool gameLoggerActive;
};

