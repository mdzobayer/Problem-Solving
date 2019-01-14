#include <iostream>
using namespace std;

bool isEven(int number){
    return ((number % 2) == 0);
}
bool isVowel(char letter){
    if((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u'))
        return true;
    else
        false;
}

int main(){
    /*
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if(isEven(num))
        cout << num << " is even. " << endl;
    else
        cout << num << " is odd. " << endl;
    */
    char ltr;
    cout << "Enter a letter: ";
    cin >> ltr;
    if(isVowel(ltr))
        cout << ltr << " is a vowel." << endl;
    else
        cout << ltr << " is a consonant. " << endl;
    return (0);
}
