#include <bits/stdc++.h>
#define SIZE 1000+5
using namespace std;

int dp[SIZE], n;
char s[SIZE];

bool isPalindrome(int l, int r) {

    while(l < r) {
        if(s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

int solve(int p) {
    if(p == n) return 0;

    if(dp[p] != -1) return dp[p];

    int i, result = INT_MAX;
    for (i = p; i < n; ++i) {
        if(isPalindrome(p, i))
            result = min(result, solve(i+1));
    }
    return dp[p] = result + 1;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i;
    scanf("%d", &test);
    getchar();
    for (t = 1; t <= test; ++t) {
        scanf("%s", &s);
        //puts(s);
        n = strlen(s);

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", t, solve(0));
    }

    return (0);
}
