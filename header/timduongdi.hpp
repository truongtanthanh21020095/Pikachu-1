#ifndef _timduongdi_
#define _timduongdi_

int booleanWay[20][20], minWay; //booleanWay[][] to print the way
bool testtwopointsin(int i1,  int j1, int i2, int j2) 
//Save the way to print out + Check if the 2 + signs touch each other
//Find the length of min way and show that way 
{                                                     
	int imin, imax, jmin, jmax;
    imin = max (Plus_sign[i1][j1].i1, Plus_sign[i2][j2].i1);
    imax = min (Plus_sign[i1][j1].i3, Plus_sign[i2][j2].i3);
    jmin = max (Plus_sign[i1][j1].j4, Plus_sign[i2][j2].j4);
    jmax = min (Plus_sign[i1][j1].j2, Plus_sign[i2][j2].j2);

	bool dau = false;
	minWay = 1000; //Points to calculate on the Oy axis
	if(j2 < j1) { swap( i1, i2); swap( j1, j2); }

	int ionnhat = -1;
	if(imin <= imax)
		for(int i = imin;i <= imax; i++)
                if(Plus_sign[i][j1].j2 >= j2) {
                    dau = true;
                    if(minWay > abs(i-i1) + abs(i-i2) + abs(j1-j2)) {
                        ionnhat = i;
                        minWay = abs(i-i1) + abs(i-i2) + abs(j1-j2);
                    }
                }
    if(ionnhat >= 0)
    {
        if(ionnhat > i1)    for(int ii = i1; ii <= ionnhat; ii++) booleanWay[ii][j1] = 1;
            else            for(int ii = i1; ii >= ionnhat; ii--) booleanWay[ii][j1] = 1;
        if(ionnhat>i2)      for(int ii = i2; ii <= ionnhat; ii++) booleanWay[ii][j2] = 1;
            else            for(int ii = i2; ii >= ionnhat; ii--) booleanWay[ii][j2] = 1;
        if(j1 <= j2)        for(int jj = j1; jj <= j2; jj++) booleanWay[ionnhat][jj] = 1;
            else            for(int jj = j2; jj <= j1; jj++) booleanWay[ionnhat][jj] = 1;
    }
    if(i1 > i2) {
        swap( i1, i2);  
        swap( j1, j2);
    }
    int minWay2 = 1000; //Points to calculate on the Ox axis 
    int jonnhat = -1;
	if(jmin <= jmax)
		for(int j = jmin; j <= jmax; j++)
                if(Plus_sign[i1][j].i3 >= i2){
                    dau = true;
                    if(minWay2 > abs(i1-i2) + abs(j-j2) + abs(j-j1)) {
                        jonnhat = j;
                        minWay2 = abs(i1-i2) + abs(j-j2) + abs(j-j1);}
                    }
    
    if(minWay2 < minWay)
    {
            for(int i = 0;i <= 10; i++)
                for(int j = 0;j <= 17; j++)
                        booleanWay[i][j]=0;
            //Print line 1 straight down
            if(jonnhat > j1)    for(int jj = j1; jj <= jonnhat; jj++) booleanWay[i1][jj] = 1;
                else            for(int jj = j1; jj >= jonnhat; jj--) booleanWay[i1][jj] = 1;
            if(jonnhat > j2)    for(int jj = j2; jj <= jonnhat; jj++) booleanWay[i2][jj] = 1;
                else            for(int jj = j2; jj >= jonnhat; jj--) booleanWay[i2][jj] = 1;
            //Print horizontal number 1 lines
            if(i1<=i2)          for(int ii = i1; ii <= i2; ii++) booleanWay[ii][jonnhat] = 1;
                else            for(int ii = i2; ii <= i1; ii++) booleanWay[ii][jonnhat] = 1;
            minWay = minWay2;
    }

	return dau;
}
bool timduongdi(SDL_Texture* texture,SDL_Renderer* renderer,int i1,int j1,int i2,int j2)
{
    minWay = 10000;
    for(int i = 0;i <= 10; i++)
        for(int j = 0;j <= 17; j++) 
            booleanWay[i][j] = 0;

    booleanWay[i1][j1] = 1;
    booleanWay[i2][j2] = 1;

    if( (i2 == i1+1 && j2 == j1) || (i2 == i1 && j2 == j1+1) || (i2 == i1-1 && j2 == j1) || (i2 == i1 && j2 == j1-1) ) minWay = 2; //2 con cạnh nhau
    else if( testtwopointsin( i1, j1, i2, j2) == false) return false;

    monstevalue[i1][j1] = 0;
    monstevalue[i2][j2] = 0;
    for(int i = 0;i <= 10; i++)
        for(int j = 0;j <= 17; j++)
            if(booleanWay[i][j] == 1)
                if( (i == i1 && j == j1) || (i == i2 && j == j2) )
                {
                    if(booleanWay[i-1][j] == 1)
                        {
                        SDL_Rect range;
                        range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                        range.h = 56; range.w = 46;
                        SDL_RenderCopy(renderer, texture_noithang1, NULL, &range);
                    }
                    else
                    if(booleanWay[i][j+1]==1)
                        {
                        SDL_Rect range;
                        range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                        range.h = 56; range.w = 46;
                        SDL_RenderCopy(renderer, texture_noingang2, NULL, &range);
                    }
                    else
                    if(booleanWay[i+1][j]==1)
                        {
                        SDL_Rect range;
                        range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                        range.h = 56; range.w = 46;
                        SDL_RenderCopy(renderer, texture_noithang3, NULL, &range);
                    }
                    else
                    if(booleanWay[i][j-1]==1)
                        {
                        SDL_Rect range;
                        range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                        range.h = 56; range.w = 46;
                        SDL_RenderCopy(renderer, texture_noingang4, NULL, &range);
                    }
                }
                else
                {
                     if(i >=1  && j >= 1)
                     {
                        if( (booleanWay[i-1][j]==1 || booleanWay[i+1][j]==1) && (booleanWay[i][j+1]==0 && booleanWay[i][j-1]==0))
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noithang, NULL, &range);
                        }
                        else
                        if(booleanWay[i][j+1]==1 && booleanWay[i+1][j]!=1 && booleanWay[i-1][j]!=1)
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noingang, NULL, &range);
                        }
                        else
                        if(booleanWay[i-1][j]==1 && booleanWay[i][j+1]==1)
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noigoc1, NULL, &range);
                        }
                        else
                        if(booleanWay[i+1][j]==1 && booleanWay[i][j+1]==1)
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noigoc2, NULL, &range);
                        }
                        else
                        if(booleanWay[i][j-1]==1 && booleanWay[i+1][j]==1)
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noigoc3, NULL, &range);
                        }
                        else
                        if(booleanWay[i][j-1]==1 && booleanWay[i-1][j]==1)
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noigoc4, NULL, &range);
                        }
                     }
                     if(i==0)
                     {
                        if(booleanWay[i][j+1]==1 && booleanWay[i+1][j]!=1 )
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noingang, NULL, &range);
                        }
                        else
                        if(booleanWay[i+1][j]==1 && booleanWay[i][j+1]==1)
                        {
                            texture = IMG_LoadTexture( renderer, "anh/noigoc2.png");
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture, NULL, &range);
                        }
                        else
                        if(booleanWay[i][j-1] == 1 && booleanWay[i+1][j] ==1)
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noigoc3, NULL, &range);
                        }
                     }
                     if(j==0)
                     {
                        if( (booleanWay[i-1][j] == 1 || booleanWay[i+1][j] == 1) && booleanWay[i][j+1] == 0 )
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noithang, NULL, &range);
                        }
                        if(booleanWay[i-1][j]==1 && booleanWay[i][j+1]==1)
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noigoc1, NULL, &range);
                        }
                        else
                        if(booleanWay[i+1][j]==1 && booleanWay[i][j+1]==1)
                        {
                            SDL_Rect range;
                            range.x = 227+(j-1)*43; range.y = 57+(i-1)*53;
                            range.h = 56; range.w = 46;
                            SDL_RenderCopy(renderer, texture_noigoc2, NULL, &range);
                        }
                     }
                }
    SDL_RenderPresent(renderer);
    Score+=minWay;
    return true;
}
#endif // _timduongdi_
