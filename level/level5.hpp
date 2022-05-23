#ifndef _level5_
#define _level5_

void level5()
{
    int dem,vt;
    int ff[20];
    for(int i=1;i<=9;i++)
            {
                dem=0;
                for(int j=16;j>=1;j--)
                    if(monstevalue[i][j]!=0)
                    {
                        dem++;
                        ff[dem]=monstevalue[i][j];
                    }
                vt=16;
                for(int j=1;j<=dem;j++)
                {
                    monstevalue[i][vt]=ff[j];
                    vt--;
                }
                for(int j=vt;j>=1;j--)
                    monstevalue[i][j]=0;
            }
}
#endif // _level5_


