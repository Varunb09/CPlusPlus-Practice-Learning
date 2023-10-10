#include<iostream>
#include<vector>
// STL : container,iterator, and algorithm
using namespace std;
int main()
{

    vector<int> vobj;
    vobj.push_back(10);
    vobj.push_back(20);
    vobj.push_back(30);
    vobj.push_back(40);
    vobj.push_back(50);
    if(!vobj.empty())
    {
        cout<<"Displaying the content of vector : "<<endl;
        for(int i=0;i<vobj.size();i++)
        {
            cout<<vobj[i]<<endl;
        }
    }
    else
    {
        cout<<"Empty Vector"<<endl;
    }
    ////////////////////
    vector<char> vobj1;
    vobj1.push_back('a');
    vobj1.push_back('b');
    vobj1.push_back('c');
    cout<<"Displaying the content of vector : "<<endl;
    vector<char>::iterator it;
    for(it=vobj1.begin();it!=vobj1.end();++it)
    {
        cout<<*it<<endl;
    }
    // both for loop are similar
    cout<<"Displaying the content of vector : "<<endl;
    for(int i=0;i<vobj1.size();i++)
    {
        cout<<vobj1[i]<<endl;
    }
    // Reverse iterator
    cout<<"Displaying the content of vector : "<<endl;
    vector<char>::reverse_iterator rit;
    for(rit=vobj1.rbegin();rit!=vobj1.rend();++rit)
    {
        cout<<*rit<<endl;
    }
    // front iterator
    cout<<"fron, back"<<endl;
    cout<<vobj.front()<<endl;
    cout<<vobj.back()<<endl;

    // push_back and pop_back
    vobj.pop_back();
    int c = vobj.size();
    cout<<c<<endl;

    vobj.push_back(50);
    c = vobj.size();
    cout<<c<<endl;







    return 0;
}
