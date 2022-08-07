#include <bits/stdc++.h>

using namespace std;



int main() {

    int test;
    string str;
    map<string, int> dictionary;

    cin >> test;
    while(test--) {
        cin >> str;

        if(dictionary.find(str) == dictionary.end()) {
            puts("OK");
            dictionary[str] = 0;
        } else {
            printf("%s%d\n", str.c_str(), ++dictionary[str]);
        }
    }

    return (0);
}