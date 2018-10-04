#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void DAD(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval;
    string adr,tstr;
    int l;

    l = opr.length();

    if(l == 1)
    {
        rval = NULL;
        rval = validate_register(rg,instr,opr[0]);

        if((opr[0] == 'B')||(opr[0] == 'D')||(opr[0] == 'H'))
        {
            if(opr[0] == 'B')
            {
                rg->L = hex_adder(rg,rg->L,rg->C,0);

                rg->H = hex_adder(rg,rg->H,rg->B,0);

                l = rg->L.length();
                if(l > 2)
                {
                    tstr = (rg->L)[0];
                    rg->H = hex_adder(rg,rg->H,tstr,0);

                    rg->L = value_adjuster(rg->L,2);
                }

                l = rg->H.length();
                if(l > 2)
                {
                    rg->H = value_adjuster(rg->H,2);
                }

                rg->L = to_uppercase(rg->L);
                rg->H = to_uppercase(rg->H);


                *ias += 3;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
            else if(opr[0]=='D')
            {
                rg->L = hex_adder(rg,rg->L,rg->E,0);

                rg->H = hex_adder(rg,rg->H,rg->D,0);

                l = rg->L.length();
                if(l > 2)
                {
                    tstr = rg->L[0];
                    rg->H = hex_adder(rg,rg->H,tstr,0);

                    rg->L = value_adjuster(rg->L,2);
                }

                l = (rg->H).length();
                if(l > 2)
                {
                    rg->H = value_adjuster(rg->H,2);
                }

                rg->L = to_uppercase(rg->L);
                rg->H = to_uppercase(rg->H);


                *ias += 3;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
            else
            {
                rg->L = hex_adder(rg,(*rg).L,(*rg).L,0);

                rg->H = hex_adder(rg,(*rg).H,(*rg).H,0);

                l = (rg->L).length();
                if(l > 2)
                {
                    tstr = (rg->L)[0];
                    rg->H = hex_adder(rg,rg->H,tstr,0);

                    rg->L = value_adjuster(rg->L,2);
                }

                l = (rg->H).length();
                if(l > 2)
                {
                    rg->H = value_adjuster(rg->H,2);
                }

                rg->L = to_uppercase(rg->L);
                rg->H = to_uppercase(rg->H);


                *ias += 3;

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
