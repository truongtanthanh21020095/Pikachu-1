#ifndef _level4_
#define _level4_

void level4()
{
    int dem,vt;
    int ff[20];
    for(int i=1;i<=9;i++)
            {
                dem=0;
                for(int j=1;j<=16;j++)
                    if(monstevalue[i][j]!=0)
                    {
                        dem++;
                        ff[dem]=monstevalue[i][j];
                    }
                vt=1;
                for(int j=1;j<=dem;j++)
                {
                    monstevalue[i][vt]=ff[j];
                    vt++;
                }
                for(int j=vt;j<=16;j++)
                    monstevalue[i][j]=0;
            }
}
#endif // _level4_

