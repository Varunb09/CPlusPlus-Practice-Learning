#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
class student
{
private:
    char *a;
    float m;
    int id,v;
// const used for getting same array after passing into the class to avoid (depricated conversion from pointer to string)
public:
    student(char x[],float y,int z,int i)
    {
        v=i;
        cout<<"in parameterized constructor"<<endl;
        a = (char*) calloc(i,sizeof(char));
        strcpy(a,x);
        m=y;
        id=z;
    }
    student(student &s)
    {
        cout<<"in copy constructor"<<endl;
        a = (char*) calloc(s.v,sizeof(char));
        strcpy(a,s.a);
        m=s.m;
        id=s.id;
    }
    void display()
    {
        cout<<"NAME : "<<a<<"  MARKS : "<<m<<" ID : "<<id<<endl;
    }

};
int main()
{
    char *a;
    float m;
    int id,i;

    cout<<"Enter data of student"<<endl;
    cout<<"Enter name : "<<endl;
    cout<<"How long do you want the string? "<<endl;
    cin>>i;
    a = (char*) calloc(i,sizeof(char));
    cin>>a;
    cout<<"Enter marks : "<<endl;
    cin>>m;
    cout<<"Enter id : "<<endl;
    cin>>id;

    student o1(a,m,id,i);
    o1.display();

    student o2(o1);
    o2.display();

}


