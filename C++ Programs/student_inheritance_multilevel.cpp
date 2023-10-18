// Simple Inheritance
#include<iostream>
#include<cstring>
using namespace std;
class student
{
protected:
    char name [50];
    int id;
public:
    student()
    {
    }
    student(const char* n,float i)
    {
        strcpy(name,n);
        id = i;
    }
    ~student()
    {
    }
};
class eng_stu: public student
{
protected:
    char project [50];
public:
    eng_stu()
    {
    }
    eng_stu(const char* p, const char* n,float i) : student(n,i)
    {
        strcpy(project,p);
    }
    ~eng_stu()
    {
    }
};
//
class comp_stu : public eng_stu
{
    char branch [50];
    float marks;
public:
    comp_stu()
    {
    }
    comp_stu(const char* n,float i,const char* p,const char* b,int m) : eng_stu(p,n,i)
    {
        strcpy(branch, b);
        marks = m;
    }
    void display()
    {
        cout<<name<<" "<<id<<" "<<project<<" "<<branch<<" "<<marks<<endl;
    }
    ~comp_stu()
    {
    }
};
int main()
{
    comp_stu c2("varun",101,"embedded system design","ece",75);
    c2.display();
}
