#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll logAtoBaseB(ll a, ll b) {
    return (log(a) / log(b));
}

int main() {

    ll a = 8;
    ll b = 2;

    printf("%lld\n", logAtoBaseB(a, b));

    a = 256;
    b = 4;
    printf("%lld\n", logAtoBaseB(a, b));

    return (0);
}