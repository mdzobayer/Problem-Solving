#include <iostream>

using namespace std;

int main(){
    char letterGrade;
    cout << "Enter the letter grade: ";
    cin >> letterGrade;
    switch(letterGrade)
    {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
        cout << "You passed!";
        break;
    case 'F':
        cout << "You failed.";
        break;
    default:
        cout << "I didn't get that grade." << endl;
    };

    return (0);
}
