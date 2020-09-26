#include <bits/stdc++.h>

using namespace std;

int main () {

    // freopen("in.txt", "r", stdin);

    int test, n, i, j, k, l, count, arr[20][20];

    scanf("%d", &test);

    while(test--) {
        scanf("%d", &n);

        count = 0;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = i; k < n; ++k) {
                    for (l = j; l < n; ++l) {
                        if (arr[i][j] > arr[k][l]) {
                            ++count;
                        }
                    }
                }
            }
        }

        printf("%d\n", count);
    }


    return (0);
}