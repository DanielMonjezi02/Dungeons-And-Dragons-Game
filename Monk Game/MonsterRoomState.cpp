#include "MonsterRoomState.h"

MonsterRoomState::MonsterRoomState(Character* monk, vector <State*>* states) : Room ("Monster Room", R"(
----------------------------------------------------------------------------------------------------------
,--.   ,--. ,-----. ,--.  ,--. ,---. ,--------.,------.,------.     ,------.  ,-----.  ,-----. ,--.   ,--. 
|   `.'   |'  .-.  '|  ,'.|  |'   .-''--.  .--'|  .---'|  .--. '    |  .--. ''  .-.  ''  .-.  '|   `.'   | 
|  |'.'|  ||  | |  ||  |' '  |`.  `-.   |  |   |  `--, |  '--'.'    |  '--'.'|  | |  ||  | |  ||  |'.'|  | 
|  |   |  |'  '-'  '|  | `   |.-'    |  |  |   |  `---.|  |\  \     |  |\  \ '  '-'  ''  '-'  '|  |   |  | 
`--'   `--' `-----' `--'  `--'`-----'   `--'   `------'`--' '--'    `--' '--' `-----'  `-----' `--'   `--' 
---------------------------------------------------------------------------------------------------------- )", "Color 0C")
{
	this->states = states;
	this->monk = monk;
	this->monster = generateMonster();
}


void MonsterRoomState::updateState()
{
	system("CLS"); // Clears the screen
	system(getRoomColour().c_str()); // Changes the console window colour based on the room 
	cout << getRoomDrawing() << endl; // Displays the drawing of the room name 
	monster->displayDrawing();
	cout << "Oh no! You have encountered a monster. You will need to defeat him!" << endl;
	cout << "Monster's Name: " + monster->getName() << endl;
	cout << "Monster's Description: " + monster->getDescription() + "\n" << endl;
	cout << "Are you ready? GOOD LUCK!" << endl;;
	system("pause");
	fight();
}

void MonsterRoomState::outputAction(int turn)
{
	system("CLS");
	string displayText;
	if (turn == 0)
	{
		system("Color 0A");
		cout << R"(
---------------------------------------------------------------------------------		                                                                                 
,--.   ,--.               ,--.   ,--.          ,--------.                        
|   `.'   | ,---. ,--,--, |  |,-.|  |,---.     '--.  .--',--.,--.,--.--.,--,--,  
|  |'.'|  || .-. ||      \|     /`-'(  .-'        |  |   |  ||  ||  .--'|      \ 
|  |   |  |' '-' '|  ||  ||  \  \   .-'  `)       |  |   '  ''  '|  |   |  ||  | 
`--'   `--' `---' `--''--'`--'`--'  `----'        `--'    `----' `--'   `--''--' 
---------------------------------------------------------------------------------                                                                                
		)";
		monk->displayDrawing();
		displayText = "It is " + monk->getName() + "'s turn" + '\n' + "Would would you like to do? Attack [1] | Defend [2]";
	}
	else if (turn == 1)
	{
		system(MonsterRoomState::getRoomColour().c_str());
		cout << R"(
------------------------------------------------------------------------------------------------------                                                                                                     
,--.   ,--.                       ,--.                ,--.          ,--------.                        
|   `.'   | ,---. ,--,--,  ,---.,-'  '-. ,---. ,--.--.|  |,---.     '--.  .--',--.,--.,--.--.,--,--,  
|  |'.'|  || .-. ||      \(  .-''-.  .-'| .-. :|  .--'`-'(  .-'        |  |   |  ||  ||  .--'|      \ 
|  |   |  |' '-' '|  ||  |.-'  `) |  |  \   --.|  |      .-'  `)       |  |   '  ''  '|  |   |  ||  | 
`--'   `--' `---' `--''--'`----'  `--'   `----'`--'      `----'        `--'    `----' `--'   `--''--' 
------------------------------------------------------------------------------------------------------                                                                                                     
		)";
		monster->displayDrawing();
		displayText = "It is " + monster->getName() + "'s turn";
	}
	monk->displayStats();
	cout << endl;
	monster->displayStats();
	cout << endl; 
	cout << displayText << endl;
}

void MonsterRoomState::fight()
{
	int gameChoice;
	int turn = 0;

	do {
		// Monk's Turn
		if (turn == 0)
		{
			outputAction(turn);
			if (inputValid(gameChoice, "Enter Choice: ") == false)
			{
				continue; // If its an invalid input, skips while iteration to ask user for a choice again
			}
			else
			{
				int attackChance = generateRandomNumber(0, 100);
				int defendChance = generateRandomNumber(1, 100);
				switch (gameChoice)
				{
				case 1:
					if (attackChance < 75)
					{
						cout << "Attack Success! " << monk->getAttackPoint() << " damage done to " << monster->getName() << endl;
						monster->loseHealthPoints(monk->getAttackPoint());
					}
					else
					{
						cout << "Attack Failed! " << endl;
					}
					turn++;
					break;
				case 2:
					if (monk->getHealth() == monk->getMaxHealth())
					{
						cout << "You can't defend because your HP is already maxed out. Please try another option! " << endl;
						system("pause");
						continue;
					}
					else if (defendChance < 50)
					{

						monk->defend();
						cout << "Defend Success! You have gained 1 HP" << endl;
					}
					else if (defendChance >= 50)
					{
						cout << "Defend Failed!" << endl;
					}
					turn++;
					break;
				default:
					cout << "Option does not exist, Please try again! " << endl;
					system("pause");
					continue;
					break;
				}

			}
		}
		// Monster's Turn
		else if (turn == 1)
		{
			outputAction(turn);
			int attackChance = generateRandomNumber(0, 100);
			int defendChance = generateRandomNumber(1, 100);
			if (monster->getAbility() == true && monster->getDefend() == true) // If monster can defend and has an ability
			{
				int monsterChoice = generateRandomNumber(0, 150); // Generates a choice on what option the monster will perform
				if (monsterChoice < 60)
				{
					if (attackChance < 50)
					{
						cout << "Attack Success! " << monster->getAttackPoint() << " damage done to " << monk->getName() << endl;
						monk->loseHealthPoints(monster->getAttackPoint());
					}
					else if (attackChance >= 50)
					{
						cout << "Attack Failed!" << endl;
					}
				}
				else if (monsterChoice >= 60 && monsterChoice < 120) // Defend
				{
					if (monster->getHealth() == monster->getMaxHealth()) // Checks to see if the HP of the monster is maxed out 
					{
						// If it its maxed out then it can't defend, skip this iteration and try a different attack option
						continue;
					}
					else if (defendChance < 50)
					{
						monster->defend();
						cout << "Defend Success! " + monster->getName() + " has gained 1 HP" << endl;

					}
					else if (defendChance >= 50)
					{
						cout << "Defend Failed!" << endl;
					}
				}
				else if(monsterChoice >= 120)
				{
					monster->performAbility(monk);
				}
			}
			else if (monster->getAbility() == false && monster->getDefend() == true) // Monster doesn't have ability but can defend
			{
				int monsterChoice = generateRandomNumber(0, 100);
				if (monsterChoice < 50)
				{
					if (attackChance < 50)
					{
						cout << "Attack Success! " << monster->getAttackPoint() << " damage done to " << monk->getName() << endl;
						monk->loseHealthPoints(monster->getAttackPoint());
					}
					else if (attackChance >= 50)
					{
						cout << "Attack Failed!" << endl;
					}
				}
				else if (monsterChoice >= 50)
				{
					if (monster->getHealth() == monster->getMaxHealth())
					{
						continue;
					}
					else if (defendChance < 50)
					{
						monster->defend();
						cout << "Defend Success! " + monster->getName() + " has gained 1 HP" << endl;
					}
					else if (defendChance >= 50)
					{
						cout << "Defend Failed!" << endl;
					}
				}
			} 
			else // Monster can only attack
			{
				if (attackChance < 50)
				{
					cout << "Attack Success! " << monster->getAttackPoint() << " damage done to " << monk->getName() << endl;
					monk->loseHealthPoints(monster->getAttackPoint());
				}
				else if (attackChance >= 50)
				{
					cout << "Attack Failed!" << endl;
				}
			}
			turn--;
		}
		system("pause");
	 
	} while ((monster->getHealth() > 0) && (monk->getHealth() > 0)); // Keep's looping till both monk and monster have a health above 0
	displayFinalScreen(); // Fight over, display results 
}

Monster* MonsterRoomState::generateMonster()
{
	int randomMonsterNumber = generateRandomNumber(1, 7);
	switch (randomMonsterNumber)
	{
	case 1:
		monster = new Goblin();
		break;
	case 2:
		monster = new Dragon();
		break;
	case 3:
		monster = new Snake();
		break;
	case 4:
		monster = new Eagle();
		break;
	case 5:
		monster = new Knight();
		break;
	case 6:
		monster = new Wizard();
		break;
	case 7:
		monster = new Ghost();
		break;
	}

	return monster; 
}

void MonsterRoomState::displayFinalScreen() // Last screen which displays victory or defeat depending on how the fight occured
{
	system("CLS");
	if (monster->getHealth() <= 0)
	{
		victoryScreen();
	}
	else if (monk->getHealth() <= 0)
	{
		defeatScreen();
	}
	system("pause");
}

void MonsterRoomState::victoryScreen()
{
	cout << R"(
--------------------------------------------------------------                                                          
,--.   ,--.,--. ,-----.,--------. ,-----. ,------.,--.   ,--. 
 \  `.'  / |  |'  .--./'--.  .--''  .-.  '|  .--. '\  `.'  /  
  \     /  |  ||  |       |  |   |  | |  ||  '--'.' '.    /   
   \   /   |  |'  '--'\   |  |   '  '-'  '|  |\  \    |  |    
    `-'    `--' `-----'   `--'    `-----' `--' '--'   `--'    
-------------------------------------------------------------- )" << endl;
	monster->setHealth(0);
	monk->displayStats();
	monster->displayStats();
	cout << endl << "You have defeated the monster, Well done!" << endl;
	setQuit(true);
}

void MonsterRoomState::defeatScreen()
{
	cout << R"(
------------------------------------------------------                                             
,------.  ,------.,------.,------.  ,---. ,--------. 
|  .-.  \ |  .---'|  .---'|  .---' /  O  \'--.  .--' 
|  |  \  :|  `--, |  `--, |  `--, |  .-.  |  |  |    
|  '--'  /|  `---.|  |`   |  `---.|  | |  |  |  |    
`-------' `------'`--'    `------'`--' `--'  `--'                                                   
------------------------------------------------------ )" << endl;
	monk->setHealth(0);
	monk->displayStats();
	monster->displayStats();
	cout << endl << "Oh no, You have been defeated!" << endl;
	states->clear(); // If the user loses the battle then it clears all the future states/rooms so that the next screen presented will be the final screen (Game summary screen)
}