#include"header.h"
#include"basic_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void LDA(string instr[65536],string opr,registers *rg,int *ias)
{
    string *aval,adr;

    aval = NULL;
    aval = validate_address(instr,opr);

    rg->A = *aval;

    *ias += 3;

    adr = hex_converter(*ias);
    adr = to_uppercase(adr);
    rg->PC = value_adjuster(adr,4);
}

