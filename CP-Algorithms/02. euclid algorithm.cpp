#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll gcdRecursive(ll a, ll b) {
    return b ? gcdRecursive(b, a%b) : a;
}

ll gcdLoop(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcdLoop(a, b) * b;
}

ll binaryGcd(ll a, ll b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);

    do {
        b >>= __builtin_ctz(b);
        if (a > b) {
            swap(a, b);
        }
        b -= a;
    } while (b);

    return a << shift;
}

int main() {

    printf("%lld\n", gcdLoop(12, 18));
    printf("%lld\n", binaryGcd(12, 18));

}