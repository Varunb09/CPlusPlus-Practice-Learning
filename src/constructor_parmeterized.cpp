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
    void display()
    {
        cout<<"a = "<<a<<" name "<<name<<endl;
    }

};
int main()
{
    test o1;
    test o2(12,"varsity");
    o2.display();

    // after this complier calls default test constructor
}

