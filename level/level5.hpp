#ifndef _level5_
#define _level5_

void level5()
{
    int Count, Coordinate;
    int ff[20];
    for (int i = 1; i <= 9; i++) {
        Count = 0;
        for (int j = 16; j >= 1; j--)
            if (monstevalue[i][j] != 0) {
                Count++;
                ff[Count] = monstevalue[i][j];
            }
        Coordinate = 16;
        for (int j = 1; j <= Count; j++) {
            monstevalue[i][Coordinate] = ff[j];
            Coordinate--;
        }
        for (int j = Coordinate; j >= 1; j--)
            monstevalue[i][j] = 0;
    }
}
#endif // _level5_


