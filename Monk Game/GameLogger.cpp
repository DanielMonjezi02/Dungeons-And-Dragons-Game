#include "GameLogger.h"
GameLogger* GameLogger::gameLoggerInstance = nullptr;

void GameLogger::createFile()
{
	gameLoggerActive = true;
	file.open("GameLogger.txt", ios::app);

	file << "-----------------------\n";
	file.close(); 

}

void GameLogger::writeToFile(string message)
{
	file.open("GameLogger.txt", ios::app);
	file << message;
	file.close(); 
}

GameLogger* GameLogger::getGameLoggerInstance()
{
	if (gameLoggerInstance == nullptr)
	{
		gameLoggerInstance = new GameLogger();
	}
	return gameLoggerInstance;
}
