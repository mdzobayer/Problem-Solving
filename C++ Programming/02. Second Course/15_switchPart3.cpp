#include <iostream>

using namespace std;
bool isVowel(char letter){
    switch(letter)
    {
    case 'a': case 'A': case 'e': case 'E':
    case 'i': case 'I': case 'o': case 'O':
    case 'u': case 'U':
        return true;
        break;
    default:
        return false;
    };
};

int main(){

    string sentence;
    char ltr;
    int numVowels = 0;
    int sentenceSize = 0;
    cout << "Enter a sentence: ";
    getline(cin,sentence);
    sentenceSize = sentence.size();//sizeof(sentence);
    cout << sentenceSize << endl;
    for(int i = 0; i < sentence.size(); ++i){
        ltr = sentence[i];
        if (isVowel(ltr))
            ++numVowels;
    };
    cout << "There are " << numVowels
         << " vowels in the sentence. " << endl;

    return (0);
}
