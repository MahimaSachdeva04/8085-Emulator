#include"header.h"
#include"operation_tools.h"
#include"convert_revert_tools.h"

void flag_setter(string res,char ch1,char ch2,char op,registers *rg)
{
    string tstr;
    int l,c;

    l = res.length();
    if(l > 2)
    {
        rg->F[7] = "1";       //Setting Carry Flag

        res = value_adjuster(res,2);
    }
    else
    {
        rg->F[7] = "0";
    }

    tstr = bin_converter(res);
    if(tstr[0] == '1')
    {
        rg->F[0] = "1";       //Setting Up Sign Flag
    }
    else
    {
        rg->F[0] = "0";
    }

    c = 0;
    l = tstr.length();
    for(int i=0;i<l;i++)
    {
        if(tstr[i] == '1')
        {
            c++;
        }
    }
    if(c%2 != 0)
    {
        rg->F[5] = "1";       //Setting Up Parity Flag
    }
    else
    {
        rg->F[5] = "0";
    }

    if(res == "00")
    {
        rg->F[1] = "1";       //Setting Up Zero Flag
    }
    else
    {
        rg->F[1] = "0";
    }


    string s1,s2,hsum;
    int n1,n2,isum;

    s1 = ch1;
    s2 = ch2;

    n1 = dec_converter(s1);
    n2 = dec_converter(s2);

    if(op == '+')
    {
        isum = n1+n2;
    }
    else if(op == '-')
    {
        isum = n1-n2;
    }
    else
    {
        cout<<"Invalid Operator Found!";
        exit(0);
    }

    hsum = hex_converter(isum);
    l = hsum.length();

    if((l > 1) || (isum < 0))
    {
        rg->F[3] = "1";       //Setting Up Auxullary Carry Flag
    }
    else
    {
        rg->F[3] = "0";
    }
}
