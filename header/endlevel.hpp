#ifndef _endlevel_
#define _endlevel_

bool endlevel()
{
    int dem = 0;
    for(int i = 1; i <= 36; i++) dem += monste[i];
    if(dem != 0) return false;
    return true;
}
#endif // _endlevel_
