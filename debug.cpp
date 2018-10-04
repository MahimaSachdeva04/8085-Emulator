#include"header.h"
#include"basic_tools.h"
#include"validation_tools.h"
#include"convert_revert_tools.h"

void debug(char **argv1,string instr[65535],registers *rg,tregisters *trg,string mne[30],int *ias,int *ic)
{
    ifstream fin;
    string *rval,*aval;
    string adr,str,tstr,sln;
    int l,tc,iln;

    fin.open("help.txt");
    while(getline(fin,str))
    {
        cout<<str<<endl;
    }
    fin.close();
    cout<<endl;

    while(1)
    {
        cout<<"-->";
        getline(cin,str);

        str = to_uppercase(str);

        l = str.length();
        if(l == 1)
        {
            if(str[0] == 'R')
            {
                fin.open(*argv1);//fin.open("sample.txt");//

                if(*ias <= 65534)
                {
                    tc = 0;
                    while(tc < *ic)
                    {
                        getline(fin,tstr);
                        tc++;
                    }

                    while(1)
                    {
                        getline(fin,tstr);
                        instr[*ias] = to_uppercase(tstr);

                        adr = hex_converter(*ias);
                        adr = to_uppercase(adr);
                        rg->SP = value_adjuster(adr,4);

                        if((*ias == 655532) || (*ias == 655533) || (*ias == 655534))
                        {
                            copy_data(rg,trg);
                        }

                        executer(&fin,instr,instr[*ias],rg,trg,mne,ias,ic);

                        if(*ias > 65534)
                        {
                            revertback_data(rg,trg);
                            cout<<"Memory Limit reached!"<<endl;
                            display(*rg);
                            exit(0);
                        }

                        *ic += 1;
                    }
                }
                else
                {
                    cout<<"Memory Limit reached!";
                    display(*rg);
                    exit(0);
                }
                display(*rg);

                fin.close();
            }
            else if(str[0] == 'S')
            {
                fin.open(*argv1);//fin.open("sample.txt");

                if(*ias <= 65534)
                {
                    tc = 0;
                    while(tc < *ic)
                    {
                        getline(fin,tstr);
                        tc++;
                    }

                    getline(fin,tstr);
                    instr[*ias] = to_uppercase(tstr);

                    adr = hex_converter(*ias);
                    adr = to_uppercase(adr);
                    rg->SP = value_adjuster(adr,4);

                    if((*ias == 655532) || (*ias == 655533) || (*ias == 655534))
                    {
                        copy_data(rg,trg);
                    }

                    executer(&fin,instr,instr[*ias],rg,trg,mne,ias,ic);

                    if(*ias > 65534)
                    {
                        revertback_data(rg,trg);
                        cout<<"Memory Limit reached!"<<endl;
                        display(*rg);
                        exit(0);
                    }

                    *ic += 1;
                }
                else
                {
                    cout<<"Memory Limit Reached!";
                    display(*rg);
                    exit(0);
                }
                display(*rg);

                fin.close();
            }
            else if(str[0] == 'Q')
            {
                exit(0);
            }
            else if(str[0] == 'H')
            {
                fin.open("help.txt");
                while( getline(fin,str) )
                {
                    cout<<str<<endl;
                }
                fin.close();
                cout<<endl;
            }
            else
            {
                cout<<"Invalid Choice entered!"<<endl<<endl;
                cout<<"To run Debugger according to your choice, Please only enter the initials"<<endl;
                cout<<"For more information--Press h"<<endl<<endl;
            }
        }
        else if(l == 3)
        {
            if((str[0] == 'P') && (str[1] == ' '))
            {
                rval = NULL;
                rval = validate_register(rg,instr,str[2]);

                if(rval != NULL)
                {
                    cout <<str[2]<<" = "<<(*rval)<<endl;
                }
            }
            else
            {
                cout<<"Invalid Choice entered!"<<endl<<endl;
                cout<<"To run Debugger according to your choice, Please only enter the initials"<<endl;
                cout<<"For more information--Press h"<<endl<<endl;
            }
        }
        else if(l == 6)
        {
            if((str[0] == 'P') && (str[1] == ' '))
            {
                aval = NULL;
                tstr = str.substr(2,l);
                tstr = to_uppercase(tstr);
                aval = validate_address(instr,tstr);

                if(aval != NULL)
                {
                    cout<<tstr<<" = "<<*aval<<endl;
                }
            }
            else if(str[0] == 'B')
            {
                sln = str.substr(2,l);
                sln = to_uppercase(sln);
                hex_validator(sln,4);
                iln = dec_converter(sln);

                fin.open(*argv1);//fin.open("sample.txt");
                if(*ias <= 65534)
                {
                    tc = 0;
                    while(tc < *ic)
                    {
                        getline(fin,tstr);
                        tc++;
                    }
                }

                iln += *ic;

                while(tc < iln)
                {
                    getline(fin,tstr);
                    instr[*ias] = to_uppercase(tstr);

                    adr = hex_converter(*ias);
                    adr = to_uppercase(adr);
                    rg->SP = value_adjuster(adr,4);


                    if((*ias == 655532) || (*ias == 655533) || (*ias == 655534))
                    {
                        copy_data(rg,trg);
                    }

                    executer(&fin,instr,instr[*ias],rg,trg,mne,ias,ic);

                    if(*ias > 65534)
                    {
                        revertback_data(rg,trg);
                        display(*rg);
                        cout<<"Memory Limit reached!"<<endl;
                        exit(0);
                    }

                    *ic += 1;

                    tc += 1;
                }
                display(*rg);
                fin.close();
            }
            else
            {
                cout<<"Invalid choice entered!"<<endl<<endl;
                cout<<"To run Debugger according to your choice, Please only enter the initials"<<endl;
                cout<<"For more information--Press h"<<endl<<endl;
            }
        }
        else
        {
            cout<<"Invalid choice entered"<<endl;
            cout<<"To run Debugger according to your choice, Please only enter the initials"<<endl;
            cout<<"For more information--Press h"<<endl<<endl;
        }
    }
}
