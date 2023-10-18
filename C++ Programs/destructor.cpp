#include<iostream>
using namespace std;
class test
{
    int a;
    char c;
public:
    test()
    {
        cout<<"main constructor\n";
    }
    test(int x)
    {
        cout<<"In constructor :)"<<endl;
    }
    ~test()
    {
        cout<<"In destructor :)"<<endl;
    }

};
void fun()
{
    test o1(10);
    test o2;
}
int main()
{
    fun();
    cout<<"In main :)"<<endl;
}

