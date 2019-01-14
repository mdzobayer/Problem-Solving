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
#define FastRead std::ios::sync_with_stdio(false);cin.tie(NULL);

///======================== Let's GO ========================

bool prime[1000010];

void sieveOfEratosthenes(ULL n) {

    ULL i, j;

    /// Initialize all numbers as prime
    memset(prime, true, sizeof(prime));

    /// Cross out multiples of 2 (all even numbers less then or equal n without 2)
    for ( i = 4; i <= n; i += 2) {
        if (prime[i])
            prime[i] = false;
    }
    /// Cross out multiples of other true marked number (Ex 3, 5, 7 etc).
    for ( i = 3; i * i <= n; i += 2) {
        if (prime[i]) {
            for ( j = i + i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

}

int main() {

    FastRead

    sieveOfEratosthenes(1000000);
    ULL n, low, high, Count;
    while(scanf("%llu", &n)) {
        if (n == 0) break;
        low = 2; high = n - 1;
        Count = 0;
        while(low <= high) {

            while(!prime[low]) ++low;
            while(!prime[high]) --high;
            if (low + high < n)
                ++low;
            else if (low + high > n)
                --high;
            else {
                ++low;
                ++Count;
            }
        }
        printf("%llu\n", Count);
    }


    return (0);
}
