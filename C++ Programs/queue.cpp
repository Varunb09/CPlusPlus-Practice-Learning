#include<iostream>
#include<queue>
using namespace std;

void showq(queue <int> gq)
{
    queue <int> g = gq;
    while(!g.empty())
    {
        cout<<"\t"<<g.front();
        g.pop();
    }
    cout<<"\n";
}
int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<"the queue is : ";
    showq(q);
    cout<<"\nsize() : "<<q.size();
    cout<<"\nfront() : "<<q.front();
    cout<<"\nback() : "<<q.back();
    cout<<"\npop() : ";
    q.pop();
    showq(q);

    return 0;
}
