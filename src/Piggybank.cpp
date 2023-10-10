#include<iostream>
#include<string.h>
using namespace std;
class piggybank
{
private:
    int rs5 ;
    int rs10;
    int rs20;
    float sum;
    int a[3];
public:
    void get_n_o_n(int rs5, int rs10, int rs20)
    {
            a[0] = rs5;
            a[1] = rs10;
            a[2] = rs20;
            cout<<"rs5 : "<<a[0]<<" rs10 : "<<a[1]<<" rs20 : "<<a[2]<<endl;
          //  return a;
    }
    void set_n_o_n (int rs_5, int rs_10, int rs_20)
    {
        rs5 += rs_5;
        rs10 += rs_10;
        rs20 += rs_20;
        display();
    }
    float total_amount()
    {
        sum = ((rs5*5)+(rs10*10)+(rs20*20));
        return sum;
    }
    void display()
    {
        cout<<"rs5 : "<<rs5<<" rs10 : "<<rs10<<" rs20 : "<<rs20<<endl;
    }
};

int main()
{
    while(1)
    {
    int x=0;
    float sum;
    cout<<"Welcome to piggy\n"<<endl;
    cout<<"Select option to access to piggiy : \n"<<endl;
    cout<<"1. get number of notes  \n2. set number of notes  \n3. calculate sum\n"<<endl;
    cin>>x;
    piggybank p1;
    switch(x)
    {
        case 1:
                p1.get_n_o_n(3,2,1);
                break;
        case 2:
                //piggybank p1;
                p1.set_n_o_n(6,5,4);
                break;
        case 3:
                //piggybank p1;
                sum = p1.total_amount();
                cout<<"Sum : "<<sum<<endl;
                break;
        default :
                cout<<"Wrong input"<<endl;
    }
    }
}


