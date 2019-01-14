#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;
int main(){



    struct person{
        string name;
        int age;

    };
    int stdCount;
    cout << "How many students in your class: ";
    cin >> stdCount;
    person *p;
    p = new person[stdCount];
    if(!p){
        cout << "Allocation error!";
        return 1;
    }
    struct person student;
    //strcpy(student.name,"Zobayer");
    student.name = "Zobayer";
    student.age = 18;

    struct person *pointer = &student;
    //pointer = &student;

    //cout << pointer->name << endl;
    //cout << student.age << endl;

    for(int i = 0; i < stdCount; ++i){
        cout << "Enter student " << i+1 << " Name: ";
        cin >> p[i].name;
        cout << "Enter student " << i+1 << " age: ";
        cin >> p[i].age;
        cout << "Student Name is " << p[i].name << " and age " << p[i].age << endl;
    }

    delete[] p;
    return (0);
}
