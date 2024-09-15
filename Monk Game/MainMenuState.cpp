#include "MainMenuState.h"

MainMenuState::MainMenuState(vector<State*>* states)
{
	this->states = states;
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::displayMainMenuOptions()
{
	system("CLS");
	cout << R"(
-----------------------------------------------------------------------------                                                                          
,--.   ,--.  ,---.  ,--.,--.  ,--.    ,--.   ,--.,------.,--.  ,--.,--. ,--. 
|   `.'   | /  O  \ |  ||  ,'.|  |    |   `.'   ||  .---'|  ,'.|  ||  | |  | 
|  |'.'|  ||  .-.  ||  ||  |' '  |    |  |'.'|  ||  `--, |  |' '  ||  | |  | 
|  |   |  ||  | |  ||  ||  | `   |    |  |   |  ||  `---.|  | `   |'  '-'  ' 
`--'   `--'`--' `--'`--'`--'  `--'    `--'   `--'`------'`--'  `--' `-----'  
----------------------------------------------------------------------------- )" << endl;
	cout << "1. Start Game" << setw(32) << "2. About Game" << setw(32) << "3. Exit Game" << endl;
}

void MainMenuState::getGameChoice(int gameChoice)
{

	switch (gameChoice)
	{
	case 1:
		this->states->push_back(new GameMenuState(states));
		break;
	case 2:
		this->states->push_back(new AboutGameState());
		break;
	case 3:
		setQuit(true);
		states->clear();
		break;
	default:
		cout << "Option does not exist, Please try again! " << endl;
		system("pause");
		updateState();
	}
}

void MainMenuState::updateState()
{
	int gameChoice;

	displayMainMenuOptions();
	if (inputValid(gameChoice, "Enter Choice: ") == false)
	{
		updateState();
	}
	else {
		getGameChoice(gameChoice);
	}
}




