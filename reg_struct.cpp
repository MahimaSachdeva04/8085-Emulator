#include"header.h"
#ifndef _reg_struct_h
#define _reg_struct_h

typedef struct registers
{
    string A,B,C,D,E,H,L,M;
    string W,Z;
    string SP,PC;
    string F[8];
}registers;

typedef struct tregisters
{
    string tA,tB,tC,tD,tE,tH,tL,tM;
    string tW,tZ;
    string tSP,tPC;
    string tF[8];
}tregisters;

#endif
