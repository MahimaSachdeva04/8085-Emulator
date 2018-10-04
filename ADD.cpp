#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void ADD(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval,*aval;
    string adr,hsum;
    int l;

    l = opr.length();

    rval == NULL;
    if(l == 1)
    {
        rval = validate_register(rg,instr,opr[0]);

        hsum = hex_adder(rg,rg->A,*rval,1);

        hsum = value_adjuster(hsum,2);

        rg->A = to_uppercase(hsum);

        *ias += 1;

        adr = hex_converter(*ias);
        adr = to_uppercase(adr);
        rg->PC = value_adjuster(adr,4);
    }
    else if(l == 4)
    {
        aval = validate_address(instr,opr);

        hsum = hex_adder(rg,rg->A,*aval,1);
        hsum = to_uppercase(hsum);
        rg->A = value_adjuster(hsum,2);

        *ias += 3;

        adr = hex_converter(*ias);
        adr = to_uppercase(adr);
        rg->PC = value_adjuster(adr,4);
    }
    else
    {
        cout<<"Invalid operand found!";
        exit(0);
    }
}
