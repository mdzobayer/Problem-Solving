#include <bits/stdc++.h>
#define pb push_back

using namespace std;

bool p[5000000+5];
int dp[5000000+5];

void sieve() {

    int i, j;
    memset(p, true, sizeof(p));

    p[0] = p[1] = false;

    for (i = 2; i < 5000001; ++i) {
        if (p[i]) {
            dp[i] += i;
            for (j = i * 2; j < 5000001; j += i) {
                p[j] = false;
                dp[j] += i;
            }
        }
    }
}
/*
//bool isDePrime(const int & x) {
//    int sz = sqrt(x) + 1;
//    int sum = 0, i = 0, y;
//
//    if (p[x]) return true;
//
//    for( ;primes[i] < x; ++i) {
//        if ((x % primes[i]) == 0) {
//            sum += primes[i];
//
////            y = x / primes[i];
////
////            if (p[y])
////                sum += y;
//        }
//    }
//    //cout << sum << endl;
//    if (p[sum]) return true;
//
//    return false;
//}
*/
int main() {

    //freopen("in.txt", "r", stdin);

    sieve();
    //cout << "sieve done" << endl;
    int i, test, a, b;

    dp[0] = dp[1] = 0;

    for (i = 2; i < 5000001; ++i) {
        if (p[dp[i]]) {
            dp[i] = dp[i-1] + 1;
        }
        else dp[i] = dp[i-1];
    }
    //cout << "Range Sum Query done" << endl;

    while(scanf("%d", &a) == 1) {
        if (a == 0) break;

        scanf("%d", &b);
        printf("%d\n", dp[b] - dp[a-1]);
    }

    return (0);
}
