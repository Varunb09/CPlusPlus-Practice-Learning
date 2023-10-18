#include<iostream>
using namespace std;
class test
{
    int a,b;
    int c;
public:
    test(int x=0, int y=0):a(x),b(y),c(10)
    {
    }
    //constant member function
    void display()const
    {
        //a=50   ERRROR
        cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    }
};
int main()
{
    //constant object
    // constant object can call only constant member function
    const test o1(10,20);
    o1.display();
}
