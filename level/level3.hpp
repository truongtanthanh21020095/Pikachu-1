#ifndef _level3_
#define _level3_

void level3()
{
    int Count, Coordinate;
    int ff[20];
    for (int j = 1; j <= 16; j++) {
        Count = 0;
        for (int i = 1; i <= 9; i++)
            if (monstevalue[i][j] != 0) {
                Count++;
                ff[Count] = monstevalue[i][j];
            }
        Coordinate = 1;
        for (int i = 1; i <= Count; i++) {
            monstevalue[Coordinate][j] = ff[i];
            Coordinate++;
        }
        for (int i = Coordinate; i <= 9; i++)
            monstevalue[i][j] = 0;
    }
}
#endif // _level3_

