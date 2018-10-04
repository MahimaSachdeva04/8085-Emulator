#include"header.h"
#include"basic_tools.h"
#include"operation_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void XCHG(registers *rg,int *ias)
{
    string adr;

    hex_validator(rg->H,2);
    hex_validator(rg->D,2);
    rg->W = rg->H;
    rg->H = rg->D;
    rg->D = rg->W;

    hex_validator(rg->L,2);
    hex_validator(rg->E,2);
    rg->Z = rg->L;
    rg->L = rg->E;
    rg->E = rg->Z;

    *ias += 1;

    adr = hex_converter(*ias);
    adr = to_uppercase(adr);
    rg->PC = value_adjuster(adr,4);
}
