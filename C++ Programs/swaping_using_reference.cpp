#include<iostream>
using namespace std;
void swap(int &ref1,int &ref2)
{
        ref1=ref1+ref2;
        ref2=ref1-ref2;
        ref1=ref1-ref2;
}
int main()
{
    int a =10,b=20;
    int &ref1 = a;
    int &ref2 = b;
    swap(ref1,ref2);
    cout<<"a after= "<<ref1<<"b after= "<<ref2<<endl;
}
