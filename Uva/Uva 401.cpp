#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main() {
    int i;
    char valid[10000];
    memset(valid, 0, sizeof(valid));
    valid['A'] = 'A';
    valid['E'] = '3';
    valid['H'] = 'H';
    valid['I'] = 'I';
    valid['J'] = 'L';
    valid['L'] = 'J';
    valid['M'] = 'M';
    valid['O'] = 'O';
    valid['S'] = '2';
    valid['T'] = 'T';
    valid['U'] = 'U';
    valid['V'] = 'V';
    valid['W'] = 'W';
    valid['X'] = 'X';
    valid['Y'] = 'Y';
    valid['Z'] = '5';
    valid['1'] = '1';
    valid['2'] = 'S';
    valid['3'] = 'E';
    valid['5'] = 'Z';
    valid['8'] = '8';
    string word, a ,b;
    while(cin >> word) {
        a = b = "";

        for ( i = word.length() - 1; i >= 0; i--) {
            a += word[i];
            b += valid[word[i]];
        }
        if(word != a && word != b) cout << word << " -- is not a palindrome." << endl << endl;
        else if(word == a && word != b) cout << word << " -- is a regular palindrome." << endl << endl;
        else if(word != a && word == b) cout << word << " -- is a mirrored string." << endl << endl;
        else cout << word << " -- is a mirrored palindrome." << endl << endl;
    }

    return (0);
}
