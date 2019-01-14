#include <iostream>

using namespace std;

int main(){

    string answer = "Watson";
    string response;

    cout << "Let's play a guessing game. "
         << "You get three tries." << endl;
    label:
    cout << "Computer that played Jeopardy?";
    getline(cin,response);
    if(response == answer) {
        cout << "That's right!" << endl;
    }
    else {
        cout << "No, that's not right. Try again." << endl;
        goto label;
    };

    return (0);
};
