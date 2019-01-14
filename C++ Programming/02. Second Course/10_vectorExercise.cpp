#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void displayVectorS(vector<string> vect){
    for(int i = 0; i < vect.size(); ++i)
        cout << vect[i];
}

string buildRWord(string word){
    string rword = "";
    vector<string> wrd;
    for(int i = 0; i < word.length(); ++i)
        wrd.push_back(word.substr(i,1));
    reverse(wrd.begin(),wrd.end());
    for(int i = 0; i <wrd.size(); ++i)
        rword += wrd[i];
    return rword;
};

int main(){

    string aword;
    cout << "Enter a word: ";
    cin >> aword;
    string raword = buildRWord(aword);
    if(raword == aword)
        cout << aword << " is a palindrome."
             << endl;
    else
        cout << aword << " is not a palindrome."
             << endl;

    return (0);
};
