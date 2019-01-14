#include <iostream>
#include <vector>
using namespace std;

int main(){
    /*
    vector<int> grades;
    int total = 0, grade = 0;
    for(int i = 1; i <= 5; ++i){
        cout << "Enter a grade: ";
        cin >> grade;
        grades.push_back(grade);
    }
    total = grades[0] + grades[1] +
            grades[2] + grades[3] + grades[4];

    cout << "The total of grade is: " << total << endl;
    total = 0;
    for(int i = 0; i < grades.size(); ++i)
        total += grades[i];
    cout << "The total of grade is: " << total << endl;
    */
    vector<string> names;
    names.push_back("Raymond");
    names.push_back("David");
    names.push_back("Cynthia");
    names.push_back("Jennifer");
    cout << endl;
    names.pop_back();
    for(int i = 0; i < names.size(); ++i){
        cout << names[i] << " ";
    };
    cout << endl;
    names.pop_back();
    for(int i = 0; i < names.size(); ++i){
        cout << names[i] << " ";
    };
    cout << endl;
    names.pop_back();
    for(int i = 0; i < names.size(); ++i){
        cout << names[i] << " ";
    };
    cout << endl;
    names.pop_back();
    for(int i = 0; i < names.size(); ++i){
        cout << names[i] << " ";
    };
    cout << endl;

    return (0);
};
