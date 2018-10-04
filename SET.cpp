#include"header.h"
#include"basic_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void SET(string instr[65536],string opr,registers *rg,int *ias)
{
    string adr,val;
    int l,ind;

    l = opr.length();

    if(l == 7)
    {
        if(opr[4] == ',')
        {
            adr = opr.substr(0,4);
            hex_validator(adr,4);
            ind = dec_converter(adr);

            val = opr.substr(5,6);
            hex_validator(val,2);

            instr[ind] = val;

            *ias += 3;

            adr = hex_converter(*ias);
            rg->PC = value_adjuster(adr,4);
        }
    }
    else
    {
        cout<<"Invalid Operand Found!"<<endl;
        display(*rg);
        exit(0);
    }
}
