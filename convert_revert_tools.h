#include"reg_struct.cpp"
#ifndef _convert_revert_tools_h
#define _convert_revert_tools_h


void copy_data(registers *,tregisters *);
void revertback_data(registers *,tregisters *);

string value_adjuster(string str,int n);

string to_lowercase(string);
string to_uppercase(string);

string bin_converter(string);
string bin_reverter(string);

string hex_converter(int);
int dec_converter(string);


#endif
