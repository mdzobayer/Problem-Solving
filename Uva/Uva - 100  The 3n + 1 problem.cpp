#include <iostream>
#include <algorithm>
#include <cstdio>
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
/// C Style Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SWAP(a, b) a = a ^ b, b = a ^ b, a = a ^ b;
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

ULL findLength(ULL & n) {
    ULL Count = 1;
    while(n != 1) {
        if (n & 1) { //odd
            n *= 3;
            ++n;
        }
        else { // even
            n >>= 1;
        }
        ++Count;
    }
    return Count;
}

int main() {
    //FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    ULL s, e, n, i, maximum;

    while(cin >> s >> e) {
        printf("%llu %llu ", s, e);
        if (s > e) {
            s ^= e;
            e ^= s;
            s ^= e;
        }
        maximum = 1;
        for (i = s ; i <= e; ++i) {
            n = i;
            maximum = max(maximum, findLength(n));
        }
        printf("%llu\n", maximum);
    }

    return (0);
}
