#include <iostream>

using namespace std;

int main() {
    int test, j;
    cin >> test;
    string dnaSeq, minSeq, newStr;
    while(test--) {
        dnaSeq = "";
        minSeq = "";
        cin >> dnaSeq;
        minSeq = dnaSeq;
        for ( j = 0; j < dnaSeq.size(); ++j) {
            newStr = "";
            newStr = dnaSeq.substr(j + 1) + dnaSeq.substr(0, j + 1);
            if ( newStr < minSeq)
                minSeq = newStr;
        }
        cout << minSeq << endl;
    }

    return (0);
}
