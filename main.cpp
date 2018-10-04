#include"header.h"
#include"reg_struct.cpp"
#include"basic_tools.h"

int main(int argc,char *argv[])
{
    registers rg;
    tregisters trg;
    string mne[30]="00",instr[65536]="00";
    int ic=0,ias=0;

    initializer(&rg);

    mneumonics(mne);

    if(argc == 2)
    {
        debug(&argv[1],instr,&rg,&trg,mne,&ias,&ic);
    }
    else
    {
        input(instr,&rg,&trg,mne,&ias,&ic);
    }

    return 0;
}
