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
    struct student record1;

    strcpy(record1.name,"Adnan");
    record1.age = 18;
    record1.rollno = 01;
    record1.percentage = 85.05;

    cout<<record1.name<<endl;
    cout<<record1.age<<endl;
    cout<<record1.rollno<<endl;
    cout<<record1.percentage<<endl;

    return (0);
}
