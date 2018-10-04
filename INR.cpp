#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void INR(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval;
    string adr,hsum;
    int l,ind,mode;

    l = opr.length();

    if(l == 1)
    {
        rval = validate_register(rg,instr,opr[0]);

        mode = 0;
        if(opr[0] != 'M')
        {
            if(opr[0] == 'A')
            {
                mode = 1;
            }

            hsum = hex_adder(rg,*rval,"1",mode);

            hsum = to_uppercase(hsum);
            hsum = value_adjuster(hsum,2);

            *rval = hsum;

            *ias += 1;

            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            rg->PC = value_adjuster(adr,4);
        }
        else
        {
            adr = rg->L;
            adr = rg->H+adr;

            ind = dec_converter(adr);
            hsum = hex_adder(rg,instr[ind],"1",0);

            instr[ind] = hsum;

            *ias += 1;

            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            rg->PC = value_adjuster(adr,4);
        }
    }
    else
    {
        cout<<"Invalid Operand Found!";
        exit(0);
    }
}
