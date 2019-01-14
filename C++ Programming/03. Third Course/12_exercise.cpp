#include <iostream>

using namespace std;

int find(string word, char lookedFor) {
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == lookedFor) {
            return i;
        }
    }
    return -1;
}
string replace(string word, char oldChar, char newChar) {
    int pos = find(word, oldChar);
    word = word.substr(0,pos) + newChar + word.substr(pos+1);
    return word;
}

int main() {

    string word = "hello";
    cout << find(word,'o') << endl;

    string oldWord = "word";
    string newWord = replace(oldWord,'d','k');
    cout << "Old Word: " << oldWord << endl
         << "New Word: " << newWord << endl;

    return (0);
}
