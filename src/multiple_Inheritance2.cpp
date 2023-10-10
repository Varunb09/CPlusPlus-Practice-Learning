#include<iostream>
#include<cstring>
using namespace std;
class electronic_eng
{
protected:
    char ebranch [50];
    char eproject [50];
public:
    electronic_eng(const char* eb=NULL,const char* ep=NULL)
    {
        cout<<"Base 1 constructor"<<endl;
        strcpy(ebranch,eb);
        strcpy(eproject,ep);
    }
    ~electronic_eng()
    {
            cout<<"Base 1 destructor"<<endl;
    }
};
class computer_eng
{
protected:
    char cbranch [50];
    char cproject [50];
public:
    computer_eng(const char* cb=NULL,const char* cp=NULL)
    {
        cout<<"Base 2 constructor"<<endl;
        strcpy(cbranch,cb);
        strcpy(cproject,cp);
    }
    ~computer_eng()
    {
        cout<<"Base 2 destructor"<<endl;
    }
};
class embedded_eng : public electronic_eng,public computer_eng
{
protected:
    char mc_mp [50];
    float marks;
public:
    embedded_eng(const char* b=NULL, const char* p=NULL, const char* c_p=NULL, float m=0) : electronic_eng(b,p),computer_eng(b,p)
    {
        cout<<"Derived constructor"<<endl;
        strcpy(mc_mp,c_p);
        marks = m;
    }
    void display()
    {
        cout<<"branch : "<<ebranch<<" project "<<eproject<<" mc_mp : "<<mc_mp<<" marks : "<<marks<<endl;
    }
    void display1()
    {
        cout<<"branch : "<<cbranch<<" project "<<cproject<<" mc_mp : "<<mc_mp<<" marks : "<<marks<<endl;
    }
    ~embedded_eng()
    {
        cout<<"Derived destructor"<<endl;
    }

};
int main()
{
    // Base 1
    embedded_eng e1("ece","esd","mc",78);
    e1.display();
    // Base 2
    embedded_eng e2("cse","linux","mp",98);
    e2.display1();

}
