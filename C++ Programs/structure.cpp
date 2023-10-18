#include<iostream>
#include<string.h>
using namespace std;
class student
{
private:
    char name[20];
    int college_id;
    char course[20];
    float total_marks;
    float fees;
public:
    void enroll_student(char*n,int i, char*c,float f)
    {
        strcpy(name,n);
        college_id = i;
        strcpy(course,c);
        fees = f;
        total_marks = 0;
    }
    void set_marks(float total)
    {
        total_marks = total;
    }
    float calculate_percentage(int no_subjects)
    {
        return(total_marks/no_subjects);
    }
};

int main()
{
    char name[20];
    int id;
    char course[20];
    float fees;
    student anu;
    cout<<"Enter the name,id,course selected and fees"<<endl;
    cin>>name>>id>>course>>fees;

    anu.enroll_student(name,id,course,fees);

    float marks;
    int no_subjects;

    cout<<"Enter total marks and number of subjects"<<endl;
    cin>>marks>>no_subjects;

    anu.set_marks(marks);
    cout<<anu.calculate_percentage(no_subjects)<<endl;
}
