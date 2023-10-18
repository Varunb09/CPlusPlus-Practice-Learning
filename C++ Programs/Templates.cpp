// Templetes: Enable you to perform generic programming
// test your code on different data types. write once and execute many times on different data types

#include<iostream>
using namespace std;
template<class T,typename T1>
void add(T a, T1 b)
{
    cout<<"RES : "<<a+b<<endl;
}
int main()
{
    add(10,56.2);
    add(10,20);
    add(10.2,2.6);
    return 0;
}
/////////////////////////////////////////
//Run only one at a time
////////////////////////////
#include<iostream>
using namespace std;
template<class T,typename T1>
T1 add(T a, T1 b)
{
    return (a+b);
}
int main()
{
    cout<<"Res : "<<add(10,56.2)<<endl;;
    cout<<"Res : "<<add(10.21,56.2)<<endl;;
    cout<<"Res : "<<add(10,20)<<endl;;
    return 0;
}

