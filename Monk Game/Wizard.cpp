#include "Wizard.h"

Wizard::Wizard() : Monster("Wizard", "A man who has magical powers", 9, 3, false, false)
{

}

void Wizard::displayDrawing()
{
	cout << R"(
          *
             / \
            /___\
           ( o o )            * *
           )  L  (           /   * *
   ________()(-)()________  /     * * *
 E\| _____ )()()() ______ |/B     * * *
   |/      ()()()(       \|      * * * *
           | )() |
           /     \
          / *  *  \
         /   *  *  \
        / *_  *  _  \   )" << endl;
}

void Wizard::performAbility(Character* character)
{
    cout << getName() + " has casted a spell on you to take your current health points and apply it to himself!" << endl;
    if ((character->getHealth() + getHealth()) > getMaxHealth())
    {
        setHealth(getMaxHealth());
    }
    else
    {
        setHealth(character->getHealth() + getHealth());
    }
}