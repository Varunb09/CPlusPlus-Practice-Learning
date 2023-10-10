// friend is keyword to access private and protected members of class outside the class of non member function
#include<iostream>
using namespace std;
class test
{
        int meter;
public:
        test(int a=0)
        {
            meter=a;
            cout<<"meter = "<<meter<<endl;
        }

        friend int addfive(test&);
        void display()
        {
            cout<<"meter = "<<meter<<endl;
        }
};
// passing by address "&" to addfive will change the value of meter whereas pass by value meter will not change
int addfive(test& m)
{
    m.meter=5;
    return m.meter;
}
int main()
{
    test o1;
    cout<<"meter = "<<addfive(o1)<<endl;
    o1.display();
}


