#include<iostream>
#include<cstring>
using namespace std;
// base class
class student
{
protected:
    char name[30];
    int id;
public:
    student()
    {
        cout<<"Base constructor"<<endl;
    }
    student(const char* n,int i)
    {
        strcpy(name,n);
        id = i;
    }
    ~student()
    {
        cout<<"Base destructor"<<endl;
    }

};
// derived 1 class
class electronic_eng : virtual public student
{
protected:
    char ebranch [50];
    char eproject [50];
public:
    electronic_eng()
    {
        cout<<"Derived 1 constructor"<<endl;
    }
    electronic_eng(const char* eb,const char* ep)
    {
        strcpy(ebranch,eb);
        strcpy(eproject,ep);
    }
    ~electronic_eng()
    {
        cout<<"Derived 1 destructor"<<endl;
    }
};
// derived 2 class
class computer_eng : virtual public student
{
protected:
    char cbranch [50];
    char cproject [50];
public:
    computer_eng()
    {
        cout<<"Derived 2 constructor"<<endl;
    }
    computer_eng(const char* cb,const char* cp)
    {
        strcpy(cbranch,cb);
        strcpy(cproject,cp);
    }
    ~computer_eng()
    {
        cout<<"Derived 2 destructor"<<endl;
    }
};
// derived class using derived 1 and derived 2
class embedded_eng : public electronic_eng,public computer_eng
{
protected:
    char mc_mp [50];
    float marks;
public:
    embedded_eng()
    {
        cout<<"Derived constructor"<<endl;
    }
    embedded_eng(const char* b, const char* p, const char* c_p, float m, const char* n, int i) : student(n,i),electronic_eng(b,p),computer_eng(b,p)
    {
        strcpy(mc_mp,c_p);
        marks = m;
    }
    void display()
    {
        cout<<"branch : "<<ebranch<<" project : "<<eproject<<" mc_mp : "<<mc_mp<<" marks : "<<marks<<" name : "<<name<<" ID : "<<id<<endl;
    }
    void display1()
    {
        cout<<"branch : "<<cbranch<<" project : "<<cproject<<" mc_mp : "<<mc_mp<<" marks : "<<marks<<" name : "<<name<<" ID : "<<id<<endl;;
    }
    ~embedded_eng()
    {
        cout<<"Derived destructor"<<endl;
    }

};
int main()
{
    // Base 1
    embedded_eng e1("ece","esd","micro controller",78,"varun",101);
    e1.display();
    // Base 2
    embedded_eng e2("cse","linux","micro processor",98,"narayan",102);
    e2.display1();

}
