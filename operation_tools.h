#include"reg_struct.cpp"
#ifndef _operation_tools_h
#define _operation_tools_h

void bin_adder(char,char,char *,char *);
string hex_adder(registers *,string str1,string str2,int);
string hex_subtracter(registers *,string str1,string str2,int);
string IIs_compliment(string);

void flag_setter(string,char,char,char,registers *);

#endif

