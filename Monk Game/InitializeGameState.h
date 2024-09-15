#pragma once
#include "Character.h"
#include "MonsterRoomState.h"
#include "EmptyRoomState.h"
#include "UpgradeRoom.h"
#include "TreasureRoomState.h"
#include "GameLogger.h"
#include "Game.h"

class InitializeGameState : public State
{
	static InitializeGameState* initializeGameStateInstance;

public:
	InitializeGameState(vector <State*>*, string);

	// Functions 
	static InitializeGameState* getInitializeGameStateInstance(vector <State*>*, string);
	void finalizeCharacter(Character*);
	void generateDungeon();
	void createRoom(int, int, int, int);
	void virtual updateState();
	int generateRandomNumber();
	void displayInitalScreen();

	// Getters
	const Character* getMonk() const { return this->monk; }
	const string& getDifficulty() const { return this->difficulty; }
	const int& getNumberOfMonsterRooms() const { return this->numberOfMonsterRooms; }
	const int& getNumberOfUpgradeRooms() const { return this->numberOfUpgradeRooms; }
	const int& getNumberOfEmptyRooms() const { return this->numberOfEmptyRooms; }

private:
	// Variables 
	vector <State*>* states;
	Character* monk;
	string difficulty;
	string monkName;
	string monkDescription;
	int numberOfMonsterRooms = 0;
	int numberOfUpgradeRooms = 0;
	int numberOfEmptyRooms = 0;
};

