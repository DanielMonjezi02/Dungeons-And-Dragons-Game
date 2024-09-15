#include "Game.h"

Game* Game::gameInstance = nullptr;

Game::Game()
{
	this->gameLogger = GameLogger::getGameLoggerInstance();
	this->states.push_back(new MainMenuState(&states));
	/*
	When the Game object is initliased/created, it pushes the "Main Menu" object into the stack 
	*/
}

void Game::createGame()
{
	/*
	The updateState() function is called which esentially displays the main menu state. This is because when we initalised the "Game"
	object, we pushed the main menu state into the stack. This function then retrives the top thing from the stack, in this case it is
	main menu state and calls the update function from the Main Menu state class.
	*/
	states.back()->updateState();
	if (states.empty())
	{
		
		//If there are no states in the stack then it quits the game.
		
		if (gameLogger->getGameLoggerActive() == true)
		{
			system("CLS");
			roomsEncountered++;
			createGameLog();
		}
		else
		{

			cout << "Goodbye! The game has ended." << endl;
		}
		quit = true;
		return;
		
	}
	if (states.back()->getQuit())
	{
		roomsEncountered++;
		/* Once a class "quit" variable has been set to true, it will return to this IF statement which will delete
		the class from the stack and pop whatever is next. For example:
		- Main Menu State is called
		- User clicks 1 which displays the game menu
		- User clicks 3, it will set quit variable to true and return to this if statement
		- Will then display main menu state since its the top thing in the stack
		*/
		delete states.back();
		states.pop_back();
	}

}

Game* Game::getGameInstance()
{
	if (gameInstance == nullptr)
	{
		gameInstance = new Game();
	}
	return gameInstance;
}

void Game::createGameLog()
{
	InitializeGameState* gameInformation = InitializeGameState::getInitializeGameStateInstance(&states, "medium");
	if (gameInformation->getMonk()->getHealth() <= 0)
	{
		gameStatus = "Lost";
	}
	else {
		gameStatus = "Victory";
	}


	// Gets the current time
	time_t currtTime;
	struct tm * timeInfo;

	time (&currtTime);
	timeInfo = localtime(&currtTime);

	char currentTime[100];
	char currentDate[100];

	strftime(currentTime, 50, "%T", timeInfo);
	strftime(currentDate, 50, "%B %d %Y", timeInfo); 


	// Stores all the game data into a text file
	gameLogger->writeToFile(
		"Date: " + string(currentDate) + "\n"
		"Time: " + string(currentTime) + "\n"
		"Monk Name: " + gameInformation->getMonk()->getName() + "\n"
		"Monk Description: " + gameInformation->getMonk()->getDescription() + "\n"
		"Monk Health Points: " + to_string(gameInformation->getMonk()->getHealth()) + "/" + to_string(gameInformation->getMonk()->getMaxHealth()) + "\n"
		"Game Difficulty: " + gameInformation->getDifficulty() + "\n"
		"Game Status: " + gameStatus + "\n"
		"Total Rooms Encountered: " + to_string(roomsEncountered) + "\n" 
	); 

	system("Color 07"); // Changes the colour of the console windows to black background and white text
	cout << R"(
------------------------------------------------------------------------------------------------------                                                                                                    
 ,----.                                 ,---.                                                       
'  .-./    ,--,--.,--,--,--. ,---.     '   .-' ,--.,--.,--,--,--.,--,--,--. ,--,--.,--.--.,--. ,--. 
|  | .---.' ,-.  ||        || .-. :    `.  `-. |  ||  ||        ||        |' ,-.  ||  .--' \  '  /  
'  '--'  |\ '-'  ||  |  |  |\   --.    .-'    |'  ''  '|  |  |  ||  |  |  |\ '-'  ||  |     \   '   
 `------'  `--`--'`--`--`--' `----'    `-----'  `----' `--`--`--'`--`--`--' `--`--'`--'   .-'  /    
                                                                                          `---'     
------------------------------------------------------------------------------------------------------)" << endl;
	// Outputs the game summary
	cout << 
		"Date: " + string(currentDate) + "\n"
		"Time: " + string(currentTime) + "\n"
		"Monk Name: " + gameInformation->getMonk()->getName() + "\n"
		"Monk Description: " + gameInformation->getMonk()->getDescription() + "\n"
		"Monk Health Points: " + to_string(gameInformation->getMonk()->getHealth()) + "/" + to_string(gameInformation->getMonk()->getMaxHealth()) + "\n"
		"Game Difficulty: " + gameInformation->getDifficulty() + "\n"
		"Game Status: " + gameStatus + "\n"
		"Total Rooms Encountered: " + to_string(roomsEncountered) + "\n" + "\n"
		"This game summary has been stored in a file named GameLogger.txt and can be located within the program's folder. " << endl;
}

