#ifndef _create_map_
#define _create_map_

bool create()
{	
	int b[40], c[40];
	for(int i = 1; i <= 36; i++){
        b[i] = 0;
        c[i] = 0;
	}
	b[0] = 0;
	for(int i = 1;i <= 36; i++)
        if(monste[i] > 0)
        {
            b[0] ++; // Giá trị b[0] = số lượng các ptu mảng b[] có giá trị
            b[ b[0] ] = i;
            c[i] = monste[i] * 2;
        }
    int dem = 5; // Trong 1 map mới chỉ có tối đa 5 cặp quái ăn được ngay cạnh nhau
    int solanrandom = 0;
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 16; j++)
            if(monstevalue[i][j] > 0) // Mặc định value = 39
		    {
			    while(true)
			    {
                    int x = rand();
                    x = x % b[0] + 1;
                    solanrandom ++;
                    if(solanrandom >= 1000) return false; //Dự phòng nếu vòng lặp random lỗi 

                    if(c[ b[x] ] > 0)
                        if ( monstevalue[i-1][j] == b[x] || monstevalue[i][j-1] == b[x] )
                        {
                                //Xử lí với biến dem khi random ra 2 con cạnh nhau
                                if(dem > 0) {
                                    dem -= 1;
                                    monstevalue[i][j] = b[x];
                                    c[ b[x] ] --;
                                    if(c[ b[x] ] == 0) {
                                        for(int jj = x; jj < b[0]; jj++)
                                            b[jj] = b[jj+1]; // dồn mảng b[] <-> 1 loại monster bị ăn hết 
                                        b[0]--;
                                    }
                                    break;
                                }
                        }
                        else  {
                                monstevalue[i][j] = b[x];
                                c[ b[x] ]--;
                                if(c[ b[x] ] == 0)
                                {
                                    for(int jj = x; jj < b[0]; jj++)
                                        b[jj] = b[jj+1]; // dồn mảng b[] <-> 1 loại monster bị ăn hết 
                                    b[0]--;
                                }
                                break;
                        }
			    }
		    }
    return true;
}

void createmap(SDL_Texture* texture,SDL_Renderer* renderer)
{
	bool mmap = false;
	if(endlevel() == false) {
        while(mmap == false) {
            mmap = create();
        }
	}
    else {
        while (mmap == false) {
            int n = 72; //số cặp quái 
            //-----reset lại value của bảng và monster[] = 0 
            for (int i = 0; i <= 10; i++)
                for (int j = 0; j <= 17; j++)
                    if (i == 0 || j == 0 || i == 10 || j == 17) monstevalue[i][j] = 0; // viền bằng 0 
                    else monstevalue[i][j] = 39; // mặc định value = 39
            for (int i = 1; i <= 39; i++) monste[i] = 0;
            //-----tạo dữ liệu cho mảng monster 36 cặp quái (mỗi ptu = 0 or 1 or 2 or 3)
            while (n > 0)
            {
                int x = rand() % 36 + 1;
                if (monste[x] <= 2) {
                    monste[x] ++;
                    n--;
                }
                else continue;
            }
            mmap = create();
        }
    }
	printMap( texture, renderer );
}

#endif // _create_map_
