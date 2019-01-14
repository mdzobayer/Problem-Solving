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


struct solder {
    LLI bref, time;

    bool operator < (solder x) {
        if (this->time > x.time) {
            return true;
        }
        else if (this->time == x.time) {
            if (this->bref < x.bref)
                return true;
            else return false;
        }
        return false;
    }
};

int main() {
    FastRead
    vector < solder > vt;
    solder tmp;
    LLI n, t = 0, b, p, i;
    while(scanf("%lld", &n) == 1) {
        if (n == 0) break;
        vt.clear();
        for (i = 0; i < n; ++i) {
            scanf("%lld %lld", &b, &p);
            tmp.bref = b;
            tmp.time = p;
            vt.phb(tmp);
        }

        sort(vt.begin(), vt.end());
        b = 0;
        p = 0;

        for (i = 0; i < vt.size(); ++i) {
            //printf("Out %lld %lld\n", vt[i].bref, vt[i].time);
            b += vt[i].bref;
            if (b + vt[i].time > p)
                p = b + vt[i].time;
        }
        printf("Case %lld: %lld\n", ++t, p);
    }
    return (0);
}
