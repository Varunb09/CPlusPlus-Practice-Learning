// friend is keyword to access private and protected members of class outside the class of non member function
#include<math.h>
#include<iostream>
using namespace std;
class test
{
        double a,b;
public:
        test(double a=0,double b=0.0)
        {
            this->a=a;
            this->b=b;
        }
        friend void add(test);
        friend void sub(test);
        friend void mul(test);
        friend void div(test);

};
void add(test m)
{
    double c;
    c=m.a+m.b;
    cout<<"c with a+b is : "<<c<<endl;
}
void sub(test m)
{
    double c;
    c=m.a-m.b;
    cout<<"c with a-b is : "<<c<<endl;
}
void mul(test m)
{
    double c;
    c=m.a*m.b;
    cout<<"c with a*b is : "<<c<<endl;
}void div(test m)
{
    double c;
    c=m.a/m.b;
    cout<<"c with a/b is : "<<c<<endl;
}
int main()
{
    test o1(1,200);
    add(o1);
    sub(o1);
    mul(o1);
    div(o1);

}


