#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void SUB(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval,*aval;
    string hdif,adr;
    int l;

    l = opr.length();

    rval == NULL;
    if(l == 1)
    {
        rval = validate_register(rg,instr,opr[0]);

        hdif = hex_subtracter(rg,rg->A,*rval,1);

        hdif = to_uppercase(hdif);
        rg->A = value_adjuster(hdif,2);

        *ias += 2;

        adr = hex_converter(*ias);
        adr = to_uppercase(adr);
        rg->PC = value_adjuster(adr,4);
    }
    else if(l == 4)
    {
        aval = validate_address(instr,opr);

        hdif = hex_subtracter(rg,rg->A,*aval,1);

        hdif = to_uppercase(hdif);
        rg->A = value_adjuster(hdif,2);

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
