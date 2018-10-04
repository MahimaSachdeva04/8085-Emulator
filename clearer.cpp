#include"reg_struct.cpp"

void resetter(registers *rg)
{
    int i;

    rg->A = "00";
    rg->B = "00";
    rg->C = "00";
    rg->D = "00";
    rg->E = "00";
    rg->H = "00";
    rg->L = "00";

    rg->M = "0000";

    rg->W = "00";
    rg->Z = "00";

    for(i=0;i<8;i++)
    {
        rg->F[i] = "0";
    }
}

void initializer(registers *rg)
{
    resetter(rg);

    rg->SP = "0000";
    rg->PC = "0000";
}
