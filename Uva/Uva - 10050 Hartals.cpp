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

    int test, n, i, p, j, h, Count;
    bool days[3655], isUse[3655];
    scanf("%d", &test);
    while(test--) {
        /// Reset memories
        memset(isUse, 1, sizeof(isUse));
        memset(days, 0, sizeof(days));

        scanf("%d%d", &n, &p);
        for (i = 0; i < p; ++i) {
            scanf("%d", &h);
            /// Cross out multiples && not use again
            if (isUse[h]) {

                for (j = h; j < 3655; j += h) {
                    days[j] = true;
                    isUse[j] = false;
                }
            }
        }
        /// Cross Friday and Saturday
        for (i = 6, j = 7; j < 3655; i += 7, j += 7) {
            days[j] = false;
            days[i] = false;
        }
        Count = 0;
        for (i = 1; i <= n; ++i) {
            if (days[i])
                ++Count;
        }
        printf("%d\n", Count);
    }

    return (0);
}
