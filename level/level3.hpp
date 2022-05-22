#ifndef _level3_
#define _level3_

void level3()
{
    int dem,vt;
    int ff[20];
    for(int j=1;j<=16;j++)
            {
                dem=0;
                for(int i=1;i<=9;i++)
                    if(monstevalue[i][j]!=0)
                    {
                        dem++;
                        ff[dem]=monstevalue[i][j];
                    }
                vt=1;
                for(int i=1;i<=dem;i++)
                {
                    monstevalue[vt][j]=ff[i];
                    vt++;
                }
                for(int i=vt;i<=9;i++)
                    monstevalue[i][j]=0;
            }
}
#endif // _level3_

