// Hierarical Inheritance
#include<iostream>
#include<cstring>
using namespace std;

// BASE CLASS Student

class student
{
protected:
    char name [50];
    int id;
public:
    student()
    {
        cout<<"\nStudent constructor :\n"<<endl;
    }
    student(const char* n,float i)
    {
        strcpy(name,n);
        id = i;
    }
    ~student()
    {
        cout<<"\nStudent destructor :\n"<<endl;
    }
};
// ----------------------------------------------------

// DERIVED CLASS 1 Engineering Student

class eng_stu: public student
{
protected:
    char cllg_name [50];
public:
    eng_stu()
    {
        cout<<"\nEngineering constructor :\n"<<endl;
    }
    eng_stu(const char* p, const char* n,float i) : student(n,i)
    {
        strcpy(cllg_name,p);
    }
    ~eng_stu()
    {
        cout<<"\nEngineering destructor :\n"<<endl;
    }
};
// ------------

// SUB DERIVED CLASS 1 computer science

class comp_stu : public eng_stu
{
    char branch [50];
    float marks;
public:
    comp_stu()
    {
        cout<<"\nComputer Science constructor :\n"<<endl;
    }
    comp_stu(const char* n,float i,const char* p,const char* b,int m) : eng_stu(p,n,i)
    {
        strcpy(branch, b);
        marks = m;
    }
    void display()
    {
        cout<<name<<" "<<id<<" "<<cllg_name<<" "<<branch<<" "<<marks<<endl;
    }
    ~comp_stu()
    {
        cout<<"\nComputer Science destructor :\n"<<endl;
    }
};
//  -------------------------------------------
// -------------------------------------------

// DERIVED CLASS 2 Medical Student

class med_stu: public student
{
protected:
    char med_cllg_name [50];
public:
    med_stu()
    {
        cout<<"\nMedical constructor :\n"<<endl;
    }
    med_stu(const char* p1, const char* n,float i) : student(n,i)
    {
        strcpy(med_cllg_name,p1);
    }
    ~med_stu()
    {
        cout<<"\nMedical destructor :\n"<<endl;
    }
};
// ------

// SUB DERIVED CLASS 2 Homepathic

class homep_stu : public med_stu
{
    char branch1 [50];
    float marks1;
public:
    homep_stu()
    {
        cout<<"\nHomepathic constructor :\n"<<endl;
    }
    homep_stu(const char* n1,float i1,const char* p1,const char* b1,int m1) : med_stu(p1,n1,i1)
    {
        strcpy(branch1, b1);
        marks1 = m1;
    }
    void display1()
    {
        cout<<name<<" "<<id<<" "<<med_cllg_name<<" "<<branch1<<" "<<marks1<<endl;
    }
    ~homep_stu()
    {
        cout<<"\nHomepathic destructor :\n"<<endl;
    }
};

// ---------------------------------------------
int main()
{
    comp_stu c2("Varun",101,"TECHNO","CS",99);
    c2.display();
    homep_stu m2("Narayan",501,"RNT","homepathic",98);
    m2.display1();
    cout<<"\n ----------------- :) -----------------\n"<<endl;
}

