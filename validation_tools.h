#include"reg_struct.cpp"
#ifndef _validation_tools_h
#define _validation_tools_h

void hex_validator(string,int);
int mneuonics_validator(string [],string);
string* validate_register(registers *,string [],char);
string* validate_address(string [],string);

#endif
