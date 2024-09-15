#include "AboutGameState.h"

void AboutGameState::displayAboutGame()
{
	system("CLS");
	cout << R"(
--------------------------------------------------------------------------------                                                                               
  ,---.  ,--.                    ,--.       ,----.                             
 /  O  \ |  |-.  ,---. ,--.,--.,-'  '-.    '  .-./    ,--,--.,--,--,--. ,---.  
|  .-.  || .-. '| .-. ||  ||  |'-.  .-'    |  | .---.' ,-.  ||        || .-. : 
|  | |  || `-' |' '-' ''  ''  '  |  |      '  '--'  |\ '-'  ||  |  |  |\   --. 
`--' `--' `---'  `---'  `----'   `--'       `------'  `--`--'`--`--`--' `----' 
-------------------------------------------------------------------------------- )" << endl;

	cout <<
		"This game is based on Dungeons and Dragons." << "\n" << "\n" <<
		"You will begin as a character with 15 Health Points and 3 Attack Points." << "\n" << "\n" <<
		"Your main goal is to reach the treasure room where you will find the goal!" << "\n" <<
		"However, to reach there you will need to get pass some rooms." << "\n" << "\n" <<
		"There are 4 types of difficulties you can select which will alter how the game plays:" << "\n" <<
		setw(20) << "Easy Difficutly:" << "\n" <<
		"          - 3 Monsters" << "\n" <<
		"          - Minimum of 1 empty room but a chance to have a max of 2" << "\n" <<
		"          - No Upgrade Rooms" << "\n" << "\n" <<
		setw(20) << "Medium Difficulty:" << "\n" <<
		"          - 4 Monsters" << "\n" <<
		"          - Minimum of 1 empty room but a chance to have a max of 2" << "\n" <<
		"          - Chance to have 1 upgrade room " << "\n" <<
		"          - 3 Monsters" << "\n" << "\n" <<
		setw(20) << "Hard Difficulty" << "\n"
		"          - 6 Monsters" << "\n" <<
		"          - Minimum of 2 empty rooms but a chance to have a max of 3" << "\n" <<
		"          - Minimuum of 1 upgrade room but a chance to have a max of 2" << "\n" << "\n" << "\n" <<
		"4 Rooms you can come across with the dungeon: " << "\n" <<
		setw(18) << "------------- " << "\n" <<
		setw(18) << "Monster Room: " << "\n" <<
		setw(18) << "------------- " << "\n" <<
		"       - The combat will be turned based. The player and monster (AI Controlled) will take it un turns to attack." << "\n" << "\n" <<
		"	1.) The player will take their turn where they can do one of the following actions:" << "\n" <<
		"	 a) Attack: This will reduce the health of the monster by the attack points the player has" << "\n" <<
		"	 b) Defend: This will recover 1 health point of the player" << "\n" << "\n" <<
		"	 Note: The player has a 75% chance for a successful attack and a 50% chance for a succesful defend." << "\n" << "\n" <<
		"	2.) Monster will take their turn where they can perform the same actions as the player." << "\n" <<
		"	    Some monsters will be able to only attack while some monsters can attack, defend and perform" << "\n" <<
		"	    a special ability." << "\n" << "\n" <<
		"	 Note: The monster has a 50% chance for a successful attack, a 50% chance for a succesful defend and a" << "\n" <<
		"	 50% chance for a succesful ability attack." << "\n" << "\n" <<
		setw(16) << "-----------" << "\n" <<
		setw(16) << "Empty Room:" << "\n" <<
		setw(16) << "-----------" << "\n" <<
		"       - This room will allow the player to pray which will restore their health points to the max or skip" << "\n" <<
		"         the room onto the next one. The player can only pray twice in per game." << "\n" << "\n" <<
		setw(18) << "-------------" << "\n" <<
		setw(18) << "Upgrade Room:" << "\n" <<
		setw(18) << "-------------" << "\n" <<
		"       - This room will allow the player to upgrade their stats with one of the following actions:" << "\n" <<
		"	1.) Increase their Attack Points by 2" << "\n" <<
		"	2.) Increase health by 5 and restore 4 health points" << "\n" << "\n" <<
		setw(19) << "--------------" << "\n" <<
		setw(19) << "Treasure Room:" << "\n" <<
		setw(19) << "--------------" << "\n" <<
		"       - This is the final room when the player has defeated all the monsters and been to all the rooms." << "\n" << endl;


	




}

void AboutGameState::updateState()
{
	displayAboutGame();
	system("pause");
	cout << endl;
	setQuit(true);
}