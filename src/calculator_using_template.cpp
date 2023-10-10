#include<iostream>
#include<cmath>
using namespace std;
template<class T>

class calculator
{
private:
    T num1,num2;
public:
    calculator(T n1,T n2)
    {
        //cout<<"in constructor \n"<<endl;
        num1 = n1;
        num2 = n2;
    }
    void displayResult()
    {
        cout<<"No."<<num1<<"and"<<num2<<"."<<endl;
        cout<<"Addition is : "<<add()<<endl;
        cout<<"Sub is : "<<sub()<<endl;
        cout<<"Mul is : "<<mul()<<endl;
        cout<<"Div is : "<<div()<<endl;

    }
    T add()
    {
        //T c;
        return(num1+num2);
        //cout<<c<<endl;
    }
    T sub()
    {
        //T c;
        return(num1-num2);

        //cout<<abs(c)<<endl;
    }
    T mul()
    {
        //T c;
        return(num1*num2);
        //cout<<c<<endl;
    }
    T div()
    {
        //T c;
        return(num1/num2);
        //cout<<c<<endl;
    }
};


int main()
{
    double a=10,b=20,c;
    calculator<int> c1(2,1);
    calculator<float> c2(2.5,1.4);

    c1.displayResult();
    c2.displayResult();

    return 0;
}



