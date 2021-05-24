#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool prime(ll n) {
    if (n < 2) return false;

    for (ll x = 2; x * x <= n; ++x) {
        if (n % x == 0) {
            return false;
        }
    }

    return true;
}

vector< ll > factors(ll n) {
    vector < ll > f;

    for (ll x = 2; x * x <= n; ++x) {
        while(n % x == 0) {
            f.push_back(x);

            n /= x;
        }
    }

    if (n > 0) {
        f.push_back(n);
    }

    return f;
}


int main() {

    vector < ll > factorList =  factors(84);

    for (ll a: factorList) {
        printf("%lld ", a);
    }
    puts("");

    return (0);
}