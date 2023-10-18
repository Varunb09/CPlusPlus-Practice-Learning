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
        cout<<"a + jb = "<<a<<" + j"<<b<<endl;
    }
    bin operator +(bin m)
    {
        bin o3;
        o3.a=a+m.a;
        o3.b=b+m.b;
        return o3;
    }
};
int main()
{
    bin o1(10,20);
    o1.display();
    bin o2(100,200);
    o2.display();
    bin o3 = o1+o2;
    o3.display();
}
