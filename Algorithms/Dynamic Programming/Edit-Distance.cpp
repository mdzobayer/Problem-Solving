#include <cstdio>
#include <cstring>

int dp[100][100];

int min(int x, int y, int z) {
    if (x > y && y < z) {
        return y;
    }
    else if (x < y && x < z) {
        return x;
    }
    else return z;
}

int editDistance(char str1[], char str2[], int m, int n) {
    if (m == 0) {
        return n;
    }

    if (n == 0) {
        return m;
    }
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    else {
        if (str1[m - 1] == str2[n - 1]) {
            return dp[m][n] = editDistance(str1, str2, m - 1, n - 1);
        }
        else {
            return dp[m][n] = 1 + min (editDistance(str1, str2, m, n - 1), /// Insert
                        editDistance(str1, str2, m - 1, n), /// Delete
                        editDistance(str1, str2, m - 1, n - 1)); /// Replace
        }
    }

}

int main() {

    char str1[50] = "sunday";
    char str2[50] = "saturday";

    memset(dp, -1, sizeof(dp));

    printf("Minimum edit Distance : %d\n", editDistance(str1, str2, 7, 9));

    return (0);
}
