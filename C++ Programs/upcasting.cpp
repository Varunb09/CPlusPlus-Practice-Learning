// base class pointer pointing to derived class object is technically termed as upcasting
//polymorphism refers to single Interface and Multiple Interface
#include<iostream>
using namespace std;

class base
{
    int a;
public:
    base()
    {
        a=10;
    }
    void print()
    {
        cout<<"in print :: base \n";
    }
    // virtual function call function at run time, so at run time "show" function called from derived class not from base class
    virtual void show()
    {
        cout<<"a = "<<a<<" in base :\n";
    }
};
class der:public base
{
    int b;
public:
    der()
    {
        b=20;
    }
    void print()
    {
        cout<<"in print :: derived \n";
    }
    void show()
    {
        cout<<"b = "<<b<<" in derived :\n";
    }
};
int main()
{
    base *b;
    der d;
    b=&d; // UPcasting
    // b-> show() calls at runtime so function called from derived class it is also -
    // - called late binding
    b->show();
    // b-> print() is not a virtual function then it is called at compile time hence base -
    // - class function is called. It is also called early binding
    b->print();
//////////////////////////
//
// ERROR ILLEGAL CONVERSION FROM BASE* TO DERIVED *
// Also called as down casting
//    base b;
//    der *d;
//    d=&b; // UPcasting
//    // b-> show() calls at runtime so function called from derived class it is also -
//    // - called late binding
//    d->show();
//    // b-> print() is not a virtual function then it is called at compile time hence base -
//    // - class function is called. It is also called early binding
//    d->print();

}
