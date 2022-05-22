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
    int dem=0;
    //----------Vòng lặp để sinh dấu +
    for(int i = 0; i <= 10; i++)
        for(int j = 0; j <= 17; j++)
        {
            Plus_sign[i][j].i1 = i; //tọa độ của phần tử cong[i][j]
            Plus_sign[i][j].j2 = j;
            Plus_sign[i][j].i3 = i;
            Plus_sign[i][j].j4 = j;
            for(int ii = i-1; ii >= 0; ii--) //dấu + : vẽ đường lên trên 
                if(monstevalue[ii][j] == 0) Plus_sign[i][j].i1 = ii;
                    else break;
            for(int ii = i+1; ii <= 10; ii++) //dấu + : vẽ đường xuống dưới
                if(monstevalue[ii][j] == 0) Plus_sign[i][j].i3 = ii;
                    else break;
            for(int jj = j-1; jj >= 0; jj--) //dấu + : vẽ đường sang trái
                if(monstevalue[i][jj] == 0) Plus_sign[i][j].j4 = jj;
                    else break;
            for(int jj = j+1; jj <= 17; jj++) //dấu + : vẽ đường sang phải
                if(monstevalue[i][jj] == 0) Plus_sign[i][j].j2 = jj;
                    else break;
            if(monstevalue[i][j] == 0) { // tăng độ dài 4 đường dấu + lên 1 ô 
                Plus_sign[i][j].i1 --;
                Plus_sign[i][j].j2 ++;
                Plus_sign[i][j].i3 ++;
                Plus_sign[i][j].j4 --;
            }
    //----------Vòng lặp để sinh dấu +
            if(monstevalue[i][j] > 0)
                if(kt( i, j) == true) dem++;
            // nếu biến dem=0 <=> không còn con nào ăn được -> trộn lại
        }
    
    return dem;
}
#endif // _mapChecker_
