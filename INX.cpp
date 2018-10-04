#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void INX(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval;
    string adr;
    int l;

    l = opr.length();

    if(l == 1)
    {
        rval = validate_register(rg,instr,opr[0]);

        if((opr[0] == 'B')||(opr[0] == 'D')||(opr[0] == 'H'))
        {
            if(opr[0] == 'B')
            {
                rg->C = hex_adder(rg,rg->C,"1",0);
                l = (rg->C).length();

                if(l > 2)
                {
                    rg->B = hex_adder(rg,rg->B,"1",0);
                }

                rg->C = value_adjuster(rg->C,2);
                rg->B = value_adjuster(rg->B,2);

                *ias += 1;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
            else if(opr[0] == 'D')
            {
                rg->E = hex_adder(rg,rg->E,"1",0);
                l = (rg->E).length();

                if(l > 2)
                {
                    rg->D = hex_adder(rg,rg->D,"1",0);
                }

                rg->E = value_adjuster(rg->E,2);
                rg->D = value_adjuster(rg->D,2);


                *ias += 1;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
            else
            {
                rg->L = hex_adder(rg,rg->L,"1",0);
                l = (rg->L).length();

                if(l > 2)
                {
                    rg->H = hex_adder(rg,rg->H,"1",0);
                }

                rg->L = value_adjuster(rg->L,2);
                rg->H = value_adjuster(rg->H,2);


                *ias += 1;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
        }
        else
        {
            cout<<"Valid register not found!";
            exit(0);
        }
    }
}
