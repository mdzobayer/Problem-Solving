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

int main() {
    FastRead

    LLI test, maximum, number, divisor, lower, upper, i, j, range;
    scanf("%lld", &test);
    while(test--) {
        scanf("%lld %lld", &lower, &upper);
        if (lower == 1 && upper == 1) {
            printf("Between 1 and 1, 1 has a maximum of 1 divisors.\n");
            continue;
        }
        maximum = divisor = number = 0;
        for (i = lower; i <= upper; ++i) {
            range = sqrt(i);
            divisor = 0;
            for (j = 1; j <= range; ++j) {
                if (i % j == 0) {
                    //printf("i = %lld j = %lld r = %lld\n", i, j, i / j);
                    ++divisor;
                    if (i / j != j) {
                        ++divisor;
                    }
                }
            }
            if (divisor > maximum) {
                maximum = divisor;
                number = i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",
               lower, upper, number, maximum);
    }

    return (0);
}
