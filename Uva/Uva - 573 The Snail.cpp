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

    int day;
    double h, f, d, u, cHeight, canClimbDay, hAfterClimb, hAfterSlide;
    while(cin >> h >> u >> d >> f) {
        if (h == 0) break;
        day = 0;
        hAfterClimb = hAfterSlide = 0;
        f = f / 100.0;
        //cout << "F is " << f << endl;
        canClimbDay = u;
        cHeight = u;
        //cout << "Height " << cHeight << endl;
        while(true) {
            if (cHeight < 0) {
                cHeight = 0;
            }
            hAfterClimb += cHeight;
            hAfterSlide += (cHeight - d);

            if (hAfterClimb > h) {
                cout << "success on day " << day+1 << endl;
                break;
            }
            if (hAfterSlide < 0) {
                cout << "failure on day " << day + 1 << endl;
                break;
            }

            hAfterClimb -= d;
            cHeight = cHeight - (f * canClimbDay);
            ++day;
        }
    }

    return (0);
}
