#include<iostream>
using namespace std;
namespace cranes
{
    int a = 12;
}
namespace varsity
{
    int a = 20;
}
using namespace varsity;
int main()
{
    cout<<"cranes"<<cranes::a<<std::endl;
    cout<<"varsity"<<a<<std::endl;

    return 0;
}
