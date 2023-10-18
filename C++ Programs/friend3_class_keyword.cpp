// friend is keyword to access private and protected members of class outside the class of non member function
#include<iostream>
#define pi 3.14
using namespace std;
class A
{
    int radius;
public:
        A()
        {
            radius = 50;
        }
        void showA()
        {
            cout<<"radius = "<<radius<<endl;
        }
        friend class B;
};
class B
{
    int area;
public:
        void findarea(A m)
        {
            area=m.radius*m.radius*pi;
            cout<<"area of circle = "<<area<<endl;
        }
};
int main()
{
    A oA;
    B oB;
    oA.showA();
    oB.findarea(oA);
}



