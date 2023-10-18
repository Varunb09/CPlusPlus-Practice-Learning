#include<iostream>
using namespace std;
class test
{
    int a;
    char c;
public:
    test(int a, char c);
    void display();
};
// method of writing class function outide the class by using function declaration in class and function def outside class with
// class name "test" and scope resolution operator "::" in this case
    test::test(int a,char c)
    {

        // if not using 'this' keyword a and c will not get value
        // as ambiguities between formal parameter and data member
        this->a=a;
        this->c=c;

    }
    void test::display()
    {
        cout<<"a = "<<a<<"c = "<<c<<endl;
    }

int main()
{
    test o1(10,'a');
    o1.display();
}
