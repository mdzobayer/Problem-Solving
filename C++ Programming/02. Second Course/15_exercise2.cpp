#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand((unsigned)time(NULL));
    int number, guess;
    number = rand() % 10 + 1;
    char cont = 'y';
    do {
        cout << "Guess a number: ";
        cin >> guess;
        if(guess == number) {
            cout << "That's right! " << endl;
            break;
        };
        cout << "Sorry. Do you want to guess again? ";
        cin >> cont;
    } while (cont != 'n');
    return (0);
}
