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
    //fWrite("out.txt");

    int n, x, y, m, o, i, j, t = 0;
    bool flag;
    char str[1000000 + 10], key;

    while(scanf("%s", &str) == 1) {
        printf("Case %d:\n", ++t);
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &m, &o);
            x = min(m, o);
            y = max(m, o);
            flag = true;
            key = str[x];
            for ( ; x <= y; ++x, --y) {
                if (str[x] != str[y] || str[y] != key) {
                    flag = false;
                    break;
                }
            }
            if (flag) printf("Yes\n");
            else printf("No\n");
        }
    }


    return (0);
}
