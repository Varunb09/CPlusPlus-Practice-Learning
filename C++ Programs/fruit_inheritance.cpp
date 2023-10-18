#include<iostream>
#include<cstring>
using namespace std;
class friut
{
protected:
    int size_F;
    char name[50];
public:
    friut()
    {
    }
    friut(const char* n,int s)
    {
        strcpy(name, n);
        size_F = s;
    }
    ~friut()
    {
    }
};
class apple : public friut
{
    float cost;
public:
    apple()
    {
    }
    apple(float c,const char* n, int s) : friut(n,s)
    {
        cost = c;
    }
    apple(apple &a)
    {
        strcpy(name,a.name);
        cost = a.cost;
        size_F = a.size_F;
    }
    void display()
    {
        cout<<cost<<" "<<name<<" "<<size_F<<endl;
    }
    ~apple()
    {
    }
};
int main()
{
    apple a1(50.2,"mango",2);
    a1.display();
    apple a2 = a1;
    a2.display();

}
