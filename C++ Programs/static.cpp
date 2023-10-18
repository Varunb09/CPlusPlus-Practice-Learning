#include<iostream>
using namespace std;
class Stat
{
    int code;
    static int count;
public:
    Stat()
    {
            code=++count;
    }
    void showcode()
    {
        cout<<"object number is : "<<code<<endl;
    }
    static void showcount()
    {
        cout<<"count object : "<<count<<endl;
    }
};
int Stat::count;
int main()
{
    Stat obj1,obj2;
    obj1.showcount();
    obj1.showcode();
    obj2.showcount();
    obj2.showcode();

//    Stat obj1;
//    obj1.showcount();
//    obj1.showcode();
//    Stat obj2;
//    obj2.showcount();
//    obj2.showcode();
}
