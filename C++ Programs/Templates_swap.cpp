#include<iostream>
using namespace std;
template<class T,typename T1>
void swapno(T a, T1 b)
{
    T c;
    c = a;
    a = b;
    b = c;
    cout<<"after swap : "<<"a = "<<a<<"b = "<<b<<endl;
}
int main()
{
    swapno(10,56.2);
    return 0;
}
