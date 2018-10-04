#include"header.h"
#include"basic_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void LXI(string instr[65536],string opr,registers *rg,int *ias,int *ic)
{
    string *drval,adr,*daval;
    int l,temp,i,tic;

    l=opr.length();

    if(l == 6)
    {
        if(opr[1] == ',')
        {
            drval = NULL;
            drval = validate_register(rg,instr,opr[0]);

            if((opr[0] == 'B') || (opr[0] == 'D') || (opr[0] == 'H'))
            {
                adr = opr.substr(2,l);

                daval = NULL;
                daval = validate_address(instr,adr);

                if(opr[0] == 'B')
                {
                    rg->B = opr.substr(2,2);
                    rg->C = opr.substr(4,6);
                }
                else if(opr[0] == 'D')
                {
                    rg->D = opr.substr(2,2);
                    rg->E = opr.substr(4,6);
                }
                else
                {
                    rg->H = opr.substr(2,2);
                    rg->L = opr.substr(4,6);
                }


                *ias += 3;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
            else
            {
                cout<<"Valid register for this operation not found!"<<endl<<endl;
                display(*rg);
                exit(0);
            }
        }
        else
        {
            cout<<"Invalid operand found!"<<endl<<endl;
            display(*rg);
            exit(0);
        }
    }
    else if(l == 7)
    {
        if(opr[2] == ',')
        {
            if((opr[0] == 'S') && (opr[1] == 'P'))
            {
                adr = opr.substr(3,l);

                hex_validator(adr,4);

                rg->SP = adr;

                temp = dec_converter(adr);

                if(temp <= *ias)
                {
                    tic = 0 ;
                    for(i=0;i<temp;i++)
                    {
                        l = instr[i].length();

                        if(l > 2)
                        {
                            tic++;
                        }
                    }
                    *ic = tic;
                }

                *ias = temp+3;

                adr = hex_converter(*ias);
                adr = to_uppercase(adr);
                rg->PC = value_adjuster(adr,4);
            }
            else if((opr[0] == 'P') && (opr[1]=='C'))
            {
                adr = opr.substr(3,l);

                hex_validator(adr,4);

                rg->PC = adr;
                rg->SP = adr;
                temp = dec_converter(adr);

                if(temp <= *ias)
                {
                    tic = 0;
                    for(i=0;i<temp;i++)
                    {
                        l = instr[i].length();

                        if(l > 2)
                        {
                            tic++;
                        }
                    }
                    *ic = tic;
                }

                *ias = temp;
            }
            else
            {
                cout<<"Invalid operand found!"<<endl<<endl;
                display(*rg);
                exit(0);
            }
        }
        else
        {
            cout<<"Invalid operand found!"<<endl<<endl;
            display(*rg);
            exit(0);
        }
    }
    else
    {
        cout<<"Invalid operand found!"<<endl<<endl;
        display(*rg);
        exit(0);
    }
}
