#include <iostream>
#include <vector>
using namespace std;

int main(){
    /*
    int grade[5];
    double average = 0.0;
    int numGrades = 5;
    for(int i = 0;i < numGrades; ++i){
        cout << "Enter a grade" << i+1 << ": ";
        cin >> grade[i];
    };
    average = (grade[0] + grade[1] + grade[2] + grade[3] + grade[4])
                / numGrades;

    cout << "The average is " << average << endl;
    */

    vector<int> grades;
    int grade, total;
    double average;
    total = 0;
    for(int i = 1; i <= 5; ++i){
        cout << "Enter a grade: ";
        cin >> grade;
        grades.push_back(grade);
        cout << grade << endl;

    }
    for(int i = 0; i < grades.size(); ++i){
        cout << grades[i] << " ";
        total += grades[i];
    };
    average = total / grades.size();
    cout << endl << "The average is " << average << endl;
    cout << endl;
    return (0);
}
