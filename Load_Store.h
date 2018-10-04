#ifndef _Load_Store_h
#define _Load_Store_h

void SET(string [],string,registers *,int *);
void MOV(string [],string,registers *,int *);
void MVI(string [],string,registers *,int *);
void LDA(string [],string,registers *,int *);
void STA(string [],string,registers *,int *);
void LXI(string [],string,registers *,int *,int *);
void LDAX(string [],string,registers *,int *);
void STAX(string [],string,registers *,int *);
void LHLD(string [],string,registers *,int *);
void SHLD(string [],string,registers *,int *);
void XCHG(registers *,int *);
void HLT(string [],string,registers *,int *,int *);

#endif
