#include "EmptyRoomState.h"

EmptyRoomState::EmptyRoomState(Character* monk) : Room("Empty Room", R"(
--------------------------------------------------------------------------------                                                                                
,------.                   ,--.               ,------.                          
|  .---',--,--,--. ,---. ,-'  '-.,--. ,--.    |  .--. ' ,---.  ,---. ,--,--,--. 
|  `--, |        || .-. |'-.  .-' \  '  /     |  '--'.'| .-. || .-. ||        | 
|  `---.|  |  |  || '-' '  |  |    \   '      |  |\  \ ' '-' '' '-' '|  |  |  | 
`------'`--`--`--'|  |-'   `--'  .-'  /       `--' '--' `---'  `---' `--`--`--' 
                  `--'           `---'                                          
-------------------------------------------------------------------------------- )", "Color 0D")
{
	this->monk = monk;
}


void EmptyRoomState::updateState()
{
	system("CLS");
	system(getRoomColour().c_str());
	cout << getRoomDrawing() << endl;
	cout << "You have entered an Empty Room, you are safe for now!" << endl;
	system("pause");
	outputAction();
}

void EmptyRoomState::outputAction()
{
	int gameChoice;
	system("CLS");
	cout << getRoomDrawing();
	cout << R"(
       _.-._
     /| | | |_
     || | | | |
     || | | | |
    _||     ` |
   \\`\       ;
    \\        |
     \\      /
     | |    |
     | |    | )" << endl;
	monk->displayStats();
	cout << "You have prayed " + to_string(monk->getPrayers()) << " times so far." << endl;
	cout << endl << "Would you like to pray and restore your health to the max? Yes [1] | No [2]" << endl;
	if (inputValid(gameChoice, "Enter Choice: ") == false)
	{
		outputAction();
	}
	else 
	{
		switch (gameChoice)
		{
		case 1:
			/* Has chosen to restore health */
			restoreHealth();
			system("pause");
			setQuit(true);
			break;
		case 2:
			/* Has chosen NOT to restore health */
			cout << monk->getName() + " has chosen to not restore health points." << endl;
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

void EmptyRoomState::restoreHealth()
{
	if (monk->getPrayers() >= 2)
	{
		cout << "You have reached your maximum prayers uses" << endl;
	}
	else if (monk->getHealth() >= monk->getMaxHealth())
	{
		cout << "Your health is already maxed out!" << endl;
	}
	else
	{
		monk->setHealth(monk->getMaxHealth());
		monk->setPrayers(monk->getPrayers() + 1);
		cout << monk->getName() + " has restored his health. " + "\n" + "Your HP is now: " + to_string(monk->getHealth()) + ". You now have " + to_string(2 - monk->getPrayers()) + " prayer left" << endl;
	}
}

