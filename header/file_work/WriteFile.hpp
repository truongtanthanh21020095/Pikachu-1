#ifndef _WriteFile_
#define _WriteFile_

void WriteFileMonsteValue()
{
  if ("DataMonsteValue.txt" != NULL)
  {
    fstream data_file;
    data_file.open("DataMonsteValue.txt", ios::out);
    for(int i =  0; i <= 10; i++)
    {
        for(int j = 0; j <= 17; j++)
            if(monstevalue[i][j] <= 9) data_file<<" "<<monstevalue[i][j]<<" ";
                else data_file<<monstevalue[i][j]<<" ";
        data_file<<endl;
    }
    data_file.close();
  }
}
void WriteFileMonste()
{
  if ("DataMonste.txt" != NULL)
  {
    fstream data_file;
    data_file.open("DataMonste.txt", ios::out);
    for(int i =  0; i <= 40; i++)
    {
        data_file<< monste[i] <<" "<<endl;
    }
    data_file.close();
  }
}
void WriteFileData()
{
  if ("Data.txt" != NULL)
  {
    fstream data_file;
    data_file.open("Data.txt", ios::out);
    data_file<< change_NumberToString(level) <<endl;
    data_file<< change_NumberToString(Score)<< endl;
    data_file<< change_NumberToString(numOfHints) <<endl;
    data_file<< change_NumberToString(timegame) <<endl;
    data_file.close();
  }
}

void WriteFile()
{
    WriteFileData();

    WriteFileMonste();

    WriteFileMonsteValue();

}
#endif // _WriteFile_
