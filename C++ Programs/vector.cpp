#include<iostream>
#include<vector>
// STL : container,iterator, and algorithm
using namespace std;
int main()
{
    int sum=0;
    vector<int> vobj;
    vobj.push_back(10);
    vobj.push_back(20);
    vobj.push_back(30);
    vobj.push_back(40);
    vobj.push_back(50);
    vector<int>::reverse_iterator it;
    for(it=vobj.rbegin();it!=vobj.rend();++it)
    {
        sum += *it;
        vobj.pop_back();
    }
    cout<<"sum is : "<<sum<<endl;
    cout<<vobj.size();
    vobj.pop
    return 0;
}

