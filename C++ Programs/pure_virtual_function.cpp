#include<iostream>
using namespace std;

class Base
{
   int x;
public:
    Base()
    {

    }
    virtual void fun() = 0;//  pure virtual function
    Base(int i)
    {
        x = i;
        cout<<"x : "<<x<<endl;
    }
};

// This class ingerits from Base and implements fun()
class Derived1: public Base
{
    int y;
public:
    Derived1(int i, int j) : Base(i) // Initalize list a
    {
        y = j;
        cout<<"y : "<<y<<endl;
    }
    void fun() { cout << "derived 1 called \n"; }
};
class Derived2: public Base
{
public:
    Derived2()
    {

    }
    void fun() { cout << "derived 2 called \n"; }
};

int main(void)
{
    cout<<sizeof(class Base)<<endl;
    //
    Derived1 d1(4,5);
    d1.fun();
    Derived2 d2;
    d2.fun();
    return 0;
}
