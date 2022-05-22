#ifndef _level2_
#define _level2_

void level2()
{
    int dem,vt;
    int ff[20];
    for(int j=1;j<=16;j++) {
        dem=0;
        for(int i=9;i>=1;i--)
        if(monstevalue[i][j]!=0) {
            dem++;
            ff[dem]=monstevalue[i][j];
        }
        vt=9;
        for(int i=1;i<=dem;i++)
        {
            monstevalue[vt][j]=ff[i];
            vt--;
        }

        for(int i=vt;i>=1;i--)
            monstevalue[i][j]=0;
    }
}
#endif // _level2_
