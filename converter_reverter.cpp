#include"header.h"

string hex_converter(int n)
{
	stringstream ss;
    ss<<hex<<n;
    string res(ss.str());

	return res;
}

int dec_converter(string str)
{
    int res;

    stringstream ss;
    ss<<str;
    ss>>hex>>res;

	return res;
}

string bin_converter(string hval)
{
    string res;
    int l,i;

	l = hval.length();

	res = "";
	for(i=0;i<l;i++)
    {
        switch(hval[i])
        {
            case '0':
                    res += "0000";
                    continue;
            case '1':
                    res += "0001";
                    continue;
            case '2':
                    res += "0010";
                    continue;
            case '3':
                    res += "0011";
                    continue;
            case '4':
                    res += "0100";
                    continue;
            case '5':
                    res += "0101";
                    continue;
            case '6':
                    res += "0110";
                    continue;
            case '7':
                    res += "0111";
                    continue;
            case '8':
                    res += "1000";
                    continue;
            case '9':
                    res += "1001";
                    continue;
            case 'A':
                    res += "1010";
                    continue;
            case 'B':
                    res += "1011";
                    continue;
            case 'C':
                    res += "1100";
                    continue;
            case 'D':
                    res += "1101";
                    continue;
            case 'E':
                    res += "1110";
                    continue;
            case 'F':
                    res += "1111";
                    continue;
            default:
                    cout<<"Invalid Data Found!";
                    exit(0);
        }
    }
	return res;
}

string bin_reverter(string bval)
{
    string tstr,res;
    int l,i;

    l = bval.length();

    res = "";
    i = 0;
    while(i<l)
    {
        tstr = bval.substr(i,(i+4));
        i += 4;

        if(tstr == "0000")
        {
            res += "0";
        }
        else if(tstr == "0001")
        {
            res += "1";
        }
        else if(tstr == "0010")
        {
            res += "2";
        }
        else if(tstr == "0011")
        {
            res += "3";
        }
        else if(tstr == "0100")
        {
            res += "4";
        }
        else if(tstr == "0101")
        {
            res += "5";
        }
        else if(tstr == "0110")
        {
            res += "6";
        }
        else if(tstr == "0111")
        {
            res += "7";
        }
        else if(tstr == "1000")
        {
            res += "8";
        }
        else if(tstr == "1001")
        {
            res += "9";
        }
        else if(tstr == "1010")
        {
            res += "A";
        }
        else if(tstr == "1011")
        {
            res += "B";
        }
        else if(tstr == "1100")
        {
            res += "C";
        }
        else if(tstr == "1101")
        {
            res += "D";
        }
        else if(tstr == "1110")
        {
            res += "E";
        }
        else if(tstr == "1111")
        {
            res += "F";
        }
        else
        {
            cout<<"Invalid Data Found!";
            exit(0);
        }
    }

    return res;
}
