#ifndef _ReadFile_
#define _ReadFile_

void ReadFileMonsteValue()
{
     string input;
     fstream fsFile;
     int i=0;
     int j=0;
     fsFile.open("DataMonsteValue.txt", ios::in);
     if (fsFile.fail() == true)    cout << "Cannot read file! DataMonsteValue.txt";
        else
            {
                  while (fsFile >> input)
                    {
                        monstevalue[i][j] = atoi(input.c_str());
                        j++;
                        if(j>=18){ i++; j=0;}
                        if(i>=11) break;
                    }
            }
     fsFile.close();
}
void ReadFileMonste()
{
     string input;
     fstream fsFile;
     int i=0;
     fsFile.open("DataMonste.txt", ios::in);
     if (fsFile.fail() == true)    cout << "Cannot read file! DataMonste.txt";
        else
            {
                  while (fsFile >> input)
                    {
                        monste[i] = atoi(input.c_str());
                        i++;
                        if(i>=36) break;
                    }
            }
     fsFile.close();
}
void ReadFileData()
{
     string input;
     fstream fsFile;
     int i=0;
     fsFile.open("Data.txt", ios::in);
     if (fsFile.fail() == true)    cout << "Cannot read file! Data.txt";
        else
            {
                  while (fsFile >> input)
                    {
                        i++ ;
                        if(i == 1) level = atoi(input.c_str());
                        if(i == 2) Score = atoi(input.c_str());
                        if(i == 3) numOfHints = atoi(input.c_str());
                        if(i == 4) timegame= atoi(input.c_str());
                        if(i >= 5 ) break;
                    }
            }

     fsFile.close();
}
void ReadFile()
{
    ReadFileData();
    ReadFileMonste();
    ReadFileMonsteValue();
}
#endif // _ReadFile_

