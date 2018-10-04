#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void DCX(string instr[65536],string opr,registers *rg,int *ias)
{
    string *rval;
    string adr,hdif;
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
                if(rg->C == "00")
                {
                    rg->B = "FF";
                }

                hdif = hex_subtracter(rg,rg->C,"1",0);
                hdif = to_uppercase(hdif);
                rg->C = value_adjuster(hdif,2);

                *ias += 1;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
            else if(opr[0] == 'D')
            {
                hdif = hex_subtracter(rg,rg->E,"1",0);
                hdif = to_uppercase(hdif);
                rg->E = value_adjuster(hdif,2);


                *ias += 1;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
            else
            {
                hdif = hex_subtracter(rg,rg->L,"1",0);
                hdif = to_uppercase(hdif);
                rg->L = value_adjuster(hdif,2);


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
