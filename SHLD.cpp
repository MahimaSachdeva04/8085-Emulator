#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void SHLD(string instr[65536],string opr,registers *rg,int *ias)
{
    string *daval;
    string hsum,adr;
    int isum,ind;

    daval = NULL;
    daval = validate_address(instr,opr);

    ind = dec_converter(opr);
    instr[ind] = rg->L;

    hsum = hex_adder(rg,opr,"1",0);

    hsum = value_adjuster(hsum,4);

    isum = dec_converter(hsum);

    daval = NULL;
    daval = validate_address(instr,hsum);

    ind = dec_converter(hsum);
    instr[ind] = rg->H;

    *ias += 3;

    adr = hex_converter(*ias);
    adr = to_uppercase(adr);
    rg->PC = value_adjuster(adr,4);
}
