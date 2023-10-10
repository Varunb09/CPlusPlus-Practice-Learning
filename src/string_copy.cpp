#include<iostream>
#include<cstring>

using namespace std;
int main()
{
    string s1("varun");
    string s2("bhatnagar");
    string s3;
    s3 = s1; // strcpy
    cout<<"s3 : "<<s3<<endl;
    s3 = s1 + " " + s2;  // strcat
    cout<<"s3 : "<<s3<<endl;

}

