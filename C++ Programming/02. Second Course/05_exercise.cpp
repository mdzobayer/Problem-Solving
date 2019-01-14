#include <iostream>

using namespace std;

int main(){
    string name, present, city, yourName;
    int age;
    cout << "Enter a name: ";
    getline(cin, name);
    cout << "Enter your present they bought: ";
    getline(cin, present);
    cout << "Enter the city they are from: ";
    getline(cin, city);
    cout << "Enter your name: ";
    getline(cin, yourName);
    cout << "Enter your age: ";
    cin >> age;
    cout << endl << endl << endl;

    cout << "Dear "<< name << "," << endl << endl ;
    cout << "Thank you for the " << present <<". "
         <<"I really like it. I can't believe I'm already " << age
         <<" years old, but it doesn't feel that much different than "
         <<"being " << age << " . I hope that some time in the next year we can "
         << "come visit you in " << city << "." << endl <<endl;
    cout << "Thank you again for the " << present << "." << endl << endl;
    cout <<"Sincerely," << endl << endl;
    cout << yourName << endl;

    return (0);
};
