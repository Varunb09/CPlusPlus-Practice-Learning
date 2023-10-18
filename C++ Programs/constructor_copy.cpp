#include<iostream>
#include<string.h>
using namespace std;
class test
{
    int a;
    char name[20];
public:
    test()
    {
        cout<<"In default constructor :)"<<endl;
    }
    // special member function
    // parameterized constructor
    test(int x,const char*s)
    {
        cout<<"In parmeterized constructor :)"<<endl;
        a=x;
        strcpy(name,s);
    }
    // copy constructor
    test(test &m)
    {
        cout<<"in copy constructor"<<endl;
        a=m.a;
        strcpy(name,m.name);
    }
    void display()
    {
        cout<<"a = "<<a<<" name "<<name<<endl;
    }

};
int main()
{
    test o1;
    // after this complier calls default test constructor

    test o2(12,"varsity");
    o2.display();

    test o3(o2);
//  test o3=o2;
    o3.display();


}


