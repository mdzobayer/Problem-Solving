#include <cstdio>
#include <algorithm>
#define lli long long int
#define sl(x) scanf("%lld", &x)

using namespace std;

lli x[1000010], y[1000010], dif[1000010], test, m, l, t, k, n, i, profit;

int main() {

    while(sl(test) == 1) {
        for (t = 1; t <= test; ++t) {
            sl(n);
            sl(k);
            profit = 0;
            for (i = 0; i < n; ++i) {
                sl(x[i]);
            }
            for (i = 0; i < n; ++i) {
                sl(y[i]);
                dif[i] = y[i] - x[i];
            }
            for (i = 0; i < n; ++i) {
                profit += dif[i];
            }
            sort(dif, dif+n);
            for (m = 0; m < k && dif[m] < 0; ++m) {
                profit -= dif[m];
            }
            printf("Case %lld: ", t);
            if (profit > 0) {
                printf("%lld\n", profit);
            }
            else {
                printf("No Profit\n");
            }
        }
    }

    return (0);
}
