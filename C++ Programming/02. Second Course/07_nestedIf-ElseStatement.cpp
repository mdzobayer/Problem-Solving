#include <iostream>
using namespace std;
int main(){

    int age;
    cout << "Enter your age: ";
    cin >> age;
    if (age < 18) {
        cout << "You can't vote yet."<< endl;
        if (age < 16){
            cout << "You can't drive yet either."<< endl;
        }
        else {
            cout << "You can drive." << endl;
        };
    }
    else {
        cout << "You can vote." << endl;
        if(age < 21){
                cout << "Buy you can't drink." << endl;
        }
        else {
            cout << "You can drive and drink. " << endl;
        };
    };
    return (0);

};
