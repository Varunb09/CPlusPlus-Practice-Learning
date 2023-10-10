#include<iostream>
using namespace std;
class test
{
// by default access specifier in class is private
// by default access specifier in structure is public

public:
    int a;
    char c;

    void display()
    {
        cout<<"inside function"<<endl;
    }

};
int main()
{
    test o1 = {10,'c'};
    cout<<"a = "<<o1.a<<"c = "<<o1.c<<endl;

    test o2;
    o2.display();

}
