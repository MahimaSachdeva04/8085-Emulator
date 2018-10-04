#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void CMA(string instr[65536],string opr,registers *rg,int *ias)
{
    string bval,adr;
    int l,i;

    l = opr.length();

    if(l == 0)
    {
        bval = bin_converter(rg->A);

        l = bval.length();

        for(i=0;i<l;i++)
        {
           if(bval[i] == '1')
           {
               bval[i] = '0';
           }
           else if(bval[i] == '0')
           {
               bval[i] = '1';
           }
           else
           {
               cout<<"Invalid Bit Found!";
               exit(0);
           }
        }

        rg->A = bin_reverter(bval);


        *ias += 1;

        adr = hex_converter(*ias);
        adr = to_uppercase(adr);
        rg->PC = value_adjuster(adr,4);
    }
    else
    {
        cout<<"Invalid Instruction Found!";
        exit(0);
    }
}
