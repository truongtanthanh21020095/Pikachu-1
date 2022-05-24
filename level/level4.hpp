#ifndef _level4_
#define _level4_

void level4()
{
    int Count, Coordinate;
    int ff[20];
    for (int i = 1; i <= 9; i++) {
        Count = 0;
        for (int j = 1; j <= 16; j++)
            if (monstevalue[i][j] != 0) {
                Count++;
                ff[Count] = monstevalue[i][j];
            }
        Coordinate = 1;
        for (int j = 1; j <= Count; j++) {
            monstevalue[i][Coordinate] = ff[j];
            Coordinate++;
        }
        for (int j = Coordinate; j <= 16; j++)
            monstevalue[i][j] = 0;
    }
}
#endif // _level4_

