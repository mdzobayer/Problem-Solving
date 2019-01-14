#include <bits/stdc++.h>

using namespace std;

int patt[100000+5];

int main() {

    //freopen("in.txt", "r", stdin);

    int i, j, k ;
    string text, pattern;

    while(cin >> text) {
        pattern = "";

        for (i = text.size() - 1; i >= 0; --i) {
            pattern += text[i];
        }
        patt[0] = 0;
        /// preprocessing array.
        for (i = 1, j = 0, k = 0; i < pattern.size(); ) {
            if (pattern[j] == pattern[i]) {
                patt[++k] = j + 1;
                ++j;
                ++i;
            }
            else if (pattern[j] != pattern[i] && j == 0) {
                patt[++k] = 0;
                ++i;
            }
            else {
                j = patt[j - 1];
            }
        }

        /// Pattern Search
        for (i = 0, j = 0, k = 0; i < text.size(); ) {
            if (text[i] == pattern[j]) {
                ++j;
                ++i;
            }
            else if (text[i] != pattern[j] && j == 0) {
                ++i;
                k = i;
            }
            else {
                j = patt[j - 1];
                k += (j+1);
            }

        }
        cout << text;
        if( j < pattern.size()) {
            for (j ; j < pattern.size(); ++j) {
                putchar(pattern[j]);
            }
        }
        cout << endl;

    }

    return (0);
}
