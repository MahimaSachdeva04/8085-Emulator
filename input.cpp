#include"header.h"
#include"basic_tools.h"
#include"convert_revert_tools.h"

void input(string instr[65535],registers *rg,tregisters *trg,string mne[30],int *ias,int *ic)
{
    ifstream fin;
    string str,adr;

    cout<<"\n            *****No File Found*****"<<endl;
    cout<<"        Now Enter Instructions Manually"<<endl<<endl;

    while(1)
    {
        if(*ias <= 65534)
        {
            adr = hex_converter(*ias);
            adr = to_uppercase(adr);
            adr = value_adjuster(adr,4);

            cout<<adr<<"  ";
            getline(cin,str);

            instr[*ias] = to_uppercase(str);

            if(instr[*ias][0] == '\0')
            {
                cout<<"Nothing Entered!"<<endl;
                display(*rg);
                exit(0);
            }

            rg->SP = adr;

            executer(&fin,instr,instr[*ias],rg,trg,mne,ias,ic);

            *ic += 1;
        }
        else
        {
            cout<<"Memory Limit Reached!"<<endl<<endl;
            display(*rg);
            exit(0);
        }
    }
    display(*rg);
}
