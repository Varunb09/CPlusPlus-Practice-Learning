#include<iostream>
#include<cstring>
using namespace std;
class student
{
protected:
    char name[50];
    float fee;
    int id;
public:
    student()
    {

    }
    student(const char* n, int i, float f)
    {
        strcpy(name,n);
        id = i;
        fee = f;
        //cout<<"base constructor\n";
    }
    ~student()
    {
        //cout<<"base destructor\n";
    }
};
class eng_stu : public student
{
    char clgname [50];
public:
    eng_stu()
    {

    }
    // initialze list method manually calling base class parameterized constructor starting with ':'
    eng_stu(const char* c, const char* n, int i, float f):student(n,i,f)
    {
        strcpy(clgname,c);
        //cout<<"derived constructor\n";
    }
    eng_stu(eng_stu &m)
    {
        strcpy(clgname,m.clgname);
        strcpy(name,m.name);
        id = m.id;
        fee = m.fee;
    }

    void display()
    {
        cout<<clgname<<" "<<name<<" "<<id<<" "<<fee<<endl;
    }
    ~eng_stu()
    {
        //cout<<"derived destructor\n";
    }
};

int main()
{
    // only calling derived class with only one argument
    eng_stu e1("techno","varun",101,40000);
    e1.display();
    eng_stu e2 = e1;
    e2.display();
}

