#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class student
{
private:
    char *a;
    float m;
    int id;
// const used for getting same array after passing into the class to avoid (depricated conversion from pointer to string)
public:
    void init(char x[],float y,int z,int i)
    {
        a = (char*) calloc(i+1,sizeof(char));
        strcpy(a,x);
        m=y;
        id=z;
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

    student o1;
    cout<<"Enter data of student"<<endl;
    cout<<"Enter name : "<<endl;
    cout<<"How long do you want the string? "<<endl;
    cin>>i;
    a = (char*) calloc(i+1,sizeof(char));
    cin>>a;
    cout<<"Enter marks : "<<endl;
    cin>>m;
    cout<<"Enter id : "<<endl;
    cin>>id;

    o1.init(a,m,id,i);
    o1.display();
}

