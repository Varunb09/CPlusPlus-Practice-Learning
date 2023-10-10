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
        cout<<"base constructor\n";
    }
    ~student()
    {
        cout<<"base destructor\n";
    }
};
class eng_stu : public student
{
    char clgname [50];
public:
    eng_stu(const char* c, const char* n, int i, float f)
    {
        strcpy(clgname,c);
        strcpy(name,n);
        id = i;
        fee = f;
        cout<<"derived constructor\n";
    }
    void display()
    {
        cout<<clgname<<" "<<name<<" "<<id<<" "<<fee<<endl;
    }
    ~eng_stu()
    {
        cout<<"derived destructor\n";
    }
};

int main()
{
    eng_stu e1("Techno", "varun",101, 10000);
    e1.display();
}


