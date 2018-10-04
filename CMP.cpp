#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void CMP(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval;
    string adr,hdif;
    int l;

    l = opr.length();

    if(l == 1)
    {
        rval = NULL;
        rval = validate_register(rg,instr,opr[0]);

        hdif = hex_subtracter(rg,rg->A,*rval,1);

        *ias += 2;

        adr = hex_converter(*ias);
        adr = to_uppercase(adr);
        rg->PC = value_adjuster(adr,4);
    }
    else if(l==4)
    {
        rval = NULL;
        rval = validate_address(instr,opr);

        hdif = hex_subtracter(rg,rg->A,*rval,1);

        *ias += 3;

        adr = hex_converter(*ias);
        adr = to_uppercase(adr);
        rg->PC = value_adjuster(adr,4);
    }
    else
    {
        cout<<"Invalid Operand Found!";
        exit(0);
    }
}
