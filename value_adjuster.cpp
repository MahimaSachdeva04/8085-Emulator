#include"header.h"

string value_adjuster(string str,int n)
{
    string tstr;
    int l,i,j;

    l = str.length();

    tstr = "";
    if(n > l)
    {
        for(i=0;i<(n-l);i++)
        {
            tstr += "0";
        }
        tstr += str;
    }
    else if(n < l)
    {
        j = l-1;
        for(i=n-1;i>=0;i--)
        {
            tstr = str[j]+tstr;
            j--;
        }
    }
    else
    {
        tstr = str;
    }

    return tstr;
}
