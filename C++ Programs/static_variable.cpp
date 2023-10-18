#include<iostream>
using namespace std;

class test
{
    static int a;
public:
    void display()
    {
        cout<<"a = "<<a<<endl;
        cout<<"size : "<<sizeof(a)<<endl;
    }
};
//static variable initialization
int test::a=10;
int main()
{
    test o;
    o.display();
    // for static variable 'n' number of object gets same memory
    test p1;
    p1.display();
}
