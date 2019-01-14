#include <bits/stdc++.h>
#define SIZE 1010

using namespace std;

char str[SIZE];
int dp[SIZE][SIZE];

int palindromeLength(int l, int r) {
    if (l == r) {
        return 1;
    }
    if (l + 1 == r) {
        if (str[l] == str[r]) {
            return 2;
        }
        else return 1;
    }

    if(dp[l][r] != -1) {
        return dp[l][r];
    }

    if(str[l] == str[r]) {
        dp[l][r] = 2 + palindromeLength(l + 1, r - 1);
    }
    else {
        dp[l][r] = max(palindromeLength(l+1, r), palindromeLength(l, r-1));
    }

    return dp[l][r];
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, len, ans;
    while(scanf("%d", &test) == 1) {
        getchar();
        while(test--) {
            gets(str);
            if (strcmp(str,"") == 0) {
                ans = 0;
            }
            else {
                len = strlen(str);
                //printf("len is %d\n", len);
                memset(dp, -1, sizeof(dp));

                ans = palindromeLength(0, len - 1);
            }
            printf("%d\n", ans);
        }
    }

    return (0);
}
