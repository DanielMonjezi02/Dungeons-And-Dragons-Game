#include "Dragon.h"

Dragon::Dragon() : Monster("Dragon", "A huge fire breathing dragon", 11, 2, true, true)
{

}

void Dragon::displayDrawing()
{
    cout << R"(
       (  )   /\   _                 (     
        \ |  (  \ ( \.(               )                      _____
      \  \ \  `  `   ) \             (  ___                 / _   \
     (_`    \+   . x  ( .\            \/   \____-----------/ (o)   \_
    - .-               \+  ;          (  O                           \____
                              )        \_____________  `              \  /
    (__                +- .( -'.- <. - _  VVVVVVV VV V\                 \/
    (_____            ._._: <_ - <- _  (--  _AAAAAAA__A_/                  |
      .    /./.+-  . .- /  +--  - .     \______________//_              \_______
      (__ ' /x  / x _/ (                                  \___'          \     /
     , x / ( '  . / .  /                                      |           \   /
        /  /  _/ /    +                                      /              \/
       '  (__/                                             /                  \
    )" << endl;

}

void Dragon::performAbility(Character* character)
{
    cout << getName() + " has casted a fireball which has done 4 damage to you!" << endl;
    character->setHealth(character->getHealth() - 4);
}