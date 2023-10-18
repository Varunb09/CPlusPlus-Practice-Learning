#include<iostream>
using namespace std;
class test
{
    const int a,b;
    int c;
public:
    test(int x=0, int y=0):a(x),b(y),c(10)
    {
    }
    void display()
    {
        cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    }
};
int main()
{
    test o1(10,20);
    o1.display();
}

