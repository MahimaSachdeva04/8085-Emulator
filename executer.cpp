#include"header.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

#include"Load_Store.h"
#include"Arithmatical.h"
#include"Jump.h"

void executer(ifstream *fin,string instr[65536],string str,registers *rg,tregisters *trg,string mne[30],int *ias,int *ic)
{
    string mn,opr;
    int opcode,l,i;

    l = str.length();

    i = 0;
    while(str[i] != ' ')
    {
        if(i == l)
        {
            break;
        }
        i++;
    }

    mn = str.substr(0,i);

    mn = to_uppercase(mn);

    opcode = mneuonics_validator(mne,mn);

    opr = "";
    if(i != l)
    {
        opr = str.substr((i+1),l);
    }

    if(opcode == 0)
    {
       SET(instr,opr,rg,ias);
    }
    else if(opcode == 1)
    {
        MOV(instr,opr,rg,ias);
    }
    else if(opcode == 2)
    {
        MVI(instr,opr,rg,ias);
    }
    else if(opcode == 3)
    {
        LXI(instr,opr,rg,ias,ic);
    }
    else if(opcode == 4)
    {
        LDA(instr,opr,rg,ias);
    }
    else if(opcode == 5)
    {
        STA(instr,opr,rg,ias);
    }
    else if(opcode == 6)
    {
        LHLD(instr,opr,rg,ias);
    }
    else if(opcode == 7)
    {
        SHLD(instr,opr,rg,ias);
    }
    else if(opcode == 8)
    {
        LDAX(instr,opr,rg,ias);
    }
    else if(opcode == 9)
    {
        STAX(instr,opr,rg,ias);
    }
    else if(opcode == 10)
    {
        XCHG(rg,ias);
    }
    else if(opcode == 11)
    {
        ADD(instr,opr,rg,ias);
    }
    else if(opcode == 12)
    {
        ADI(instr,opr,rg,ias);
    }
    else if(opcode == 13)
    {
        SUB(instr,opr,rg,ias);
    }
    else if(opcode == 14)
    {
        SUI(instr,opr,rg,ias);
    }
    else if(opcode == 15)
    {
        INR(instr,opr,rg,ias);
    }
    else if(opcode == 16)
    {
        DCR(instr,opr,rg,ias);
    }
    else if(opcode == 17)
    {
        INX(instr,opr,rg,ias);
    }
    else if(opcode == 18)
    {
        DCX(instr,opr,rg,ias);
    }
    else if(opcode == 19)
    {
        DAD(instr,opr,rg,ias);
    }
    else if(opcode == 20)
    {
        CMA(instr,opr,rg,ias);
    }
    else if(opcode == 21)
    {
        CMP(instr,opr,rg,ias);
    }
    else if(opcode == 22)
    {
        JMP(fin,instr,opr,rg,trg,mne,ias,ic);
    }
    else if(opcode == 23)
    {
        JC(fin,instr,opr,rg,trg,mne,ias,ic);
    }
    else if(opcode == 24)
    {
        JNC(fin,instr,opr,rg,trg,mne,ias,ic);
    }
    else if(opcode == 25)
    {
        JZ(fin,instr,opr,rg,trg,mne,ias,ic);
    }
    else if(opcode == 26)
    {
        JNZ(fin,instr,opr,rg,trg,mne,ias,ic);
    }
    else if(opcode == 27)
    {
        HLT(instr,opr,rg,ias,ic);
    }
    else
    {
        cout<<"Invalid Opcode Found!";
        exit(0);
    }
}
