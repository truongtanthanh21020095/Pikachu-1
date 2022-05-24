#ifndef _gamehints_
#define _gamehints_
coordinate hints[300]; //Array contains all of available "eat" monter pairs
int testhint()
{
    int d = 0;
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 16; j++)
            if(monstevalue[i][j] > 0 )
            {
                for(int ii = 1;ii <= 9; ii++)
                  for(int jj = 1;jj <= 16; jj++)
	 		        if(ii*20 + jj >= i*20 + j) break;
                    else if (monstevalue[ii][jj] == monstevalue[i][j]) {
                        if (testtwopoints(i, j, ii, jj) == true) {
                            d++;
                            hints[2 * d].i = i; //Save the coordinates of edible pairs
                            hints[2 * d].j = j;
                            hints[2 * d + 1].i = ii;
                            hints[2 * d + 1].j = jj;
                        }
                    }
            }
    return d;
}

void hint(SDL_Texture* texture,SDL_Renderer* renderer)
{
     printMap(texture,renderer);
     int dem1 = testhint();
 
     hints[0].i = 0;
     hints[0].j = 0;
     hints[1].i = 0;
     hints[1].j = 0;
 
     int xx = 0;
     while(hints[ 2*xx ].i * hints[ 2*xx + 1].i * hints[2*xx].j * hints[ 2*xx + 1].j == 0)
     {
         xx = rand();
         xx = xx%dem1+1;
     }

     SDL_Rect range;
     range.x = 230+(hints[2*xx].j-1)*43-3; range.y = 60+(hints[2*xx].i-1)*53-3;
     range.h = 56; range.w = 46;
     SDL_RenderCopy(renderer, texture_picking, NULL, &range);

     range.x = 230+(hints[2*xx+1].j-1)*43-3; range.y = 60+(hints[2*xx+1].i-1)*53-3;
     range.h = 56; range.w = 46;
     SDL_RenderCopy(renderer, texture_picking, NULL, &range);

     SDL_RenderPresent(renderer);
}
#endif // _gamehints_
