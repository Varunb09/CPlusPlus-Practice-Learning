#include<iostream>
#include<string.h>
using namespace std;
class animal
{
private:
    char name[50];
    float height;
    float weight;
public:
    void animal_detail(char*n,float h,float w)
    {
        strcpy(name,n);
        height = h;
        weight = w;
    }
    void display()
    {
        cout<<"name: "<<name<<" height : "<<height<<" weight : "<<weight<<endl;
    }
};

int main()
{
    char name[50];
    int height;
    int weight;
    animal a1;
    cout<<"Enter the name,height,weight"<<endl;
    cin>>name>>height>>weight;

    a1.animal_detail(name,height,weight);
    a1.display();
}

