#include "DifficultyMenuState.h"
DifficultyMenuState* DifficultyMenuState::difficultyMenuStateInstance = nullptr;

void DifficultyMenuState::displayDifficultyMenuOptions()
{
	system("CLS");
	cout << R"(
--------------------------------------------------------------------------------------------------------                                                                                                                                                                                                          
,------.  ,--. ,---. ,---.,--.              ,--.  ,--.               ,--.   ,--.                        
|  .-.  \ `--'/  .-'/  .-'`--' ,---.,--.,--.|  |,-'  '-.,--. ,--.    |   `.'   | ,---. ,--,--, ,--.,--. 
|  |  \  :,--.|  `-,|  `-,,--.| .--'|  ||  ||  |'-.  .-' \  '  /     |  |'.'|  || .-. :|      \|  ||  | 
|  '--'  /|  ||  .-'|  .-'|  |\ `--.'  ''  '|  |  |  |    \   '      |  |   |  |\   --.|  ||  |'  ''  ' 
`-------' `--'`--'  `--'  `--' `---' `----' `--'  `--'  .-'  /       `--'   `--' `----'`--''--' `----'  
                                                        `---'                                            )" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(60) << "Easy = 3 Monsters" << endl;
	cout << setw(60) << "Medium = 4 Monsters" << endl;
	cout << setw(60) << "Hard = 6 Monsters" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << "1. Easy" << setw(25) << "2. Medium" << setw(25) << "3. Hard" << setw(25) << "4. Game Menu" << endl;
}

void DifficultyMenuState::getDifficultyChoice(int difficultyChoice)
{

	switch (difficultyChoice)
	{
	case 1:
		setDifficulty("Easy");
		updateState();
		break;
	case 2:
		setDifficulty("Medium");
		updateState();
		break;
	case 3:
		setDifficulty("Hard");
		updateState();
		break;
	case 4:
		setQuit(true);
		return;
	default:
		cout << "Option does not exist, Please try again! " << endl;
		system("pause");
		updateState();
		break;
	}
}

void DifficultyMenuState::updateState()
{

	int difficultyChoice;

	displayDifficultyMenuOptions();
	cout << endl << "Selected Difficulty: " + difficulty;
	if (inputValid(difficultyChoice, "Enter Choice: ") == false)
	{
		updateState();
	}
	else {
		getDifficultyChoice(difficultyChoice);
	}

}

// Singleton Design Pattern 
DifficultyMenuState *DifficultyMenuState::getDifficultyMenuStateInstance()
{
	/* Ensures that the GameMenuState class is not creating multiple instances of the DifficultyMenuState 
	since every time the Game Menu State is entered, it initializes the DifficultyMenuState*/
	if (difficultyMenuStateInstance == nullptr) 
	{
		difficultyMenuStateInstance = new DifficultyMenuState();
	}
	return difficultyMenuStateInstance;
}
