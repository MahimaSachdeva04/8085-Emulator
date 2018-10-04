#include"header.h"
#include"basic_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void MVI(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval;
    string val,adr;
    int l;

    l = opr.length();

    rval = NULL;

    if(l == 4)
    {
        if(opr[1] == ',')
        {
            if(opr[0] == 'F')
            {
                cout<<"Register F cannot be accessed!";
                exit(0);
            }

            rval = validate_register(rg,instr,opr[0]);

            val = opr.substr(2,l);

            hex_validator(val,2);

            *rval = val;

            *ias += 2;

            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            rg->PC = value_adjuster(adr,4);
        }
        else
        {
            cout<<"Invalid operand found!"<<endl<<endl;
            display(*rg);
            exit(0);
        }
    }
    else
    {
        cout<<"Invalid operand found!"<<endl<<endl;
        display(*rg);
        exit(0);
    }
}
