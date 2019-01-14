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

int remain(int x) {
    if (x == 1) return 2;
    else if (x == 2 || x == 3) return 4;
    return 0;
}

int main() {
    FastRead

    int x, y, ans;
    while(scanf("%d %d", &x, &y) == 2) {
        if (x == 0 && y == 0) break;
        else if (x == 1 || y == 1) ans = x * y;
        else if (x == 2 || y == 2) {
            ans = ((x * y) / 2);
            ans = ((ans / 4) * 4) + remain(ans % 4);
        }
        else {
            ans = ((x * y) + 1) / 2;
        }
        printf("%d knights may be placed on a %d row %d column board.\n",
               ans, x, y);
    }

    return (0);
}
