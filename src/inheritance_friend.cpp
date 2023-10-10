// Simple Inheritance
#include<iostream>
using namespace std;
class test
{
public:
    int a,b;
public:
    test(int a=0,int b=0)
    {
        this->a=a;
        this->b=b;
    }
    friend void multi(test);
};


class derived : public test
{
public:
    derived()
    {
        cout<<"derived constructor\n";
        test o1(10,20);
        multi(o1);
    }
    void multi(test m)
    {
        int c;
        c=m.a*m.b;
        cout<<"c : "<<c<<endl;
    }
};
int main()
{
    derived d1;
}
