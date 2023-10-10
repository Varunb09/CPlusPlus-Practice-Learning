#include<iostream>
#include<cstring>
using namespace std;

class abst_string
{
public:
    virtual char* fun(char*) = 0;//  pure virtual function
};

// This class ingerits from Base and implements fun()
class abst_Uppercase: public abst_string
{
public:
    char* fun(char* temp)
    {
        cout << "derived 1 called \n";
        char *temp1;
        temp1 = strupr(temp);
        return temp1;
    }
};
//class abst_Lowercase: public abs_string
//{
//public:
//    abst_Lowercase()
//    {
//    }
//    char* fun(const char * temp)
//    {
//        cout << "derived 2 called \n";
//        strlwr();
//        char *temp1;
//        *temp1 = strlwr(temp);
//        return temp1;
//    }
//};

int main(void)
{
    char temp;
    char temp1;
    strcpy(temp,"varun");
    abst_Uppercase d1;
    temp1 = d1.fun(temp&);
    cout<<"upper case : "<<*temp<<endl;
    //abst_Lowercase d2("VARUN");
    //d2.fun();
    return 0;
}
