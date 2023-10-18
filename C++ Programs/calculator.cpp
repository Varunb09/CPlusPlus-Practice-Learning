#include<iostream>
#include<cmath>
using namespace std;
//template<class T,typename T1>
//T ternary_operator(T a, T1 b)
//{
//    //a>b?cout<<"a greater":cout<<"b greater";;
//    a>b ? 0 : 1;
//}

class calculator
{
//protected:
//    double c;
public:
    calculator()
    {
        cout<<"in constructor \n"<<endl;
    }
    double add(double a,double b)
    {
        double c;
        c = a+b;
        return c;
    }
    double sub(double a,double b)
    {
        double c;
        c = a-b;
        return abs(c);
    }
    double mul(double a,double b)
    {
        double c;
        c = a*b;
        return c;
    }
    double div(double a,double b)
    {
        double c;
        c = a/b;
        return c;
    }
};


int main()
{
    double a=10,b=20,c;
    calculator c1;
    c=c1.add(abs(a),abs(b));
    cout<<c<<endl;
    c=c1.sub(abs(a),abs(b));
    cout<<c<<endl;
    c=c1.mul(abs(a),abs(b));
    cout<<c<<endl;
    c=c1.div(abs(a),abs(b));
    cout<<c<<endl;
    return 0;
}


