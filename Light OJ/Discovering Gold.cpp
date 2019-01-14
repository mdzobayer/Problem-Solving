#include <bits/stdc++.h>

using namespace std;

int n;
double dp[110], arr[110];

double calcu(int pos) {

    if (pos == n) {
        return 0.0;
    }

    if (dp[pos] >= 0.0) {
        return dp[pos];
    }
    double res = 0.0;
    int i, conn = 0;
    dp[pos] = 0;
    for ( i = 1; i <= 6; ++i) {
        if (pos + i <= n) {
            res += arr[pos + i] + calcu(pos + i);
        }
        else ++conn;
    }

    return dp[pos] = (res / (6.0 - conn));
}

int main() {

    //freopen("in.txt", "r", stdin);

    int i,test, t, j;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%lf", &arr[i]);
        }
//        for (j = 1; j <= 110; ++j) {
//            dp[j] = -1.0;
//        }
        memset(dp, -1.0, sizeof(dp));
        double result = arr[1] + calcu(1);
        printf("Case %d: %f\n", t, result);
        //cout << arr[1] + calcu(1) << endl;
    }


    return (0);
}

