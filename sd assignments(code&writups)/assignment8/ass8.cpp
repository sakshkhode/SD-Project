//NAME:SAKSHI KHODE  ROLL NO:223031  BATCH:C2

#include<iostream>
#include<fstream>
using namespace std;
class Student
{
 int rollno;
 char name[20];
 char Class;
 public:
 void getdata();
 void displayall();
 int getno() {return rollno;}
 int getClass() {return Class;}
}s;

void Student::getdata()
{
    cout<<"Enter Name     : ";
 cin>>name;
cin.getline(name,20);
 cout<<"Enter Roll No. : ";
 cin>>rollno;

// gets(name);
 cout<<"Enter Class    : ";
 cin>>Class;
}

void Student::displayall()
{
 ifstream fin("stud.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  cout<<"Name:"<<name<<endl;
  cout<<"Roll no"<<rollno<<endl;
  cout<<"Class:"<<Class<<endl;
 }
 fin.close();
// int x=gcount();
// cout<<"\n"<<x<<" Bytes read from file...\n";
}

//For adding the data into the file.
void add()
{

 char ch='y';
 ofstream fout("stud.dat",ios::out|ios::app|ios::binary);
 while(ch=='y'||ch=='Y')
 {
  s.getdata();
  fout.write((char*)&s,sizeof(s));
  cout<<"\nDo you want to add more : ";
  cin>>ch;
 }
 cout<<"\nData Appended and Transferred to file...\n";
 fout.close();
}



void Delete()
{
 int rno;
 char found='n';
 fstream fio("stud.dat",ios::in|ios::out|ios::binary|ios::app);
 ofstream fout("temp.dat",ios::out|ios::binary|ios::app);
 ofstream out("trash.dat",ios::out|ios::binary|ios::app);

 cout<<"\nEnter the Roll No. whose record is to be deleted: ";
 cin>>rno;

 while(fio.read((char*)&s,sizeof(s)))
 {
  if(s.getno()==rno)
  {
   out.write((char*)&s,sizeof(s));
   found='y';
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 if(found=='n') cout<<"\nThe Roll No."<<rno<<" is not in the file...\n";
 fio.close();
 fout.close();
 remove("stud.dat");
 rename("temp.dat","stud.dat");
}



int main()
{
 int n,rno,i;
 fstream fio("stud.dat",ios::in|ios::out|ios::binary);
 int ch;
 char choice='y';

 while(choice=='y')
 {
     cout<<"\n\t...MENU OF PROGRAM...\n";
 cout<<"\t1. Add the record...\n";
 cout<<"\t2. Display all records...\n";
 cout<<"\t3. Delete the Record...\n";

 cin>>ch;
   switch(ch)
   {
  case 1: add(); break;
  case 2: s.displayall(); break;
  case 3: Delete(); break;
  default: cout<<"Wrong Input please enter the correct value....";
   }
   cout<<"Do you want to continue?(y/n)";
   cin>>choice;
 }
// fio.close();

 return 0;
}


//For Displaying the all data of the students.
