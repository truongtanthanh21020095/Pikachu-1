#ifndef _NumberToString_
#define _NumberToString_

string change_NumberToString(int number)
{
    number = max(number, 0);
    string res;
    while(number > 0){
        res = char(number % 10 + 48) + res;
        number /= 10;
    }
    if(!res.size()) res = "0";
    return res;
}

#endif // _NumberToString_
