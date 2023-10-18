// Hierarical Inheritance
#include<iostream>
#include<cstring>
using namespace std;

// BASE CLASS Student
class student
{
public:
    student()
    {
    }
    student()
    {
    }
    ~student()
    {
    }
};
// ----------------------------------------------------
// DERIVED CLASS 1 Engineering Student
class eng_stu: public student
{

public:
    eng_stu()
    {
    }
    eng_stu() : student()
    {
        strcpy();
    }
    ~eng_stu()
    {
    }
};
// SUB DERIVED CLASS 1 computer science
class comp_stu : public eng_stu
{
public:
    comp_stu()
    {
    }
    comp_stu() : eng_stu()
    {
    }
    void display()
    {
    }
    ~comp_stu()
    {
    }
};
// DERIVED CLASS 2 Medical Student
class med_stu: public student
{
public:
    med_stu()
    {
    }
    med_stu() : student()
    {
    }
    ~med_stu()
    {
    }
};
// SUB DERIVED CLASS 2 Homepathic
class homep_stu : public med_stu
{
public:
    homep_stu()
    {
    }
    homep_stu() : med_stu()
    {
    }
    void display1()
    {
    }
    ~homep_stu()
    {
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
