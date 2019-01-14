#include <cstdio>
#include <cstring>

int max (int x, int y) {return x > y ? x : y;}

char str1[] = "AGGTAB", str2[] = "GXTXAYB";

/// Top down approach
int dp[500][500];
int lcs (int i, int j) {
    if (i <= 0 || j <= 0) {
        return (0);
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (str1[i - 1] == str2[j - 1]) {
        return dp[i][j] = 1 + lcs(i - 1, j - 1);
    }
    else {
        return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
    }
}

int LCS(int x, int y) {
    int table[x + 1][y + 1], i, j;

    for (i = 0; i <= x; ++i) {
        for (j = 0; j <= y; ++j) {
            if(i == 0 || j == 0) {
                table[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table[x][y];
}

int main() {
    memset(dp, -1, sizeof(dp));
    printf("Length is %d\n", LCS(strlen(str1), strlen(str2)));

    return (0);
}
