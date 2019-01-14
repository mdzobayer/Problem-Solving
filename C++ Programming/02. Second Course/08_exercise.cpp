#include <iostream>
using namespace std;
int main(){
    string answer = "Watson";
    string response;
    int tries = 1;
    cout << "Let's play a guessing game."
         << "You get three tries." << endl;
    while (tries <= 3){
        cout << "What is the name of the computer "
             << "that played Jeopardy? ";
        getline(cin, response);
        if (response == answer){
            cout << "That's right!" << endl;
            tries = 4;
        }
        else if (response != answer){
            if (tries == 1){
                cout << "Sorry, try again." << endl;
                ++tries;
            }
            else if(tries == 2){
                cout << "That's still not right. Try one more time."
                     << endl;
                ++tries;
            }
            else if (tries == 3){
                cout << "Sorry, out of tries. "
                     << "The correct answer is Watson." << endl;
                ++tries;
            }
        }
    }
    return (0);
}
