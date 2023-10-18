// commented program give error amiguous due acessing of base multiple times
/*
#include<iostream>
using namespace std;
class person
{
public:
    void show()
    {
        cout<<"inside person :\n"<<endl;
    }

};
class men : public person
{

};
class women : public person
{

};
class child : public men,public women
{

};
int main()
{
    child c;
    c.show();
}

*/

// correct code can be made by using virtual keyword before each derived class

#include<iostream>
using namespace std;
class person
{
public:
    void show()
    {
        cout<<"inside person :\n"<<endl;
    }

};
class men : virtual public person
{

};
class women : virtual public person
{

};
class child : public men,public women
{

};
int main()
{
    child c;
    c.show();
}

