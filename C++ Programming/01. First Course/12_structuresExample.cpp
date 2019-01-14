#include <iostream>
#include <cstring>

struct student{
    char name[25];
    int age;
    int rollno;
    float percentage;
};

using namespace std;
int main(){
    struct student record1 = {"Adnan",18,02,85.05};
    struct student record2 = {"Tasnim",17,05,50.05};



    cout<<record1.name<<endl;
    cout<<record1.age<<endl;
    cout<<record1.rollno<<endl;
    cout<<record1.percentage<<endl<<endl;

    cout<<record2.name<<endl;
    cout<<record2.age<<endl;
    cout<<record2.rollno<<endl;
    cout<<record2.percentage<<endl;

    return (0);
}
