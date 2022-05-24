#ifndef _mapChecker_
#define _mapChecker_
bool kt(int i,int j)
{
    for(int ii = 1; ii <= 9; ii++)
        for(int jj = 1;jj <= 16; jj++)
	 		if( ii * 20 + jj >= i * 20 + j ) break;
	 		else if(monstevalue[ii][jj] == monstevalue[i][j] && monstevalue[i][j] > 0 && i*ii*j*jj !=0)
				  	if(testtwopoints(i,j,ii,jj) == true) return true;
    return false;
}
int kiemtra()
{
    int Count=0;
    //----------The loop to create sign "+"
    for(int i = 0; i <= 10; i++)
        for(int j = 0; j <= 17; j++)
        {
            Plus_sign[i][j].i1 = i; //coordidate of element Plus_sign[i][j]
            Plus_sign[i][j].j2 = j;
            Plus_sign[i][j].i3 = i;
            Plus_sign[i][j].j4 = j;
            for(int ii = i-1; ii >= 0; ii--) // + : paint the way -> Up 
                if(monstevalue[ii][j] == 0) Plus_sign[i][j].i1 = ii;
                    else break;
            for(int ii = i+1; ii <= 10; ii++) // + : paint the way -> Down
                if(monstevalue[ii][j] == 0) Plus_sign[i][j].i3 = ii;
                    else break;
            for(int jj = j-1; jj >= 0; jj--) // + : paint the way -> Left
                if(monstevalue[i][jj] == 0) Plus_sign[i][j].j4 = jj;
                    else break;
            for(int jj = j+1; jj <= 17; jj++) // + : paint the way -> Right
                if(monstevalue[i][jj] == 0) Plus_sign[i][j].j2 = jj;
                    else break;
            if(monstevalue[i][j] == 0) { // increase 1 unit for length of 4 way of Plus Sign "+"  
                Plus_sign[i][j].i1 --;
                Plus_sign[i][j].j2 ++;
                Plus_sign[i][j].i3 ++;
                Plus_sign[i][j].j4 --;
            }
    //----------The loop to create sign "+"
            if(monstevalue[i][j] > 0)
                if(kt( i, j) == true) Count++;
            // if variable Count=0 <=> Map has no one edible pairs -> Shuffle map
        }
    
    return Count;
}
#endif // _mapChecker_
