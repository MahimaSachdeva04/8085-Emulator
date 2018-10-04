#include"header.h"
#include"reg_struct.cpp"

void display(registers rg)
{
    rg.M = rg.H;
    rg.M += rg.L;

    cout<<"General Purpose Registers:-"<<endl;
    cout<<"A="<<rg.A<<endl;
    cout<<"B="<<rg.B<<endl;
    cout<<"C="<<rg.C<<endl;
    cout<<"D="<<rg.D<<endl;
    cout<<"E="<<rg.E<<endl;
    cout<<"H="<<rg.H<<endl;
    cout<<"L="<<rg.L<<endl;
    cout<<"M="<<rg.M<<endl<<endl;

    cout<<"Special Purpose Registers:-"<<endl;
    cout<<"SP="<<rg.SP<<endl;
    cout<<"PC="<<rg.PC<<endl<<endl;

    cout<<"Flags:-"<<endl;
    cout<<"Sign Flag="<<rg.F[0]<<endl;
    cout<<"Zero Flag="<<rg.F[1]<<endl;
    cout<<"Auxillary Carry Flag="<<rg.F[3]<<endl;
    cout<<"Parity Flag="<<rg.F[5]<<endl;
    cout<<"Carry Flag="<<rg.F[7]<<endl<<endl;
}
