#include<iostream>
#include<cstring>
using namespace std;
class my_string
{
private:
   char s1[50],s2[50];
public:
    my_string(const char *x = NULL, const char *y = NULL)
    {
        strcpy(s1,x);
        strcpy(s2,y);
    }
    void display()
    {
        cout<<"s1 : "<<s1<<" s2 : "<<s2<<endl;
    }
    friend void operator +(my_string,my_string);
    friend void operator ==(my_string m1,my_string m2);
    //friend void operator =(my_string m1,my_string m2);
    void operator =(my_string m1)
    {
        cout<<"s1 : "<<s1<<"s2 : "<<s2<<endl;
        strcpy(s1,m1.s1);
        strcpy(s2,m1.s2);
        cout<<"s1 : "<<s1<<"s2 : "<<s2<<endl;
        cout<<"m1.s1 : "<<m1.s1<<"m1.s2 : "<<m1.s2<<endl;

    }
};
void operator +(my_string m1,my_string m2)
{
    char ch1[50],ch2[50];
    strcpy(ch1,m1.s1);
    strcat(ch1,m2.s1);
    strcpy(ch2,m1.s2);
    strcat(ch2,m2.s2);
    cout<<"ch1 : "<<ch1<<" ch2 : "<<ch2<<endl;

}
void operator ==(my_string m1,my_string m2)
{
    char ch1[50],ch2[50];
    strcpy(ch1,m1.s1);
    int res = strcmp(ch1,m2.s1);
    if (res == 0)
    {
            cout<<"res : "<<res<<endl;
            cout<<"equal string";
    }
    else if(res > 0)
    {
        cout<<"res : "<<res<<endl;
        cout<<"s1 > s2"<<endl;
    }
    else
    {
        cout<<"res : "<<res<<endl;
        cout<<"s1 < s2"<<endl;
    }

}


int main()
{
    my_string o1("varun","cranes");
    my_string o2("bhatnagar","banglore");
    o1+o2;
    o1==o2;
    o1=o2;
    //o1!=o2;
}

