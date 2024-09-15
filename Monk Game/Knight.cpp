#include "Knight.h"

Knight::Knight() : Monster("Knight", "A knight with a shining sword and armour", 13, 2, true, true)
{

}

void Knight::displayDrawing()
{
    cout << R"(
  ,^.
  |||
  |||       _T_
  |||   .-.[:|:].-.
  ===_ /\|  "'"  |/
   E]_|\/ \--|-|''''|
   O  `'  '=[:]| A  |
          /""""|  P |
         /"""""`.__.'
        []"/"""\"[]
        | \     / |
        | |     | |
      <\\\)     (///> )" << endl;
}

void Knight::performAbility(Character* character)
{
    cout << getName() + " has taken a magical potion which deals the same damage as you for one attack!" << endl;
    character->setHealth(character->getHealth() - character->getAttackPoint());
}