#include "Eagle.h"

Eagle::Eagle() : Monster("Eagle", "A fast eagle that can fly", 11, 3, false, true)
{

}


void Eagle::displayDrawing()
{
    cout << R"(
                     ///,        ////
                     \  /,      /  >.
                      \  /,   _/  /.
                       \_  /_/   /.
                        \__/_   <    
                        /<<< \_\_  
                       /,)^>>_._ \
                       (/   \\ /\\\
                            // ````
                     ======((`=======)" << endl;
}
