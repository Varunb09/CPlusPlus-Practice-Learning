#include<iostream>
using namespace std;

#define r 3
#define c 3
int main()
{
    int (*p)[c] = new int [r][c];
    cout<<"Enter 3 elements : \n"<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0;j<3;j++)
        {
                cin>>p[i][j];
        }
    }
    for(int i = 0; i<3; i++)
    {
        for(int j = 0;j<3;j++)
        {
                cout<<p[i][j]<<"\t";
        }
        cout<<endl;
    }
    delete [] p;
}
