#include "GameMenuState.h"

GameMenuState::GameMenuState(vector<State*>* states) 
{
	this->states = states;
	this->difficultyMenuStateInstance = DifficultyMenuState::getDifficultyMenuStateInstance();
}

GameMenuState::~GameMenuState()
{
	
}

void GameMenuState::displayGameMenuOptions() // Initally displays this to the user
{
	system("CLS");
	cout << R"(
--------------------------------------------------------------------------------                                                                                 
 ,----.     ,---.  ,--.   ,--.,------.    ,--.   ,--.,------.,--.  ,--.,--. ,--. 
'  .-./    /  O  \ |   `.'   ||  .---'    |   `.'   ||  .---'|  ,'.|  ||  | |  | 
|  | .---.|  .-.  ||  |'.'|  ||  `--,     |  |'.'|  ||  `--, |  |' '  ||  | |  | 
'  '--'  ||  | |  ||  |   |  ||  `---.    |  |   |  ||  `---.|  | `   |'  '-'  ' 
 `------' `--' `--'`--'   `--'`------'    `--'   `--'`------'`--'  `--' `-----'  
-------------------------------------------------------------------------------- )" << endl;
	cout << "1. Create Character" << setw(28) << "2. Game Difficulty" << setw(33) << "3. Go back to main menu" << endl;

}

// Factory Method
void GameMenuState::getGameChoice(int gameChoice)
{
	switch (gameChoice)
	{
	case 1:
		states->push_back(InitializeGameState::getInitializeGameStateInstance(states, difficultyMenuStateInstance->getDifficulty()));
		break;
	case 2:
		difficultyMenuStateInstance->updateState();
		break;
	case 3:
		setQuit(true);
		break;
	default:
		cout << "Option does not exist, Please try again! " << endl;
		system("pause");
		break;
	}
}

void GameMenuState::updateState()
{
	int gameChoice;

	displayGameMenuOptions();
	if (inputValid(gameChoice, "Enter Choice: ") == false)
	{
		updateState();
	}
	else {
		getGameChoice(gameChoice);
	}
}
