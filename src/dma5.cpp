#include<iostream>
#include<stdlib.h>
using namespace std;
class test
{
    int a;
public:
    test(int x=0)
    {
        a=x;
        cout<<"default constructor\n";
    }

    ~test()
    {
        cout<<"In destructor :)"<<endl;
    }
    void display()
    {
        cout<<"a = "<<a<<endl;
    }

};
int main()
{
    test o;
    test *ptr = new test(100);
    ptr->display();
    delete ptr;

}
