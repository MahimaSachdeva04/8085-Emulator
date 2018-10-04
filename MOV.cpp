#include"header.h"
#include"basic_tools.h"
#include"convert_revert_tools.h"
#include"validation_tools.h"

void MOV(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval,*rval1,*rval2,*aval;
    string adr;
    int l,ind;

    rval1 = NULL;
    rval2 = NULL;

    l = opr.length();


    if(l == 3)
    {
        if(opr[1] == ',')
        {
            if((opr[0] == 'F') || (opr[2] == 'F'))
            {
                cout<<"Register F cannot be accessed!";
                exit(0);
            }

            rval1 = validate_register(rg,instr,opr[0]);
            rval2 = validate_register(rg,instr,opr[2]);

            *rval1 = *rval2;
            *ias += 1;

            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            rg->PC = value_adjuster(adr,4);
        }
        else
        {
            cout<<"Invalid operand found!"<<endl;
            display(*rg);
            exit(0);
        }
    }
    else if(l == 6)
    {
        if(opr[1] == ',')
        {
            if(opr[0] == 'F')
            {
                cout<<"Register F cannot be accessed!";
                exit(0);
            }

            rval = validate_register(rg,instr,opr[0]);

            adr = opr.substr(2,l);
            aval = validate_address(instr,adr);

            *rval = *aval;
            *ias += 3;

            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            rg->PC = value_adjuster(adr,4);
        }
        else if(opr[4] == ',')
        {
            adr = opr.substr(0,4);
            hex_validator(adr,4);
            ind = dec_converter(adr);

            if(opr[5] == 'F')
            {
                cout<<"Register F cannot be accessed!";
                exit(0);
            }

            rval = validate_register(rg,instr,opr[5]);

            instr[ind] = *rval;

            *ias += 3;

            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            rg->PC = value_adjuster(adr,4);
        }
        else
        {
            cout<<"Invalid operand found!"<<endl;
            display(*rg);
            exit(0);
        }
    }
    else
    {
        cout<<"Invalid operand found!"<<endl;
        display(*rg);
        exit(0);
    }
}
