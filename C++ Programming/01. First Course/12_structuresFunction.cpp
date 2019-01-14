#include <iostream>

using namespace std;
struct student{
    int age;
    char name[20];
};

void display(struct student rec){
    //struct student rec;
    cout<<"age = "<<rec.age<<endl;
    cout<<"name = "<<rec.name<<endl;
}
int main(){
    struct student record1 = {23,"Zobayer"};
    struct student record2 = {32,"Rifat"};

    display(record1);
    display(record2);

    return (0);
}
