#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll binPowRecursive(ll a, ll n) {
    ll x;
    if (n == 0)
        return 1;

    else if (n % 2 == 0) {
        x = binPowRecursive(a, n/2);
        return  x * x;
    }
    else {
        x = binPowRecursive(a, (n-1)/2);
        return x * x * a;
    }
}

ll binPowLoop(ll a, ll n) {
    ll result = 1;

    while (n > 0) {
//        cout << "n = " << n << endl;
//        cout << "a = " << a << endl;
        if (n % 2 == 1) {
            result = result * a;
        }
        a = a * a;
        n >>= 1;
//        cout << "result = " << result << endl << endl;

    }

    return result;
}

ll binPowLoopModule(ll a, ll n, ll m) {
    ll result = 1;
    a = a % m;
    while(n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }

        a = (a * a) % m;
        n >>= 1;
    }

    return result;
}

ll modpow (ll x, ll n, ll m) {
    if (n == 0) {
        return 1 % m;
    }

    ll u = modpow(x , n / 2, m);

    u = (u * u) % m;

    if (n & 1)
        u = (u * x) % m;

    return u;
}

int main() {

    cout << binPowRecursive(3, 7) << endl;
    cout << binPowLoopModule(3, 7, 10) << endl;
    cout << modpow(3, 7, 10) << endl;

    return (0);
}
