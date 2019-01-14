#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

int sumOfFactor[1000 + 5];

void calc() {
    int sum, range, i, j;
    memset(sumOfFactor, -1, sizeof(sumOfFactor));

    for (i = 1; i <= 1000; ++i) {
        sum = 0;
        range = sqrt(i);
        for (j = 1; j <= range; ++j) {
            if (i % j == 0) {
                sum += j;
                if (i / j != j) {
                    sum += (i / j);
                }
            }
        }
        if (sum <= 1000)
            sumOfFactor[sum] = i;
    }
}

int main() {
    FastRead

    calc();
    int t = 0, n;

    while(scanf("%d", &n) == 1) {
        if (n == 0) break;

        printf("Case %d: %d\n", ++t, sumOfFactor[n]);
    }

    return (0);
}
