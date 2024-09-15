#include "Goblin.h"

Goblin::Goblin() : Monster("Goblin", "An ugly looking goblin with bat-like earts and a big nose", 10, 2, false, false)
{

}


void Goblin::displayDrawing()
{
    cout << R"(
             ,      ,
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \
	)" << endl;
}

