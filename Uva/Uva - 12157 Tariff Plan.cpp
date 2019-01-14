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

    int test, t, n, i, time, mile, juice;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        mile = juice = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d", &time);
//            if (time == 0) {
//                mile += 10;
//                juice += 15;
//            }
            mile += ((time / 30) * 10);
            if (time % 30 >= 0) {
                mile += 10;
            }
            juice += ((time / 60) * 15);
            if (time % 60 >= 0) {
                juice += 15;
            }
        }
        //printf("Mile %d Juice %d\n", mile, juice);
        if (mile < juice) {
            printf("Case %d: Mile %d\n", t, mile);
        }
        else if (juice < mile) {
            printf("Case %d: Juice %d\n", t, juice);
        }
        else {
            printf("Case %d: Mile Juice %d\n", t, mile);
        }
    }


    return (0);
}
