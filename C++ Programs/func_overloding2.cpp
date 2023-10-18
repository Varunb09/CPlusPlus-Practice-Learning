#include<iostream>
using namespace std;

#define pi 3.14
void area(int);
void area(float);
void area(int,int);

void area(int Side_Square)
{
    cout<<"AREA "<<Side_Square<<"is"<<"\t";
    cout<<Side_Square*Side_Square<<endl;

}
void area(float radius)
{
    cout<<"radius "<<radius<<"is"<<"\t";
    cout<<pi*radius*radius<<endl;

}
void area(int length,int breadth)
{
    cout<<"area rec. "<<length*breadth<<endl;

}

int main()
{
    int side = 10;
    float rad = 12.2f;
    int length = 15,breadth = 4;

    area(side);
    area(rad);
    area(length,breadth);
}

