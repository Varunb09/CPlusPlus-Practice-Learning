#include<iostream>
using namespace std;
class test
{
public:
    // special member function
    // Default constructor
    test()
    {
        cout<<"In constructor :)"<<endl;
    }

    void display()
    {
        cout<<"inside function"<<endl;
    }

};
int main()
{
    test o2;
    // after this complier calls default test constructor
    o2.display();
}
