#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

vector < ll > sieveOfEratosthenes(ll n) {
    bool prime [n + 5];
    memset(prime, true, sizeof(prime));

    ll len, i, j;

    len = sqrt(n + 5);

    for (i = 4; i <= n; i += 2) {
        prime[i] = false;
    }

    for (i = 3; i <= len; i += 2) {
        if (prime[i]) {
            for (j = i * 2; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    vector < ll > primeList;

    for (i = 2; i <= n; ++i) {
        if (prime[i]) {
            primeList.pb(i);
        }
    }

    return primeList;
}

int main() {

    vector < ll > primes = sieveOfEratosthenes(100);

    for (ll a : primes) {
        printf("%lld ", a);
    }
    puts("");

    return (0);
}