#include"header.h"

string to_lowercase(string str)
{
    int l,i;

    l = str.length();

    for(i=0;i<l;i++)
    {
        if((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            str[i] += 32;
        }
    }
    return str;
}

string to_uppercase(string str)
{
    int l,i;

    l = str.length();

    for(i=0;i<l;i++)
    {
        if((str[i] >= 'a') && (str[i] <= 'z'))
        {
            str[i] -= 32;
        }
    }
    return str;
}
