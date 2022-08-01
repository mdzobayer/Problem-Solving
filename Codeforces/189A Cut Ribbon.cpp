#include <bits/stdc++.h>

using namespace std;

int n, arr[3], dp[5][4000+5];

int solve(int pos, int remain) {
    if (pos > 2 || remain < 0) return (0);

    if (remain == 0) {
        return (1);
    }

    if (dp[pos][remain] != -1) {
        return dp[pos][remain];
    }


    int a = solve(pos, remain - arr[pos]) > 0 ? solve(pos, remain - arr[pos]) + 1 : 0;
    int b = solve(pos + 1, remain - arr[pos]) > 0 ? solve(pos + 1, remain - arr[pos]) + 1 : 0;
    int c = solve(pos + 1, remain) > 0 ? solve(pos + 1, remain) : 0;


    int result = max(a, b);
    result = max(result, c);
    
    return dp[pos][remain] = result;
}

int main() {

    memset(dp, -1, sizeof(dp));
    cin >> n >> arr[0] >> arr[1] >> arr[2];

    cout << solve(0, n) - 1 << endl;

    return (0);
}