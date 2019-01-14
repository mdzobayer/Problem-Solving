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
LLI arr[500010];

/// Modified Kadana's Algorithm
int MinimalSubarrayLength (int size, int x) {

    int length = 0, maxEndingHere = 0, minLength = 500010;
    for (int i = 0; i < size; ++i) {
        maxEndingHere += arr[i];
        ++length;
        if (maxEndingHere >= x) {
            if (minLength > length)
                minLength = length;
            length = 0;
            maxEndingHere = 0;
        }
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
            length = 0;
        }
    }
    if (minLength == 500010) {
        return -1;
    }
    else {
        return minLength;
    }
}


int main() {
    FastRead
    //fRead("in.txt");
    LLI test, n, x, i;
    scanf("%lld", &test);
    while(test--) {
        scanf("%lld %lld", &n, &x);
        for (i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
        }
        printf("%d\n", MinimalSubarrayLength(n, x));
    }

    return (0);
}
