#include<iostream>
#include<cstring>

using namespace std;
int main()
{
    string s1("varun");
    string s2("vaRUN");
    // string comaprison s1 with s2 using compare function
    int res = s1.compare(s2);
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
