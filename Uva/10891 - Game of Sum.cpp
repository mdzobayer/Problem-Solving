#include <bits/stdc++.h>

using namespace std;

int arr[110], n, i, dp[110][110];
bool done[110][110];

int easyGame(int left, int right) {
    if (left > right) {
        return 0;
    }
    if (done[left][right] == true) return dp[left][right];

    int i, maximum = INT_MIN;
    for (i = left; i <= right; ++i) {
        maximum = max (maximum, (arr[i] - arr[left - 1]) - easyGame(i + 1, right));
        maximum = max (maximum, (arr[right] - arr[i - 1]) - easyGame(left, i - 1));
    }
    done[left][right] = true;
    return dp[left][right] = maximum;
}

int main() {

    //freopen("in.txt", "r", stdin);

    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        memset(done, false, sizeof(done));

        arr[0] = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            arr[i] += arr[i - 1];
        }

        printf("%d\n", easyGame(1, n));
    }

    return (0);
}
