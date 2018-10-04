#include"header.h"
#include"basic_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void STA(string instr[65536],string opr,registers *rg,int *ias)
{
    string adr;
    int ind;

    hex_validator(opr,4);

    ind = dec_converter(opr);

    instr[ind] = rg->A;

    *ias += 3;

    adr = hex_converter(*ias);
    adr = to_uppercase(adr);
    rg->PC = value_adjuster(adr,4);
}
