#include <iostream>

using namespace std;

int main(){

    char letterGrade;
    cout << "Enter your letter Grade: ";
    cin >> letterGrade;
    switch(letterGrade)
    {
    case 'A':
        cout << "An A is in the range of 90 to 100" << endl;
        break;
    case 'B':
        cout << "A B is in the range of 80 to 89" << endl;
        break;
    case 'C':
        cout << "A C is in the range of 70 to 79." << endl;
        break;
    case 'D':
        cout << "A D is in the range of 60 to 69." << endl;
        break;
    case 'F':
        cout << "A F is in the range of 0 to 59." << endl;
        break;
    default:
        cout << "Don't recognize input.";
    };
    return (0);
};
