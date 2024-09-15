#include "Player.h"
#include "Monster.h"

Character::Character(string name, string description)
{
	this->name = name;
	this->description = description;
}

void Character::createCharacter(Character* character)
{
	character->setHealth(15);
	character->setMaxHealth(15);
	character->setAttackPoints(3);
	character->setPrayers(0);
}

void Character::loseHealthPoints(int amount) // Used as part of the attack feature in monster room 
{
	this->health -= amount;
}

void Character::defend() // Used as part of the defend feature in monster room 
{
	this->setHealth(this->getHealth() + 1);

}

void Character::displayStats()
{
	cout << "Character's Details | Name: " + getName() + " | HP: " + to_string(getHealth()) + "/" + to_string(getMaxHealth()) + " | Attack Point: " + to_string(getAttackPoint()) << endl;
}

void Character::displayDrawing()
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
