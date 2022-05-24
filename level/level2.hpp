#ifndef _level2_
#define _level2_

void level2()
{
    int Count, Coordinate;
    int ff[20];
    for (int j = 1; j <= 16; j++) {
        Count = 0;
        for (int i = 9; i >= 1; i--)
            if (monstevalue[i][j] != 0) {
                Count++;
                ff[Count] = monstevalue[i][j];
            }
        Coordinate = 9;
        for (int i = 1; i <= Count; i++)
        {
            monstevalue[Coordinate][j] = ff[i];
            Coordinate--;
        }

        for (int i = Coordinate; i >= 1; i--)
            monstevalue[i][j] = 0;
    }
}
#endif // _level2_
