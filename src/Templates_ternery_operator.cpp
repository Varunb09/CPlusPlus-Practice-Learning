#include<iostream>
using namespace std;
template<class T,typename T1>
T ternary_operator(T a, T1 b)
{
    //a>b?cout<<"a greater":cout<<"b greater";;
    a>b ? 0 : 1;
}
int main()
{
    int a;
    a = ternary_operator(100,56.2);
    if(a == 1)
        cout<<"b greater"<<endl;
    else
        cout<<"b greater"<<endl;
    return 0;
}

