#include "UpgradeRoom.h"

UpgradeRoom::UpgradeRoom(Character* monk) : Room("Upgrade Rom", R"(
----------------------------------------------------------------------------------------------------------                                                                                                           
,--. ,--.,------.  ,----.   ,------.   ,---.  ,------.  ,------.    ,------.  ,-----.  ,-----. ,--.   ,--. 
|  | |  ||  .--. ''  .-./   |  .--. ' /  O  \ |  .-.  \ |  .---'    |  .--. ''  .-.  ''  .-.  '|   `.'   | 
|  | |  ||  '--' ||  | .---.|  '--'.'|  .-.  ||  |  \  :|  `--,     |  '--'.'|  | |  ||  | |  ||  |'.'|  | 
'  '-'  '|  | --' '  '--'  ||  |\  \ |  | |  ||  '--'  /|  `---.    |  |\  \ '  '-'  ''  '-'  '|  |   |  | 
 `-----' `--'      `------' `--' '--'`--' `--'`-------' `------'    `--' '--' `-----'  `-----' `--'   `--' 
----------------------------------------------------------------------------------------------------------                                                                                                            									
													)", "Color 0B")
{
	this->monk = monk;
}

void UpgradeRoom::updateState()
{
	system("CLS");

	system(getRoomColour().c_str());
	cout << getRoomDrawing() << endl;
	cout << "You have entered an Upgrade Room, Enjoy the upgrades!" << endl;
	system("pause");
	outputAction();
}

void UpgradeRoom::outputAction()
{
	int gameChoice;
	system("CLS");
	cout << getRoomDrawing();
	cout << R"(	


                                             ,o8o, ,o8o,
              |______________              ,888888,888888,
       [======|______________>      OR     888888888888888          
              |                            888888888888888
              '                            `8888888888888'
                                             `888888888'
                                               `88888'
                                                 `8' )" << endl;
	cout << "What would you like to upgrade?: " << endl;
	cout << setw(75) << "1. Increase Maximum Health Points by 5 and restore 4 health points" << endl;
	cout << endl << setw(39) << "2. Increase Attack Points by 2" << endl << endl;
	monk->displayStats();
	cout << "What would you like to do? Increase Health [1] | Increase Attack Points [2]" << endl;
	if (inputValid(gameChoice, "Enter Choice: ") == false)
	{
		outputAction();
	}
	else 
	{
		switch (gameChoice)
		{
		case 1:
			/* Has chosen to increase health health */
			increaseHealth();
			system("pause");
			setQuit(true);
			break;
		case 2:
			/* Has chosen to increase attack points */
			increaseAttackPoints();
			system("pause");
			setQuit(true);
			break;
		default:
			cout << "Option does not exist, Please try again! " << endl;
			system("pause");
			outputAction();
			break;
		}
	}
}

void UpgradeRoom::increaseHealth()
{
	monk->setMaxHealth(monk->getMaxHealth() + 5);
	monk->setHealth(monk->getHealth() + 4);
	cout << monk->getName() + " has chosen to increase their health. New Health Point Stats: " << monk->getHealth() << "/" << monk->getMaxHealth() << endl;
}

void UpgradeRoom::increaseAttackPoints()
{
	monk->setAttackPoints(monk->getAttackPoint() + 2);
	cout << monk->getName() + " has chosen to increase their attack points. New Attack Point Stats: " << monk->getAttackPoint() << endl;
}