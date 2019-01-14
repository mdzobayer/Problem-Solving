#include <bits/stdc++.h>
#define SIZE 1000+5

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int patt[SIZE], i, j, k, test, query, q;
    string pattern, text;
    bool flag;
    while(scanf("%d", &test) == 1) {
        cin.ignore();
        while(test--) {

            getline(cin, text);
            //cout << "text = " << text << endl;
            scanf("%d", &query);
            cin.ignore();
            for (q = 0; q < query; ++q) {
                getline(cin, pattern);
                //cout << "pattern = " << pattern << endl;
                //pattern = "abcaby";
                //pattern = "aabaabaaa";
                //pattern = "abcdabca";
                //text = "abxabcabcabyabcaby";
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
                /*
                for (j = 0; j < i; ++j) {
                    printf("%d ", patt[j]);
                }
                printf("\n");
                */
                /// Pattern Search
                flag = true;
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

                    if( j == pattern.size()) {
                        //cout << "pattern found at " << ( i - j ) << endl ;
                        //j = patt[ j - 1 ];
                        flag = false;
                        break;
                    }

                }
                if (flag) {
                    printf("n\n");
                }
                else {
                    printf("y\n");
                }
            }
        }
    }

    return (0);
}
