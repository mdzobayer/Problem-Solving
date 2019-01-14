#include <iostream>
using namespace std;

int qualityPoints(char letterGrade){
    int qPoints;
    if(letterGrade == 'A')
        qPoints = 4;
    else if (letterGrade == 'B')
        qPoints = 3;
    else if(letterGrade == 'C')
        qPoints = 2;
    else if(letterGrade == 'D')
        qPoints = 1;
    else
        qPoints = 0;
    return (qPoints);
}

string getInitials(string first, string middle, string last){
    string firstInit, middleInit, lastInit;
    firstInit = first.substr(0,2);
    middleInit = middle.substr(0,2);
    lastInit = last.substr(0,2);

    return (firstInit + middleInit + lastInit);
}

int main(){
/*
    char grade;
    cout << "Enter the letter Grade: ";
    cin >> grade;
    cout << "A " << grade << " earns "
         << qualityPoints(grade)
         << " quality points. " << endl;
*/
    string firstName, middleName, lastName;
    cout << "Enter your first name: ";
    getline(cin,firstName);
    cout << firstName.substr(2,10) << endl;
    cout << "Enter your middle name: ";
    getline(cin,middleName);
    cout << "Enter your last name: ";
    getline(cin,lastName);
    cout << "Your initials are "
         << getInitials(firstName,middleName,lastName)
         << ". " << endl;
    return (0);
};
