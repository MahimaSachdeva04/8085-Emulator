#include"header.h"
#include"convert_revert_tools.h"
#include"operation_tools.h"

string IIs_compliment(string hstr)
{
    string bstr;
    char carry,res;
    int l,i;

    bstr=bin_converter(hstr);

    l=bstr.length();

    for(i=0;i<l;i++)
    {
        if(bstr[i]=='1')
        {
            bstr[i]='0';
        }
        else
        {
            bstr[i]='1';
        }
    }

    carry='0';
    bin_adder(bstr[l-1],'1',&carry,&res);
    hstr=res;
    for(i=l-2;i>=0;i--)
    {
        bin_adder(bstr[i],'0',&carry,&res);
        hstr=res+hstr;
    }

    l=hstr.length();
    while(l%4!=0)
    {
        l--;
    }

    hstr=value_adjuster(hstr,l);

    hstr=bin_reverter(hstr);

    hstr=value_adjuster(hstr,2);

    return hstr;
}
