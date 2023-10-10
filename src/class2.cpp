#include<iostream>
using namespace std;
class test
{
private:
    int a;
    char c;
public:
    void init(int x,char y)
    {
       a=x;
       c=y;
    }
    void display()
    {
        cout<<"a = "<<a<<"c = "<<c<<endl;
    }

};
int main()
{
    test o1;
    o1.init(10,'c');
    o1.display();

}

