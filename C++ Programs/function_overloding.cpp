#include<iostream>
using namespace std;

void fun(int a,int b)
{
    cout<<a<<" "<<b<<endl;
}
void fun(int a,int b,int c)
{
    cout<<a<<" "<<b<<" "<<c<<endl;
}
void fun(double a,double b)
{
    cout<<a<<" "<<b<<endl;
}

int main()
{
    fun(1,2);
    fun(5.2,6.3);
    fun(1,2,3);
//      fun(57,2.3);    ERROR function not found as argument provided
//      fun(1,2.3,5);   ERROR
}

