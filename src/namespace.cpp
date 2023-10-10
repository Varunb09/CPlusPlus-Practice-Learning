#include<iostream>
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
    std::cout<<"cranes"<<cranes::a<<std::endl;
    std::cout<<"varsity"<<a<<std::endl;

    return 0;
}
