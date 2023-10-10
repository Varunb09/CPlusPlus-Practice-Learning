//polymorphism refers to single Interface and Multiple implementation
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
    void show()
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
    void show()
    {
        cout<<"b = "<<b<<" in derived :\n";
    }
};
// As show function is similar to both base and derived class therefore this situation is called as method overiding
// overing is applicable in inhertance only
int main()
{
    base b;
    b.show();
    der d;
    d.show();
}
