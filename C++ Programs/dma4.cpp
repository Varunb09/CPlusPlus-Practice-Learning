#include<iostream>
#include<stdlib.h>
using namespace std;
class test
{
    int a;
public:
    test(int x)
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
    test *ptr = new test(100);
    ptr->display();
    delete ptr;

}

