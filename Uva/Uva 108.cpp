#include <cstdio>

int n, arr[110][110];

int max (int x, int y) {
    return x > y ? x : y;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int i, j, k, l, current = 0, answer = 0;

    while(scanf("%d", &n) == 1){
        current = answer = -130;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                scanf("%d", &arr[i][j]);
                if (i > 0) arr[i][j] += arr[i - 1][j];
                if (j > 0) arr[i][j] += arr[i][j - 1];
                if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];

            }
        }
        /*
        printf("Calculated Pre-process\n");
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {

            }
        }
        */

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = i; k < n; ++k) {
                    for (l = j; l < n; ++l) {
                       current = arr[k][l];
                       if (i > 0) current -= arr[i - 1][l];
                       if (j > 0) current -= arr[k][j - 1];
                       if (i > 0 && j > 0) current += arr[i - 1][j - 1];
                       answer = max(current, answer);
                    }
                }
            }
        }
        printf("%d\n", answer);
    }

    return (0);
}
