#include <iostream>
using namespace std;
int main(){

    int grade, gradeTotal, numGrades;
    double average;
    numGrades = gradeTotal = 0;
    cout << "Enter a grade: ";
    cin >> grade;
    while (grade != -1){
        gradeTotal += grade;
        ++numGrades;
        cout << "Enter a grade: ";
        cin >> grade;

    }
    average = gradeTotal / numGrades;
    cout << "The average grade is: " << average << endl;

    return (0);
};
