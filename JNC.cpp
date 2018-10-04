#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void JNC(ifstream *fin,string instr[65536],string opr,registers *rg,tregisters *trg,string mne[30],int *ias,int *ic)
{
    string adr,tstr;
    int l,ind,temp;

    if(rg->F[7] != "1")
    {
        l = opr.length();

        if(l == 4)
        {
            hex_validator(opr,4);

            ind = dec_converter(opr);

            temp = *ias;

            if(ind <= *ias)
            {
                *ias = ind;

                while(*ias < temp)
                {
                    executer(fin,instr,instr[*ias],rg,trg,mne,ias,ic);
                }

                executer(fin,instr,instr[*ias],rg,trg,mne,ias,ic);
            }
            else
            {
                *ias += 3;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);

                copy_data(rg,trg);

                while(*ias < ind)
                {
                    getline(*fin,tstr);

                    tstr = to_uppercase(tstr);
                    instr[*ias] = tstr;

                    executer(fin,instr,instr[*ias],rg,trg,mne,ias,ic);

                    *ic += 1;
                }
                if(*ias > ind)
                {
                    cout<<"Address mentioned is not proper";
                    exit(0);
                }
                revertback_data(rg,trg);
            }
        }
        else
        {
            cout<<"Invalid Operand Found!";
            exit(0);
        }
    }
    else
    {
        *ias += 3;

        adr = hex_converter(*ias);
        adr = to_uppercase(adr);
        rg->PC = value_adjuster(adr,4);
    }
}
