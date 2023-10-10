#include<iostream>
using namespace std;
class test
{
    int a;
public:
    test()
    {
        cout<<"main constructor\n";
    }
    ~test()
    {
        cout<<"In destructor :)"<<endl;
    }

};
void fun()
{
    static test o2;
}
int main()
{
    fun();
    cout<<"In main :)"<<endl;
}
// Static existance remain in program till end of main therefore destructor calls last

