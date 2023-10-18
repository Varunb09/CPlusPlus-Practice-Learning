#include<iostream>
using namespace std;

int main()
{
    // Example 1
    int *p = new int(100);
    cout<<"*p = "<<*p<<endl;
    delete p;


    // Example 2
    // taking five element and printing them
    int *p1 = new int[5];
    cout<<"Enter 5 elements : \n"<<endl;
    for(int i = 0; i<5; i++)
    {
        cin>>*(p1+i);
    }
    for(int i = 0; i<5; i++)
    {
        cout<<"p = "<<*(p1+i)<<endl;
    }
    delete [] p1;
}
