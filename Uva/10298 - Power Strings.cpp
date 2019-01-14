#include <bits/stdc++.h>
#define SIZE 1000005

using namespace std;
char pattern[SIZE];
int test, patt[SIZE], len, i, j;

int main() {

    //freopen("in.txt", "r", stdin);

    while(gets(pattern)) {

        if(strcmp(pattern, ".") == 0) break;

        len = strlen(pattern);

        /// KMP preprocessing array.
        patt[0] = 0;
        for (i = 1, j = 0; i < len; ) {
            if (pattern[j] == pattern[i]) {
                ++j;
                patt[i] = j;
                ++i;
            }
            else if (j == 0) {
                patt[i] = 0;
                ++i;
            }
            else {
                j = patt[j - 1];
            }
        }

        if (len % (len - j)) {
            printf("%d\n", 1);
        }
        else {
            printf("%d\n", len / (len - j));
        }
    }

    return (0);
}
