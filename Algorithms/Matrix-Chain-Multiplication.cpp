#include <cstdio>
#include <cstring>
#include <climits>

int dp[10][10], arr[] = {1, 2, 3, 4, 3}, n = 5;

int matrixChainMultiplication(int l, int r) {
    if (l == r) return (0);

    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    else {

        int k, min, count;
        min = INT_MAX;

        for (k = l; k < r; ++k) {
            count = matrixChainMultiplication(l, k) +
                    matrixChainMultiplication(k + 1, r) +
                    arr[l - 1] * arr[k] * arr[r];
            if (count < min) min = count;
        }
        return dp[l][r] = min;
    }
}

int main() {
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }


    printf("Minimum number of multiplication %d\n",
           matrixChainMultiplication(1, 4));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }


    return (0);
}
