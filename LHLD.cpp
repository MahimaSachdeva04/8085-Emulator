#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void LHLD(string instr[65536],string opr,registers *rg,int *ias)
{
    string *aval;
    string hsum,adr;
    int isum;

    aval = NULL;
    aval = validate_address(instr,opr);

    rg->L = *aval;

    hsum = hex_adder(rg,opr,"1",0);

    hsum = value_adjuster(hsum,4);

    isum = dec_converter(hsum);

    aval = NULL;
    aval = validate_address(instr,hsum);

    rg->H = *aval;

    *ias += 3;

    adr = hex_converter(*ias);
    adr = to_uppercase(adr);
    rg->PC = value_adjuster(adr,4);
}
