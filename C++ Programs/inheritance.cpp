// Simple Inheritance
#include<iostream>
using namespace std;
class base
{
public:
    base()
    {
        cout<<"base constructor\n";
    }
    ~base()
    {
        cout<<"base destructor\n";
    }
};
class derived1: public base
{
public:
    derived1()
    {

        cout<<"derived1 constructor\n";
    }
    ~derived1()
    {
        cout<<"derived1 destructor\n";
    }
};
//
class derived2 : public derived1
{
public:
    derived2()
    {

        cout<<"derived2 constructor\n";
    }
    ~derived2()
    {
        cout<<" derived2 destructor\n";
    }
};
int main()
{
    cout<<"\n multi level inheritance : \n";
    derived2 d2;

}


