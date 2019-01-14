#include <cstdio>
#include <cstring>

int max (int x, int y) { return x > y ? x : y;};
int min (int x, int y) { return x < y ? x : y;};

int dp[15][15];

int optimalStrategy(int arr[], int i, int j) {
    if (i == j) {
        return arr[i];
    }
    if (j == i + 1) {
        return max(arr[i], arr[j]);
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    else
    return dp[i][j] = max((arr[i] + min(optimalStrategy(arr, i + 2, j), optimalStrategy(arr, i + 1, j - 1))),
                          (arr[j] + min(optimalStrategy(arr, i, j - 2), optimalStrategy(arr, i + 1, j - 1)))
                         );
}

int main() {
    int arr[] = {8, 15, 3, 7};
    memset(dp, -1, sizeof(dp));
    printf("Max value is %d\n", optimalStrategy(arr, 0, 3));


    return (0);
}
