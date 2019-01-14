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

    //fRead("in.txt");

    int device[22], n, m, c, maxCon, i, t = 0, sumOfPower, con;
    bool isOn[22], isBlown;
    while(scanf("%d %d %d", &n, &m, &c) == 3) {
        if (n == 0 && m == 0 && c == 0) break;
        for (i = 0; i < n; ++i) {
            scanf("%d", &device[i]);
        }
        isBlown = false;
        memset(isOn, 0, sizeof(isOn));
        sumOfPower = maxCon = 0;
        for (i = 0; i < m; ++i) {
            scanf("%d", &con);
            if (isOn[con - 1]) {
                sumOfPower -= device[con - 1];
                isOn[con - 1] = false;
            }
            else {
                sumOfPower += device[con - 1];
                isOn[con - 1] = true;
            }
            if (sumOfPower > c) isBlown = true;
            if (maxCon < sumOfPower) maxCon = sumOfPower;
        }
        printf("Sequence %d\n", ++t);
        if (isBlown) {
            printf("Fuse was blown.\n\n");
        }
        else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n", maxCon);
        }
    }

    return (0);
}
