#include"reg_struct.cpp"
#ifndef _basic_tools_h
#define _basic_tools_h

void resetter(registers *);
void initializer(registers *);

void mneumonics(string *);

void input(string [],registers *,tregisters *,string [],int *,int *);

void debug(char **,string [],registers *,tregisters *,string [],int *,int *);

void executer(ifstream *,string [],string,registers *,tregisters *,string [],int *,int *);

void display(registers);

#endif
