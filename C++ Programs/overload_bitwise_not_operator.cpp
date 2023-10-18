#include<iostream>
using namespace std;

class bitwise
{
private:
    int a;
public:
    bitwise(int x = 0)
    {
        a = x;
    }
    void display()
    {
        cout<<"a = "<<a<<endl;
    }
   void operator ~()
    {
        a = ~a;
    }
};
int main()
{
    bitwise o1(1);
    o1.display();
    ~o1;
    o1.display();
}

