#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void HLT(string instr[65536],string str,registers *rg,int *ias,int *ic)
{
    string adr,adr1,adr2,temp;
    int l,ind,ind1,ind2,i;

    l = str.length();

    if(l == 0)
    {
        display(*rg);

        cout<<"\nExecuted Program:-"<<endl;
        for(i = 0;i < 65535;i++)
        {
            cout<<instr[i]<<endl;
            if(instr[i] == "HLT")
            {
                break;
            }
        }

        LABEL:
        cout<<"\n\n\nEnter address to view value:-"<<endl;
        cout<<"For address range(value-value):"<<endl;
        cout<<"For value(value):"<<endl;
        cout<<"Enter your choice:";
        getline(cin,adr);
        adr = to_uppercase(adr);

        l = adr.length();

        if(l == 4)
        {
            hex_validator(adr,4);
            ind = dec_converter(adr);

            if((ind < 0) || (ind > 65534))
            {
                cout<<"Wrong memory range entered!";
                exit(0);
            }

            cout<<"\nValue stored:-"<<endl;
            temp = hex_converter(ind);
            temp = to_uppercase(temp);
            temp = value_adjuster(temp,4);

            cout<<temp<<" "<<instr[ind]<<endl;
        }
        else if(l == 9)
        {
            if(adr[4] == '-')
            {
                adr1 = adr.substr(0,4);
                hex_validator(adr1,4);
                ind1 = dec_converter(adr1);

                if((ind1 < 0) || (ind1 > 65534))
                {
                    cout<<"Wrong memory range entered!";
                    exit(0);
                }

                adr2 = adr.substr(5,l);
                hex_validator(adr2,4);
                ind2 = dec_converter(adr2);


                if((ind2 < 0) || (ind2 > 65534))
                {
                    cout<<"Wrong memory range entered!";
                    exit(0);
                }


                cout<<"\nValues stored:-"<<endl;
                for(i = ind1;i <= ind2;i++)
                {
                    temp = hex_converter(i);
                    temp = to_uppercase(temp);
                    temp = value_adjuster(temp,4);

                    cout<<temp<<" "<<instr[i]<<endl;
                }
            }
            else
            {
                cout<<"Invalid Input Found!";
                exit(0);
            }
        }
        else
        {
            cout<<"Invalid Input Found!";
            exit(0);
        }

        cout<<"\n\n\nPress (Q/q)-To quit the program"<<endl;
        cout<<"Press any other key to continue"<<endl;
        cout<<"Enter your choice:";
        getline(cin,adr);

        adr = to_lowercase(adr);

        if(adr == "q")
        {
            exit(0);
        }
        else
        {
            goto LABEL;
        }

        *ic += 1;

        exit(0);
    }
    else
    {
        cout<<"Invalid Instruction Found!";
        exit(0);
    }
}
