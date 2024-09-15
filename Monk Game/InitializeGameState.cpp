#include "InitializeGameState.h"
InitializeGameState* InitializeGameState::initializeGameStateInstance = nullptr;

InitializeGameState::InitializeGameState(vector<State*>* states, string difficulty)
{
	this->states = states;
	this->difficulty = difficulty;
	cin.ignore();
}

void InitializeGameState::displayInitalScreen()
{
	system("CLS");
	cout << R"(
----------------------------------------------------------------------------------------------                                                                                                                                                                                                                              
 ,-----.                        ,--.             ,------. ,--.                               
'  .--./,--.--. ,---.  ,--,--.,-'  '-. ,---.     |  .--. '|  | ,--,--.,--. ,--.,---. ,--.--. 
|  |    |  .--'| .-. :' ,-.  |'-.  .-'| .-. :    |  '--' ||  |' ,-.  | \  '  /| .-. :|  .--' 
'  '--'\|  |   \   --.\ '-'  |  |  |  \   --.    |  | --' |  |\ '-'  |  \   ' \   --.|  |    
 `-----'`--'    `----' `--`--'  `--'   `----'    `--'     `--' `--`--'.-'  /   `----'`--'    
                                                                      `---'                  
----------------------------------------------------------------------------------------------
                         Create your character with a name & description       
----------------------------------------------------------------------------------------------)" << endl;
}

void InitializeGameState::updateState()
{
	do
	{
		displayInitalScreen();
		cout << endl << "Name: ";
		getline(cin, monkName);

		if (monkName.empty() == false)
		{
			monkName[0] = toupper(monkName[0]); // Makes sure that the first character in the name is an upper case
			cout << "Description: ";
			getline(cin, monkDescription);
			if (monkDescription.empty() == false)
			{
				Character* monk = new Character(monkName, monkDescription); // Creates monk
				monk->createCharacter(monk);
				for (int j = 0; j < 3; j++) {
					cout << "\rCreating Character   \rCreating Character";
					for (int i = 0; i < 3; i++) {
						cout << ".";
						Sleep(300);
					}
				}
				finalizeCharacter(monk);
				cout << endl << "Character created, Welcome " + monk->getName() + " to Dungeons and Dragons!" << endl;
				system("pause");
				generateDungeon();
				break;
			}
			else
			{
				cout << "Character description can't be empty! " << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Character name can't be empty! " << endl;
			system("pause");
		}
		break;
	} while (monkName.empty() || monkDescription.empty());

}

void InitializeGameState::finalizeCharacter(Character* character)
{

	GameLogger* gameLogger = GameLogger::getGameLoggerInstance();
	gameLogger->createFile();
	character->createCharacter(character);
	monk = character;
}
void InitializeGameState::generateDungeon()
{
	/* The vector which contains the states currently has two states within it. The menu state and the game state:
	Since these two states are no longer needed due to the game starting, it is only right that the stack is cleared so
	they those two states can no longer be accessed when the stack pops elements as well as freeing up memory */
	states->clear();
	Game* gameInstance = Game::getGameInstance();
	gameInstance->setRoomsEncountered(0); // Reset the rooms encountered as the the menu's had counted as rooms
	states->push_back(new TreasureRoomState(states)); // Ensures the treasure room is always the last state which is why it gets pushed back first
	states->push_back(new MonsterRoomState(monk, states)); // Ensures there is at least one monster before the user gets to the treasure no matter what
	numberOfMonsterRooms++;
	if (difficulty == "Easy")
	{
		/*
		- 3 Monsters
		- Minimum 1 empty room but there is a chance to have 2 empty rooms
		- 0 Upgrade room 
		*/
		
		while ((numberOfMonsterRooms != 2) || (numberOfEmptyRooms < 1))
		{
			int roomNumber = generateRandomNumber();
			createRoom(roomNumber, 2, 2, 0);
		}
	} 
	else if (difficulty == "Medium")
	{
		/*
		- 4 Monsters
		- Minimum 1 empty room but there is a chance to have 2 empty rooms
		- Chance to have 1 upgrade room
		*/
		
		while ((numberOfMonsterRooms != 3) || (numberOfEmptyRooms < 1))
		{
			int roomNumber = generateRandomNumber();
			createRoom(roomNumber, 3, 2, 1);
		}
	}
	else if (difficulty == "Hard")
	{
		/*
		- 6 Monsters
		- Minimum 2 empty room but there is a chance to have 3 empty rooms
		- Minimum 1 upgrade room but there is a chance to have 2 upgrade rooms 
		*/
		while ((numberOfMonsterRooms != 5) || (numberOfEmptyRooms < 2) || (numberOfUpgradeRooms < 1))
		{
			int roomNumber = generateRandomNumber();
			createRoom(roomNumber, 5, 3, 2);
		}
	}
	states->push_back(new MonsterRoomState(monk, states)); // Ensures there's always a monster room at the start
	numberOfMonsterRooms++; 
}

int InitializeGameState::generateRandomNumber() {
	srand(time(NULL));
	random_device device;
	default_random_engine engine(device());
	uniform_int_distribution<int> r(1, 3);
	return r(engine);
}

void InitializeGameState::createRoom(int roomNumber, int maximumMonsterRooms, int maximumEmptyRooms, int maximumUpgradeRooms)
{
	if (roomNumber == 1)
	{
		if (!(numberOfMonsterRooms >= maximumMonsterRooms))
		{
			states->push_back(new MonsterRoomState(monk, states));
			numberOfMonsterRooms++;
		}
	}
	else if (roomNumber == 2)
	{
		if (!(numberOfUpgradeRooms >= maximumUpgradeRooms))
		{
			states->push_back(new UpgradeRoom(monk));
			numberOfUpgradeRooms++;
		}

	}
	else if (roomNumber == 3)
	{
		if (!(numberOfEmptyRooms >= maximumEmptyRooms))
		{
			states->push_back(new EmptyRoomState(monk));
			this->numberOfEmptyRooms++;
		}
	}
}

InitializeGameState* InitializeGameState::getInitializeGameStateInstance(vector<State*>* states, string difficulty)
{
	if (initializeGameStateInstance == nullptr)
	{
		initializeGameStateInstance = new InitializeGameState(states, difficulty);
	}
	return initializeGameStateInstance;
}