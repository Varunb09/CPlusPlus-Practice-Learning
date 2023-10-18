/*

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
    void operator +(bin m)
    {
        bin o3;
        o3.a=a+m.a;
        o3.b=b+m.b;
        cout<<"a = "<<o3.a<<" b :"<<o3.b<<endl;
    }
};
int main()
{
    bin o1(10,20);
    bin o2(100,200);
    o1+o2;
}

*/




// ANOTHER METHOD USING RETURN VALUE




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
    bin o2(100,200);
    bin o3 = o1+o2;
    o3.display();
}
