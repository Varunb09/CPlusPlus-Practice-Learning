// friend is keyword to access private and protected members of class outside the class of non member function

#include<iostream>
using namespace std;
class test
{
        int a,b;
public:
        test(int a=0,int b=0)
        {
            this->a=a;
            this->b=b;
        }
        friend void multi(test);
};
void multi(test m)
{
    int c;
    c=m.a*m.b;
    cout<<"c : "<<c<<endl;
}
int main()
{
    test o1(10,20);
    multi(o1);
}

