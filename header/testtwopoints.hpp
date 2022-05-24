#ifndef _testtwopoints_
#define _testtwopoints_
//---- Use for check all map, not for check 2 monter selected


//Check if the 2 + signs touch each other
bool testtwopoints(int i1, int j1, int i2, int j2)
{
    // j <=> Ox, jmin: drag left, jmax: drag right
    // i <=> Oy, imin: drag down, imax: drag up 
	int imin,imax,jmin,jmax;
    imin = max (Plus_sign[i1][j1].i1, Plus_sign[i2][j2].i1);
    imax = min (Plus_sign[i1][j1].i3, Plus_sign[i2][j2].i3);
    jmin = max (Plus_sign[i1][j1].j4, Plus_sign[i2][j2].j4);
    jmax = min (Plus_sign[i1][j1].j2, Plus_sign[i2][j2].j2);
    // consider Oy intersection (with overlap of 1 or more rows)
    if(j2 < j1){ swap(i1, i2);  swap(j1, j2);}
	if(imin <= imax)
		for(int i = imin; i <= imax; i++)
			if(Plus_sign[i][j1].j2 >= j2) return true;

    // consider Oy\x intersection (with overlap of 1 or more collums)
    if(i1 > i2){ swap(i1, i2);  swap(j1, j2);}
    if(jmin < jmax)
        for(int j = jmin; j <= jmax; j++)
            if(Plus_sign[i1][j].i3>=i2) return true;

    return false;
}
#endif // _testtwopoints_
