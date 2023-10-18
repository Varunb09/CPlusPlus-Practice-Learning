// urinary operator with member function overloading
#include<iostream>
using namespace std;
class ope
{
    int a;
public:
    ope(int x = 0)
    {
        a=x;
    }
    void display()
    {
        cout<<"a= "<<a<<endl;
    }
    void operator ++()
    {
        ++a;
    }
};
int main()
{
    ope o(10);
    o.display();
    ++o;
    o.display();
}
