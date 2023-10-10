#include<iostream>
using namespace std;

class test
{
    static int a;
    int b;
public:
    static void display()
    {
        cout<<"a = "<<a<<endl;
    }
};
//static variable initialization
int test::a=10;
int main()
{
    test o;
    test p1;
    test::display();
    // for static variable 'n' number of object gets same memory
}
