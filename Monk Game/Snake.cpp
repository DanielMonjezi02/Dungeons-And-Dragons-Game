#include "Snake.h"


Snake::Snake() : Monster("Snake", "Venmous, fast and highly deadly creature", 9, 2, true, true)
{

}

void Snake::displayDrawing()
{
    cout << R"(
      ---_ ......._-_--.
      (|\ /      / /| \  \
      /  /     .'  -=-'   `.
     /  /    .'             )
   _/  /   .'        _.)   /
  / o   o        _.-' /  .'
  \          _.-'    / .'*|
   \______.-'//    .'.' \*|
    \|  \ | //   .'.' _ |*|
     `   \|//  .'.'_ _ _|*|
      .  .// .'.' | _ _ \*|
      \`-|\_/ /    \ _ _ \*\
       `/'\__/      \ _ _ \*\
      /^|            \ _ _ \*
     '  `             \ _ _ \   )" << endl;
}

void Snake::performAbility(Character* character)
{
    cout << getName() + " performed a venmous bite which has done 4 damage to you!" << endl;
    character->setHealth(character->getHealth() - 4);
}
