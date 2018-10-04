#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void ADI(string instr[65536],string opr,registers *rg,int *ias)
{
    string hsum,adr;
    int l;

    l = opr.length();

    if(l == 2)
    {
        hex_validator(opr,2);

        hsum = hex_adder(rg,rg->A,opr,1);

        hsum = to_uppercase(hsum);

        rg->A = value_adjuster(hsum,2);


        *ias += 2;

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
