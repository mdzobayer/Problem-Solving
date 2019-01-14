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

struct pos {
    LLI x, y;
};

int main() {
    FastRead

    double angle, d1, d2, d3;
    pos p1, p2, p3;
    LLI a, b;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
//    a = (p1.x - p2.x, p1.y - p2.y);
//    b = (p1.x - p3.x, p1.y - p3.y);
//    angle = atan2(p2.y - p1.y, p2.x - p1.x) - atan2(p3.y - p1.y, p3.x - p1.x);

    d1 = sqrt(((p1.x - p2.x)*(p1.x - p2.x)) + ((p1.y - p2.y)*(p1.y - p2.y)));
    d2 = sqrt(((p1.x - p3.x)*(p1.x - p3.x)) + ((p1.y - p3.y)*(p1.y - p3.y)));
    d3 = sqrt(((p2.x - p3.x)*(p2.x - p3.x)) + ((p2.y - p3.y)*(p2.y - p3.y)));


    if (d1 == d2) {
        angle = acos ((d2*d2 + d1*d1 - d3*d3) / (2 * d2 * d1));
        //angle = atan2(abs((p2.x - p1.x)*(p3.y - p1.y) - ))
        if (angle == 90) {
            cout << "Yes" << endl;
        }
        else {
            cout << "1No" << endl;
        }
    }
    else if (d1 == d3) {
        angle = acos ((d2*d2 + d1*d1 - d3*d3) / (2 * d2 * d1));
        if (angle == 90) {
            cout << "Yes" << endl;
        }
        else {
            cout << "2No" << endl;
        }
    }
    else if (d2 == d3) {
        angle = acos ((d2*d2 + d1*d1 - d3*d3) / (2 * d2 * d1));
        if (angle == 90) {
            cout << "Yes" << endl;
        }
        else {
            cout << "3No" << endl;
        }
    }
    else {
        cout << "--No" << endl;
    }

    return (0);
}
