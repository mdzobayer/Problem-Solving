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

int main() {

    FastRead

    LLI b1, i, b2, b3, g1, g2, g3, c1, c2, c3, arr[8], minValue, minIndex;
    while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3) {
        arr[0] = b2 + b3 + c1 + c3 + g1 + g2;
        arr[1] = b2 + b3 + g1 + g3 + c1 + c2;

        arr[2] = c2 + c3 + b1 + b3 + g1 + g2;
        arr[3] = c2 + c3 + g1 + g3 + b1 + b2;

        arr[4] = g2 + g3 + b1 + b3 + c1 + c2;
        arr[5] = g2 + g3 + c1 + c3 + b1 + b2;

        minValue = arr[0];
        minIndex = 0;

        for (i = 1; i < 6; ++i) {
            if ( minValue > arr[i]) {
                minValue = arr[i];
                minIndex = i;
            }
        }
        if (minIndex == 0) {
            printf("BCG %lld\n", minValue);
        }
        else if (minIndex == 1) {
            printf("BGC %lld\n", minValue);
        }
        else if (minIndex == 2) {
            printf("CBG %lld\n", minValue);
        }
        else if (minIndex == 3) {
            printf("CGB %lld\n", minValue);
        }
        else if (minIndex == 4) {
            printf("GBC %lld\n", minValue);
        }
        else if (minIndex == 5) {
            printf("GCB %lld\n", minValue);
        }
    }

    return (0);
}
