#include <bits/stdc++.h>

using namespace std;

int patt[1000000+5];


int main() {

    int test, t;
    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {

        int  i, j, k, cnn = 0, pSize;
        string pattern, text;
        cin >> text >> pattern;

        memset(patt, 0, sizeof(patt));

        pSize = pattern.size();
        patt[0] = 0;

        /// preprocessing array.
        for (i = 1, j = 0, k = 0; i < pSize; ) {
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
        int tSize = text.size();
        for (i = 0, j = 0, k = 0; i < tSize; ) {
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

            if( j == pattern.size()) {
                //cout << "pattern found at " << ( i - j ) << endl ;
                j = patt[ j - 1 ];
                ++cnn;
            }

        }
        printf("Case %d: %d\n", t, cnn);
    }

    return (0);
}
