//**********************************************************************************


//        HEADER FILES USED IN PROGRAM


//**********************************************************************************


#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<iomanip.h>
#include<process.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>


//*******************************************************************************


char Date[20];
//******************************************************************************
//          FUNCTION TO SET SYSTEM DATE
//******************************************************************************


void time()
{  time_t t;
   time(&t);
   ctime(&t);
   printf("%s\n",ctime(&t));
}


//******************************************************************************
//         CLASS USED IN PROJECT
//******************************************************************************
class doctor
{ private:
        char docno[6];
        char docname[20];
        char specialisation[20];
  public:
        void create_doctor()
        {cout<<"\nNEW DOCTOR ENTRY \n";
        cout<<"\nEnter The Doctor No:";
        cin>>docno;
        cout<<"\n\nEnter the name of the doctor";
        gets(docname);
        cout<<"\n\nSpecialisation :";
        gets(specialisation);
        cout<<"\n\n\nDoctor Record Created";
        }
        void show_doctor()
        {cout<<"\nDoctor no:"<<docno;
        cout<<"\nDoctor name:";
        puts(docname);
        cout<<"\nSpecialisation:";
        puts(specialisation);
        }
        void modify_doctor()
        {cout<<"\nDoctor no:"<<docno;
        cout<<"\nModify Doctor Name:";
        gets(docname);
        cout<<"\nModify Specialisation of doctor:";
        gets(specialisation);
        }
        char *retdocno()
        {return docno;
        }
        void report()
        {cout<<docno<<setw(30)<<docname<<setw(30)<<specialisation<<endl;
        }
 getch();
};  //CLASS ENDS HERE


class patient
{ private:
        char admno[6];
        char name[20];
        char doctor_consulted[20];
        int age;
        char date[20];
  public:
     void create_patient()
        {cleardevice();
        cout<<"\nNEW PATIENT ENTRY \n";
        cout<<"\n\nEnter The Admit No:";
        cin>>admno;
        cout<<"\n\nEnter the name of the patient :";
        gets(name);
        cout<<"\n\nEnter the doctor consulted :";
        gets(doctor_consulted);
        cout<<"\n\nEnter the age of the patient:";
        cin>>age;
        cout<<"\n\n\nPatient Record Created\n\n";
        }
    void show_patient()
        {cout<<"\nAdmit no:"<<admno;
        cout<<"\nPatient name:";
        puts(name);
        cout<<"\nDoctor Consulted:";
        puts(doctor_consulted);
        cout<<"Age:"<<age;
        }
    void modify_patient()
        {cout<<"\nAdmit no:"<<admno;
        cout<<"\nModify Patient Name:";
        gets(name);
        cout<<"\nModify doctor consulted:";
        gets(doctor_consulted);
        cout<<"\nEnter new registration date:";
        gets(date);
        }
    char *retadmno()
        {return admno;
        }
void op()
{cout<<"\n\n\tName:"<<name;
 cout<<"\t\tRegister no:"<<admno;
 cout<<"\n\n\tDate & Time of registration:";time();
 cout<<"\n\t\tPlease bring this card during\n\t\t\tevery hospital visit";
 rectangle(4,4,630,450);
}
void bill()
{gotoxy(1,15);
cout<<"\n\tMr./Mrs. :"<<name;
cout<<"\t\tPatient no:"<<admno; randomize();
cout<<"\t Doctor:"<<doctor_consulted;
cout<<"\n\tAge :"<<age<<"\tBill no: ABC"<<random(5000);
cout<<"\tBill Date and Time:";time();
rectangle(4,300,500,500);
rectangle(500,400,630,450);
line(4,320,500,320);
line(500,380,630,380);
line(50,300,50,450);
line(200,300,200,450);
line(300,300,300,450);
line(390,300,390,450);
}
void report()
{cout<<admno<<"\t\t"<<name<<"\t\t"<<age<<"\t\t"<<doctor_consulted<<endl;
}
void dis()
{cout<<"\nDate of admission:"<<date<<"\tDate & time of discharge: ";time();
cout<<"\nName of patient:"<<name;
getch();
}
};     //CLASS ENDS HERE




//**************************************************************************************
//   GLOBAL DECLARATION FOR STREAM OBJECT, OBJECT, GRAPHICS
//**************************************************************************************


fstream fp, fpl;
doctor doc;
patient st;
int gdriver = DETECT, gmode, errorcode;


//*************************************************************************************
//   FUNCTION TO GENERATE OP CARD
//*************************************************************************************


void issue_opcard()
{
setcolor(15);
cleardevice();
int flag=0;
char n[20];
gotoxy(1,1);
cout<<"\n\tEnter The Admit No For Op Card Generation :";
cin>>n;
cleardevice();
setbkcolor(3);
settextstyle(1,0,4);
outtextxy(90,15,"PT CP Memorial Hospital");
gotoxy(12,5);
cout<<"********************************************************";
cout<<"\n";
cout<<"\n\t\t(owned by Pullickal Medical Foundation)\n\tMG Road ,Kochi-16,ph:0485443563”\n\t\tE-mail:info@medical.org";
cout<<"Service Taxno:ABB7800ID";
settextstyle(4,0,4);
outtextxy(80,160,"Excellence In Health Since 1982");
settextstyle(4,0,4);
outtextxy(190,200,"  OP CARD");
gotoxy(20,20);
fp.open("patient.dat",ios::in);
while(fp.read((char *)&st,sizeof(patient)))
{ if( (strcmpi (st.retadmno(), n) ==0))
   { st.op();
     flag=1;
   }
}
if(flag==0)
cout<<"\n\nPatient does not exist";
fp.close();
getch();
return;
}
//***********************************************************************************
//        FUNCTION TO WRITE INTO THE FILES
//***********************************************************************************


void write_doctor()
{char ch;
fp.open("doctor.dat",ios::out|ios::app);
do
  {  cleardevice();
     gotoxy(1,1);
     doc.create_doctor();
     fp.write((char*)&doc,sizeof(doctor));
     cout<<"\n\tDo you want to add more record [Y/N] ? ";
     cin>>ch;
  }  while(ch=='y'||ch=='Y');
 fp.close();
 getch();
}
void write_patient()
{char ch;
fp.open("patient.dat",ios::out|ios::app);
do
{
  gotoxy(1,1);
  st.create_patient();
  fp.write((char*)&st,sizeof(patient));
  cout<<"\n\tDo you want to add more record [Y/N] ? ";
  cin>>ch;
  }  while(ch=='y'||ch=='Y');
 fp.close();
 getch();
}


//***********************************************************************************
//        FUNCTION TO READ SPECIFIC RECORD FROM FILE
//***********************************************************************************


void display_spd(char n[])
{ cleardevice();
  gotoxy(1,1);
  cout<<"\nDOCTOR DETAILS\n";
  int flag=0;
  fp.open("doctor.dat",ios::in) ;
  while(fp.read( (char*)&doc,sizeof(doctor)) )
{if(strcmpi(doc.retdocno(),n)==0)
            { doc.show_doctor();
                flag=1;
            }
}
fp.close();
if(flag==0)
    cout<<"\n\n\tDoctor does not exist!";
getch();
}


void display_sps(char n[])
{cleardevice();
gotoxy(1,1);
cout<<"\n\tPATIENT DETAILS\n";
int flag=0;
fp.open("patient.dat",ios::in) ;
while(fp.read((char*)&st,sizeof(patient)))
{if(strcmpi(st.retadmno(),n)==0)
             { st.show_patient();
                  flag=1;
             }
}
fp.close();
if(flag==0)
cout<<"\n\nPatient does not exist!";
getch();
}


//**********************************************************************************
//        FUNCTION TO MODIFY RECORD OR FILE
//**********************************************************************************


void modify_doctor()
{gotoxy(1,1);
char  n[6];
int found=1;
cleardevice();
cout<<"\n\n\tMODIFY DOCTOR RECORD";
cout<<"\n\n\t Enter the doc no. of Doctor:";
cin>>n;
fp.open("doctor.dat",ios::in|ios::out);
while(fp.read((char*)&doc,sizeof(doctor))&&found==0)
  { if(strcmpi(doc.retdocno(),n)==0)
       {doc.show_doctor();
        cout<<"\nEnter the new details of doctor"<<endl;
        doc.modify_doctor();
        int pos=-1*sizeof(doc);
        fp.seekp(pos,ios::cur);
        fp.write((char*)&doc,sizeof(doctor));
        cout<<"\n\nRecord Updated";
        found=1;
       }
  }
fp.close();
if(found==0)
cout<<"\n\nRecord Not Found!";
getch();
}


void modify_patient()
{gotoxy(1,1);
char  n[6];
int found=1;
cleardevice();
cout<<"\n\n\tMODIFY PATIENT RECORD";
cout<<"\n\n\t Enter the admin no. of patient:";
cin>>n;
fp.open("patient.dat",ios::in|ios::out);
while(fp.read((char*)&st,sizeof(patient))&&found==0)
  { if(strcmpi(st.retadmno(),n)==0)
       {st.show_patient();
        cout<<"\nEnter the new details of patient"<<endl;
        st.modify_patient();
        int pos=-1*sizeof(st);
        fp.seekp(pos,ios::cur);
        fp.write((char*)&st,sizeof(patient));
        cout<<"\n\nRecord Updated";
        found=1;
       }
  }
fp.close();
if(found==0)
cout<<"\n\nRecord Not Found!";
getch();
}


//***********************************************************************************
//        FUNCTION TO DELETE RECORD OF FILE
//***********************************************************************************


void delete_patient()
{char n[6];
int flag=0;
cleardevice();
gotoxy(1,1);
cout<<"\n\n\nDELETE PATIENT  ";
cout<<"\n\nEnter the admission no. of the patient to be deleted:";
cin>>n;
fp.open("patient.dat",ios::in|ios::out);
fstream fp2;
fp2.open("temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&st,sizeof(patient)))
{if(strcmp(st.retadmno(),n) != 0)
    fp2.write((char*)&st,sizeof(patient));
 else
    flag=1;
}
fp2.close();
fp.close();
remove("patient.dat");
rename("temp.dat","patient.dat");
if(flag==1)
  cout<<"\n\n\tRecord deleted";
else
  cout<<"\n\n\tRecord not found";
getch();
}


void delete_doctor()
{
char n[6];
cleardevice();
gotoxy(1,1);
cout<<"\n\n\n\tDELETE DOCTOR  ";
cout<<"\n\n\tEnter the doctor no. of the doctor to be deleted:";
cin>>n;
fp.open("doctor.dat",ios::in|ios::out);
fstream fp2;
fp2.open("temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&doc,sizeof(doctor)))
{if(strcmp(doc.retdocno(),n) != 0)
   { fp2.write((char*)&doc,sizeof(doctor)); }
}
fp2.close();
fp.close();
remove("doctor.dat");
rename("temp.dat","doctor.dat");
cout<<"\n\n\tRecord deleted";
getch();
}


//*******************************************************************************
//        FUNCTION TO DISPLAY ALL DOCTOR LIST
//******************************************************************************


void display_allb()
{  cleardevice();
   fp.open("doctor.dat",ios::in);
  if(!fp)
     {cout<<"\n\tERROR!!!FILE COULD NOT BE OPENED";
      getch();
      return;
     }
gotoxy(1,1);
cout<<"\n\n\t\t\tDOCTOR LIST\n\n";
cout<<"\t---------------------------------------------------------\n";
cout<<"\tDoctor no."<<setw(20)<<"Doctor Name:"<<setw(25)<<"Specialisation\n";
cout<<"\t---------------------------------------------------------\n";
while(fp.read((char*)&doc,sizeof(doctor)))
{doc.report();
}
fp.close();
getch();
}
//**********************************************************************************
//        FUNCTION TO DISPLAY ALL PATIENT LIST
//**********************************************************************************


void display_alls()
{  cleardevice();
   fp.open("patient.dat",ios::in);
  if(!fp)
     {cout<<"\tERROR!!!FILE COULD NOT BE OPENED";
      getch();
      return;
     }
gotoxy(1,1);
cout<<"\n\n\t\tPATIENT LIST\n\n";
cout<<"\t--------------------------------------------------------------\n";
cout<<"Admit No."<<setw(20)<<"Name and Age:"<<setw(25)<<"Doctor Consulted\n";
cout<<"\t--------------------------------------------------------------\n";
while(fp.read((char*)&st,sizeof(patient)))
{st.report();
}
fp.close();
getch();
}
//**********************************************************************************
//        FUNCTION TO GENERATE THE BILL
//**********************************************************************************
void generate_bill()
{cleardevice();
int flag=0,net=0;
char n[20];
float med_charge=0, discount=0,claim=0,gross=0,temp=0,other=0;
const int consult_fee=100;
gotoxy(1,1);
cout<<"\n\n\tEnter the patient's admit no :";
gets(n);
cout<<"\n\tEnter the medical charges :";
cin>>med_charge;
cout<<"\n\tEnter discount if any(%):";
cin>>discount;
cout<<"\n\t insurance/corporate claim amount:";
cin>>claim;
cout<<"\n\tEnter LAB charges if any:";
cin>>other;
gross=(med_charge+consult_fee+other);
temp=(((discount*gross)/100)+claim);
net=gross-temp;


cleardevice();
setbkcolor(9);
settextstyle(4,0,4);
outtextxy(90,15,"PT CP Memorial Hospital");
gotoxy(12,5);
cout<<"************************************************";
cout<<"\n";
cout<<"\n\t(owned by Pullickal Medical Foundation)\n\t\tMG Road ,Kochi-16,ph:0485443563\n\t\tE-mail:info@medical.org";
cout<<"Service Taxno:ABB7800ID";
settextstyle(4,0,4);
outtextxy(80,160,"Excellence In Health Since 1982");
settextstyle(1,0,2);
outtextxy(200,200," CASH BILL");
gotoxy(32,15);
fp.open("patient.dat",ios::in);
while(fp.read((char *)&st,sizeof(patient)))
{ if(strcmpi(st.retadmno(),n)==0)
 {
  cout<<"\n\n\n\n\nsl.no\t"<<setw(5)<<"Category"<<setw(20)<<"Amount"<<setw(10)<<"Gross"<<setw(15)<<"Reduction";
  cout<<"\n 1.\t"<<setw(5)<<"consul_ fee     "<<setw(10)<<"100";
  cout<<"\n 2.\t"<<setw(5)<<"Pharmacy Charges"<<setw(10)<<med_charge;
  cout<<"\n 3.\t"<<setw(5)<<"Discount(%)     "<<setw(10)<<discount;
  cout<<"\n 4.\t"<<setw(5)<<"Insurance/Claim   "<<setw(10)<<claim<<setw(10)<<gross<<setw(15)<<temp;
  cout<<"\n 5.\t"<<setw(5)<<"LAB charges     "<<setw(10)<<other<<setw(45)<<"Net amount\n"<<setw(70)<<"\t"<<net;
  st.bill();
  flag=1;
 }


}
rectangle(4,4,630,500);
if (flag==0)
outtextxy(50,350,"Patient does not exist!");
fp.close();
getch();
}




//***********************************************************************************
//        INTRODUCTION FUNCTION
//***********************************************************************************


void intro()
{
cleardevice();
setbkcolor(4);
for(int i=0;i<16;i++)
{ setcolor(i);
  delay(250);
  settextstyle(3,0,0);
  outtextxy(35,35,"HOSPITAL MANAGEMENT");
  outtextxy(35,100,"SYSTEM");
  settextstyle(2,0,6);
  outtextxy(20,300,"MADE BY:SANDRA SKARIA AND ELIZABETH ELDHO");
  outtextxy(20,400,"ST.PHILOMENA'S PUBLIC SCHOOL");
  setcolor(1);
}
getch();
cleardevice();
}


//**********************************************************************************
//        ADMINISTRATOR MENU FUNCTION
//**********************************************************************************


void admin_menu()
{
cleardevice();
int ch2,ch3;
gotoxy(1,1);
setbkcolor(9);
cout<<"\n\n\n\t ADMINISTRATOR MENU";
cout<<"\n\n\t1.Create Patient Record";
cout<<"\n\n\t2.Patient Record Operation";
cout<<"\n\n\t3.Create Doctor Record";
cout<<"\n\n\t4.Doctor Record Operation";
cout<<"\n\n\t5.back to main menu";
cout<<"\n\n\tPlease enter your choice(1-5)";
cin>>ch2;
switch(ch2)
{case 1:cleardevice();
        write_patient();
        break;
case 2:cleardevice();
        gotoxy(1,1);
        setbkcolor(12);
        cout<<"\n\n\tPATIENT RECORD OPERATION";
cout<<"\n\n\t1.Display All Patient Record";
cout<<"\n\n\t2.Display Specific Patient Record";
cout<<"\n\n\t3.Modify Patient Record";
cout<<"\n\n\t4.Delete Patient Record";
cout<<"\n\n\t please enter your choice(1-4)";
cin>>ch3;
switch(ch3)
{case 1:display_alls();
        break;
case 2:char num[6];
        cleardevice();
        gotoxy(1,1);
        cout<<"\n\n\tplease enter the admit no.:";
        cin>>num;
        display_sps(num);
        break;
case 3:modify_patient();
        break;
case 4:delete_patient();
        break;
default: cout<<"invalid choice";
        return;
}
case 3:cleardevice();
        write_doctor();
        break;
case 4:cleardevice();
        gotoxy(1,1);
        setbkcolor(12);
        cout<<"\n\n\tDOCTOR RECORD OPERATION";
cout<<"\n\n\t1.Display All Doctor Record";
cout<<"\n\n\t2.Display Specific Doctor Record";
cout<<"\n\n\t3.Modify Doctor Record";
cout<<"\n\n\t4.Delete Doctor Record";
cout<<"\n\n\t please enter your choice(1-4)";
cin>>ch3;
switch(ch3)
{case 1:display_allb();
        break;
case 2:char num[6];
        cleardevice();
        gotoxy(1,1);
        cout<<"\n\n\tplease enter the doctor no.:";
        cin>>num;
        display_spd(num);
        break;
case 3:modify_doctor();
        break;
case 4:delete_doctor();
        break;
default: cout<<"\n\tinvalid choice";
        return;
}
case 5:return;
default:cout<<"\a";
}
admin_menu();
getch();
}
//********************************************************************************
//        FUNCTION OF DISCHARGE SUMMARY
//********************************************************************************


/* voiddischarge_display()
{ fstream fin;
  char summary;
  fin.open("summary.txt",ios::in);
  while( !fin.eof() )
      { fin.get(summary)
        cout<<summary;
      }
} */
//***************************************************************************


void discharge_summary()
{ gotoxy(1,1);
  char ch[6], summary;
  int i, op, flag=0;
  fstream fin;
  { cleardevice();
     setbkcolor(5);
cout<<"\n\tDischarge Summary";
cout<<"\n\tEnter the admit no. of the patient";
cin>>ch;


fp.open("patient.dat",ios::in);
while(fp.read((char*)&st,sizeof(patient)))
{if(strcmpi(st.retadmno(),ch)==0)
      {flag=1;
      }
}
fp.close();
if(flag==0)
    { cout<<"Patient does not exist";
      getch();
      return;
    }
fin.open("summary.txt",ios::out);
cout<<"\tType the discharge summary under specific heads\n";
cout<<"\tFINAL DIAGNOSIS:(enter '~' for next head)\n";
fin<<"\n\tFINAL DIAGNOSIS:\n";
for(i=0;i<500;i++)
{  cout<<"\t";
   cin.get(summary);
   if (summary=='~')
       break;
   fin.put(summary);
}
cout<<"\tHISTORY OF ILLNESS:(enter '~' for next head)\n";
fin<<"\n\tHISTORY OF PRESENT ILLNESS:\n\n";
for(i=0;i<500;i++)
{  cout<<"\t";
   cin.get(summary);
   if (summary=='~')
       break;
   fin.put(summary);
}
cout<<"\tPHYSICAL EXAMINATION:(enter '~' for next head)\n";
fin<<"\n\tPHYSICAL EXAMINATION:\n";
for(int i=0;i<500;i++)
{  cout<<"\t";
   cin.get(summary);
   if (summary=='~')
       break;
   fin.put(summary);
}
cout<<"\tHOSPITAL COURSE:(enter '~' for next head)\n";
fin<<"\n\tHOSPITAL COURSE:\n";
for(i=0;i<500;i++)
{  cout<<"\t";
   cin.get(summary);
   if (summary=='~')
       break;
   fin.put(summary);
}
cout<<"\tDISCHARGE DISPOSITION:(enter '~' for next head)\n";
fin<<"\n\tDISCHARGE DISPOSITION:\n";
for(i=0;i<500;i++)
{  cout<<"\t";
   cin.get(summary);
   if (summary=='~')
       break;
   fin.put(summary);
}
cout<<"\tDIET:(enter '~' for next head)\n";
fin<<"\n\tDIET:\n";
for(i=0;i<500;i++)
{  cout<<"\t";
   cin.get(summary);
   if (summary=='~')
       break;
   fin.put(summary);
}
cout<<"\tFOLLOW UPS:(enter '~' for next head)\n";
fin<<"\n\tFOLLOW UPS:\n";
for(i=0;i<500;i++)
{  cout<<"\t";
   cin.get(summary);
   if (summary=='~')
       break;
   fin.put(summary);
}
cout<<"\t1.submit\n\t2.abort\n\tYour option is(1-2):";
cin>>op;
fin.close();
}
if(op==1)
{cleardevice();
gotoxy(1,1);
setcolor(0);
setbkcolor(2);


fp.open("patient.dat",ios::in);
while(fp.read((char*)&st,sizeof(patient)))
{if(strcmpi(st.retadmno(),ch)==0)
    {st.dis();
      flag=1;
    }
}
fp.close();
if(flag==0)
    cout<<"\n\tPatient does not exist";
fin.open("summary.txt",ios::in);
while( !fin.eof() )
    { fin.get(summary);
      cout<<summary;
    }
}
else
    return;
getch();
}
//**********************************************************************************
//        MAIN FUNCTION OF THE PROGRAM
//**********************************************************************************


void main()
{ detectgraph(&gdriver,&gmode);
  initgraph(&gdriver,&gmode,"c:\\TURBOC3\\BGI");
  int ch;
  intro();
  do
   {cleardevice();
    setbkcolor(3);
    gotoxy(1,1);
    cout<<"\n\n\n\tMAIN MENU";
    cout<<"\n\n\t01.ISSUE OP CARD";
    cout<<"\n\n\t02.GENERATE BILL";
    cout<<"\n\n\t03.RECORDS";
    cout<<"\n\n\t04.DISCHARGE SUMMARY";
    cout<<"\n\n\t05.EXIT";
    cout<<"\n\n\tPlease Select Your Option(1-4) :";
    cin>>ch;
switch(ch)
{case 1:cleardevice();
       issue_opcard();
        break;
case 2:cleardevice();
       generate_bill();
       break;
case 3:cleardevice();
       admin_menu();
       break;
case 4:cleardevice();
       discharge_summary();
       break;
case 5:exit(0);
default:cout<<"\a";
  }
} while(ch != 5);
getch();
}


//***********************************************************************************
//        END OF PROJECT
//***********************************************************************************












