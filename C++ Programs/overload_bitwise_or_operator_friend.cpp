
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
    friend bitwise operator |(bitwise& , bitwise&);
};
bitwise operator |(bitwise& m,bitwise& n)
{
    bitwise o3;
    o3.a = m.a|n.a;
    cout<<"o3 = "<<o3.a<<endl;
}
int main()
{
    bitwise o1(0);
    bitwise o2(1);
    o1.display();
    o2.display();
    o1|o2;
}

