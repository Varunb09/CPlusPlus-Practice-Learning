#include<iostream>
using namespace std;
int fun(int a,int b,int c = 0,int d = 0);
// int fun(int a,int b,int c = 0,int d);    ERROR as default values should be always from right to left
int main()
{
    cout<<fun(1,2)<<endl;
    cout<<fun(1,2,3)<<endl;
    cout<<fun(1,2,3,4)<<endl;

}
int fun(int a,int b,int c,int d)
{
    return a+b+c+d;
}
