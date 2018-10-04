#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void SUI(string instr[65536],string opr,registers *rg,int *ias)
{
    string hdif,adr;
    int l;

    l = opr.length();

    if(l == 2)
    {
        hex_validator(opr,2);

        hdif = hex_subtracter(rg,rg->A,opr,1);

        hdif = to_uppercase(hdif);

        rg->A = value_adjuster(hdif,2);

        *ias += 2;

        adr = hex_converter(*ias);
        rg->PC = value_adjuster(adr,4);
    }
    else
    {
        cout<<"Invalid Operand Found!";
        exit(0);
    }
}
