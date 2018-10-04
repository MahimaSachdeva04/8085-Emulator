#include"header.h"
#include"operation_tools.h"
#include"convert_revert_tools.h"

void bin_adder(char ch1,char ch2,char *carry,char *res)
{
    int n1,n2,cry,isum,l;

    if((ch1 == '0') && (ch2 == '0'))
    {
        n1 = 0;
        n2 = 0;
    }
    else if((ch1 == '0') && (ch2 == '1'))
    {
        n1 = 0;
        n2 = 1;
    }
    else if((ch1 == '1') && (ch2 == '0'))
    {
        n1 = 1;
        n2 = 0;
    }
    else if((ch1 == '1') && (ch2 == '1'))
    {
        n1 = 1;
        n2 = 1;
    }
    else
    {
        cout<<"Invalid Data Found!";
        exit(0);
    }

    if(*carry == '0')
    {
        cry=0;
    }
    else if(*carry == '1')
    {
        cry=1;
    }
    else
    {
        cout<<"Invalid Carry Bit found!";
        exit(0);
    }

    isum = n1+n2+cry;

    if(isum == 2)
    {
        isum = 11;
    }

    stringstream ss;
    ss<<isum;
    string str=ss.str();

    l=str.length();

    if(l>1)
    {
        *carry='1';
    }
    else
    {
        *carry='0';
    }

    *res=str[l-1];
}

string hex_adder(registers *rg,string str1,string str2,int mode)
{
    string hsum,thsum,temp;
    int isum,n1,n2,l1,l2;

    n1 = dec_converter(str1);
    n2 = dec_converter(str2);

    isum = n1+n2;

    hsum = hex_converter(isum);

    if(mode == 1)
    {
        l1 = str1.length();
        l2 = str2.length();
        flag_setter(hsum,str1[l1-1],str2[l2-1],'+',rg);
    }

    return hsum;
}

string hex_subtracter(registers *rg,string str1,string str2,int mode)
{
    string hdif,thdif,temp;
    int idif,flag,n1,n2,l1,l2;

    n1 = dec_converter(str1);
    n2 = dec_converter(str2);

    idif = n1-n2;

    flag = 0;
    if(idif < 0)
    {
        flag = 1;
        idif = idif*-1;
    }
    hdif = hex_converter(idif);
    hdif = value_adjuster(hdif,2);

    if(flag == 1)
    {
        hdif = IIs_compliment(hdif);

        idif = idif*-1;
    }

    if(mode==1)
    {
        l1 = str1.length();
        l2 = str2.length();
        flag_setter(hdif,str1[l1-1],str2[l2-1],'-',rg);
    }

    return hdif;
}
