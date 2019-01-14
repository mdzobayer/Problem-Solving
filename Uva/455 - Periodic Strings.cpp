#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);


    char pattern[100];
    int test, patt[100], len, i, j, k;
    bool flag = false;

    while(scanf("%d", &test) == 1){
        getchar();
        while(test--) {

            getchar();
            gets(pattern);

            if (flag) printf("\n");
            flag = true;
            len = strlen(pattern);

            /// KMP preprocessing array.
            patt[0] = 0;
            for (i = 1, j = 0, k = 0; i < len; ) {
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
                printf("%d\n", len);
            }
            else {
                printf("%d\n", len - j);
            }
        }
    }
    return (0);
}
