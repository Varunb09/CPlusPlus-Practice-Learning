#include<iostream>
using namespace std;

class bin
{
    int a,b;
public:
    bin(int x=0,int y=0)
    {
        a=x;
        b=y;
    }
    void display()
    {
        cout<<"a = "<<a<<" b"<<b<<endl;
    }
    friend bin operator +(bin,bin);
};

bin operator +(bin m1, bin m2)
{
    bin o3;
    o3.a=m1.a+m2.a;
    o3.b=m1.b+m2.b;
    return o3;
}

int main()
{
    bin o1(10,20);
    bin o2(100,200);
    bin o3 = o1+o2;
    o3.display();
}
