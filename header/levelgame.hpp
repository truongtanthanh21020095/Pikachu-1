#ifndef _levelgame_
#define _levelgame_

#include "level/level2.hpp"
#include "level/level3.hpp"
#include "level/level4.hpp"


void levelgame(int level)
{
    int NumOfLevel = 4;
    level%= NumOfLevel;
    level+=1;
    if(level == 2) level2();
    if(level == 3) level3();
    if(level == 4) level4();
}
#endif // _levelgame_

