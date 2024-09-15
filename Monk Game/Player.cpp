#include "Player.h"

Player::Player(string name, string description) : Character()
{
    createCharacter(name, description, 20, 20, 3);
    int prayers = 0;
}

void Player::displayStats()
{
	cout << "Character's Details | Name: " + getName() + " | HP: " + to_string(getHealth()) + "/" + to_string(getMaxHealth()) + " | Attack Point: " + to_string(getAttackPoint()) << endl;
}

void Player::displayDrawing()
{
    cout << R"(
           ,, ",
          -   c
           `-|\.
            / `\
          (/  |_\
          |__, |
           |   |
           |   |
           /___|
	)" << endl;
}