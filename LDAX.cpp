#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void LDAX(string instr[65536],string opr,registers *rg,int *ias)
{
    string *drval,adr;
    int l,ind;

    l = opr.length();

    if(l == 1)
    {
        drval = validate_register(rg,instr,opr[0]);

        if((opr[0]=='B') || (opr[0]=='D') || (opr[0]=='H'))
        {
            if(opr[0] == 'B')
            {
                adr = rg->B;
                adr += rg->C;
            }
            else if(opr[0] == 'D')
            {
                adr = rg->D;
                adr += rg->E;
            }
            else
            {
                adr = rg->H;
                adr += rg->L;
            }

            ind = dec_converter(adr);
            rg->A = instr[ind];

            *ias += 2;

            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            rg->PC=value_adjuster(adr,4);
        }
        else
        {
            cout<<"Valid register not found!"<<endl<<endl;
            display(*rg);
            exit(0);
        }
    }
    else
    {
        cout<<"Invalid operand found!"<<endl<<endl;
        display(*rg);
        exit(0);
    }
}
