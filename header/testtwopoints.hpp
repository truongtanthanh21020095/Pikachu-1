#ifndef _testtwopoints_
#define _testtwopoints_
 // Dùng để kiểm tra toàn map, chứ không ktra 2 con được chọn
bool testtwopoints(int i1, int j1, int i2, int j2) //Ktra xem 2 dấu + có chạm nhau không
{
    // j <=> trục x, jmin: kéo sang trái, jmax: kéo sang phải 
    // i <=> trục y, imin: kéo xuống, imax: kéo lên 
	int imin,imax,jmin,jmax;
    imin = max (Plus_sign[i1][j1].i1, Plus_sign[i2][j2].i1);
    imax = min (Plus_sign[i1][j1].i3, Plus_sign[i2][j2].i3);
    jmin = max (Plus_sign[i1][j1].j4, Plus_sign[i2][j2].j4);
    jmax = min (Plus_sign[i1][j1].j2, Plus_sign[i2][j2].j2);
    // xét giao nhau theo Oy (có trùng nhau 1 hoặc nhiều hàng)
    if(j2 < j1){ swap(i1, i2);  swap(j1, j2);}
	if(imin <= imax)
		for(int i = imin; i <= imax; i++)
			if(Plus_sign[i][j1].j2 >= j2) return true;

    // xét giao nhau theo Ox (có trùng nhau 1 hoặc nhiều cột)
    if(i1 > i2){ swap(i1, i2);  swap(j1, j2);}
    if(jmin < jmax)
        for(int j = jmin; j <= jmax; j++)
            if(Plus_sign[i1][j].i3>=i2) return true;

    return false;
}
#endif // _testtwopoints_
