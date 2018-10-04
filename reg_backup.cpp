#include"reg_struct.cpp"

void copy_data(registers *rg1,tregisters *rg2)
{
    int i;

    rg2->tA = rg1->A;
    rg2->tB = rg1->B;
    rg2->tC = rg1->C;
    rg2->tD = rg1->D;
    rg2->tE = rg1->E;
    rg2->tH = rg1->H;
    rg2->tL = rg1->L;
    rg2->tM = rg1->M;

    rg2->tSP = rg1->SP;
    rg2->tPC = rg1->PC;

    for(i=0;i<8;i++)
    {
        rg2->tF[i] = rg1->F[i];
    }
}

void revertback_data(registers *rg1,tregisters *rg2)
{
    int i;

    rg1->A = rg2->tA;
    rg1->B = rg2->tB;
    rg1->C = rg2->tC;
    rg1->D = rg2->tD;
    rg1->E = rg2->tE;
    rg1->H = rg2->tH;
    rg1->L = rg2->tL;
    rg1->M = rg2->tM;

    rg1->SP = rg2->tSP;
    rg1->PC = rg2->tPC;

    for(i=0;i<8;i++)
    {
        rg1->F[i] = rg2->tF[i];
    }
}
