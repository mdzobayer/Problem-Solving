#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// Orbit counting theorem
// Burnside's lemma

ll countDistinctWays(ll n, ll m) {

    ll ans = 0, gcd;
    
    for (ll k = 0; k < n; ++k) {
        gcd = __gcd(k, n);
        ans += pow(m, gcd);
    }

    ans /= n;

    return ans;
}

int main() {

    ll n = 4, m = 3;

    cout << countDistinctWays(n, m) << endl;

    return (0);
}