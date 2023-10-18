#include<iostream>
#include<string.h>
using namespace std;
class String
{
private:
    int size;
    char *s;
public:
    String(const char *str = NULL);//constructor
    ~String(){delete [] s;};//destructor
    String(const String&);//copy constructor
    void print(){cout << s << endl; }// function to print string
    void change(const char *);//function to change
};
    String::String(const char * str)
    {
        size = strlen(str);
        s = new char[size+1];
        strcpy(s,str);
    }
    void String::change(const char *str)
    {
        delete [] s;
        size = strlen(str);
        s = new char[size+1];
        strcpy(s,str);
    }
    String::String(const String& old_str)
    {
        size = old_str.size;
        s = new char[size+1];
        strcpy(s,old_str.s);
    }

int main()
{
    // deep coping means str1 and str2 gets different memory
        String str1("Cranes");
        String str2 = str1;
        str1.print();
        str2.print();
        str1.change("Varun Bhatnagar");
        str2.change("ECE Branch");
        str1.print();
        str2.print();
        return 0;
}
