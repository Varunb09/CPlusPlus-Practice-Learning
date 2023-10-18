#include<iostream>
using namespace std;
int main()
{
    int a = 12;
    int &ref = a;
    ref++;
    cout<< "a = "<<a<<endl;
    a++;
    cout<< "a = "<<a<<endl;
    cout<< "size int ref = "<<sizeof(int&)<<endl;
    cout<< "size of char ref = "<<sizeof(char&)<<endl;
//  size of reference pointer vary according to data types
}
