#include<iostream>
using namespace std;
#define swp(a,b) a=a+b;b=a-b;a=a-b;cout<<"a= "<<a<<"b= "<<b<<endl;
// inline enable simple funtion to work like macros
inline int swap(int a,int b)
{
        a=a+b;
        b=a-b;
        a=a-b;
        cout<<"a= "<<a<<"b= "<<b<<endl;
}
int main()
{
    int a =10,b=20;
    swp(a,b);
    swap(10,20);

}

