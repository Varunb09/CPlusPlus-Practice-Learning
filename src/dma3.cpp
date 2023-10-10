#include<iostream>
#include<stdlib.h>
using namespace std;
class test
{
public:
    test()
    {
        cout<<"default constructor\n";
    }
    ~test()
    {
        cout<<"In destructor :)"<<endl;
    }

};
int main()
{
    test *ptr = new test[5];
    delete [] ptr;
    // using malloc, calloc here will not invoke constructor and destructor
    //    test *p = (test*)malloc(sizeof(test));
    //    free(p);
}
