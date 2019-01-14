#include <iostream>

using namespace std;

int main(){

    string firstName, lastName;
    cin >> firstName >> lastName;
    cout << firstName << " " << lastName << endl;

    string fullName;
    cout << "Enter your full name: ";
    //cin >> fullName;
    getline(cin, fullName);
    cout << "Your name is : " << fullName;

    return (0);
};
