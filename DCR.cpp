#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void DCR(string instr[65536],string str,registers *rg,int *ias)
{
    string *rval;
    string adr,hdif;
    int l,ind,mode;

    l = str.length();

    if(l == 1)
    {
        rval = validate_register(rg,instr,str[0]);

        mode = 0;
        if(str[0] != 'M')
        {
            if(str[0] == 'A')
            {
                mode = 1;
            }

            hdif = hex_subtracter(rg,*rval,"1",mode);

            hdif = to_uppercase(hdif);
            hdif = value_adjuster(hdif,2);

            *rval = hdif;

            *ias += 1;

            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            rg->PC = value_adjuster(adr,4);
        }
        else
        {
            adr = (*rg).L;
            adr = (*rg).H+adr;

            ind = dec_converter(adr);
            hdif = hex_subtracter(rg,instr[ind],"1",0);

            instr[ind] = hdif;

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
