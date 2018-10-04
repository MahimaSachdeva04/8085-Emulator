#include"header.h"
#include"reg_struct.cpp"
#include"convert_revert_tools.h"

void hex_validator(string str,int width)
{
    int l,i;

    l = str.length();

    if(l == width)
    {
        for(i=0;i<l;i++)
        {
            switch(str[i])
            {
                case '0':
                        continue;
                case '1':
                        continue;
                case '2':
                        continue;
                case '3':
                        continue;
                case '4':
                        continue;
                case '5':
                        continue;
                case '6':
                        continue;
                case '7':
                        continue;
                case '8':
                        continue;
                case '9':
                        continue;
                case 'A':
                        continue;
                case 'B':
                        continue;
                case 'C':
                        continue;
                case 'D':
                        continue;
                case 'E':
                        continue;
                case 'F':
                        continue;
                default:
                        cout<<"Invalid Data Found!";
                        exit(0);
            }
        }
    }
    else
    {
        cout<<"Invalid Data Found!";
        exit(0);
    }
}

int mneuonics_validator(string mne[30],string str)
{
    int flag,i;

    flag = 0;
    for(i=0;i<28;i++)
    {
        if(mne[i] == str)
        {
            flag = 1;
            return i;
        }
    }

    if(flag == 0)
    {
        cout<<"Mneumonic, Not Found!";
        exit(0);
    }

    return 0;
}

string* validate_register(registers *rg,string instr[65535],char ch)
{
    int tM;

    switch(ch)
    {
        case 'A':
                hex_validator(rg->A,2);
                return (&(rg->A));
        case 'B':
                hex_validator(rg->B,2);
                return (&(rg->B));
        case 'C':
                hex_validator(rg->C,2);
                return (&(rg->C));
        case 'D':
                hex_validator(rg->D,2);
                return (&(rg->D));
        case 'E':
                hex_validator(rg->E,2);
                return (&(rg->E));
        case 'H':
                hex_validator(rg->H,2);
                return (&(rg->H));
        case 'L':
                hex_validator(rg->L,2);
                return (&(rg->L));
        case 'M':
                hex_validator(rg->H,2);
                rg->M = rg->H;
                hex_validator(rg->L,2);
                rg->M += rg->L;

                tM=dec_converter(rg->M);
                hex_validator(instr[tM],2);
                return (&(instr[tM]));
        case 'W':
                cout<<"Sorry, You can't access this register!";
                exit(0);
        case 'Z':
                cout<<"Sorry, You can't access this register!";
                exit(0);
        default:
                cout<<"No valid register found!";
                exit(0);
    }
}

string* validate_address(string instr[65536],string adr)
{
    int temp,l;

    l = adr.length();

    if(l == 4)
    {
        hex_validator(adr,4);

        temp = dec_converter(adr);

        if((temp >= 0) && (temp <= 65534))
        {
            hex_validator(instr[temp],2);

            return (&instr[temp]);
        }
        else
        {
            cout<<"Invalid value found at the given address!";
            exit(0);
        }
    }
    else
    {
        cout<<"Invalid address found!";
        exit(0);
    }
}
