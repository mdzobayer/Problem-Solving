#include <bits/stdc++.h>


using namespace std;

char s[105];
int dp[105][105];

int genResult(int left, int right) {
    if (left >= right) return 0;

    int & result = dp[left][right];

    if (result != -1) return result;

    if (s[left] == s[right])
        result = genResult(left + 1, right - 1);
    else
        result = min(genResult(left + 1, right) + 1,
                     genResult(left, right - 1) + 1);
    return result;
}

int main() {

    //freopen("in.txt", "r", stdin);
    int test, t, result;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        getchar();
        scanf("%s", &s);
        memset(dp, -1, sizeof(dp));
        result = strlen(s);
        result = genResult(0, result - 1);
        printf("Case %d: %d\n", t, result);
    }

    return (0);
}
