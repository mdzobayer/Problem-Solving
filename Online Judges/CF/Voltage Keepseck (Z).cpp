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
/// C Style Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SWAP(a, b) a = a ^ b, b = a ^ b, a = a ^ b;
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)

//int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
//                  {0,-1,1,0,-1,1,1,-1}};

//int knight[2][8] = {{-2,-2,-1,1,2,2,1,-1},
//                    {-1,1,2,2,1,-1,-2,-2}};
//bool sevenSegment[8][10] =
//{
//    {0,0,0,0,0,0,0,0,0,0}, ///Segment 0
//    {1,0,1,1,0,1,1,1,1,1}, ///Segment 1
//    {1,1,1,1,1,0,0,1,1,1}, ///Segment 2
//    {1,1,0,1,1,1,1,1,1,1}, ///Segment 3
//    {1,0,1,1,0,1,1,0,1,1}, ///Segment 4
//    {1,0,1,0,0,0,1,0,1,0}, ///Segment 5
//    {1,0,0,0,1,1,1,0,1,1}, ///Segment 6
//    {0,0,1,1,1,1,1,0,1,1}  ///Segment 7
//};
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(NULL);

///======================== Let's GO ========================

#define MKV 1e-7

class aDevice{
public:
    LLI a, b;
    aDevice(){
        a = 0;
        b = 0;
    }
    modify(LLI aa, LLI bb) {
        a = aa;
        b = bb;
    }
};
LLI n, p, i, requare = 0;
vector < aDevice > devices;

double costXTime(double x) {
    cout << "I am called " << x << endl;
    double i, range = devices.size(), cost = 0;
    for (i = 0; i < range; ++i) {
        cost += devices[i].a * x;
    }
    return cost;
}

double binarySearch() {
    double anss = 0, low = 0, mid, high = 100000+10, power, cost;
    cout << low << " " << high << endl;
    while(low + MKV < high) {
        mid = (low + high) / 2.0;
        power = p * mid;
        cost = costXTime(mid);
        if (power >= cost) {
            anss = mid;
            low = mid;
            cout << "Found a solution" << endl;
        }
        else {
            high = mid;
        }

    }
    return anss;
}

int main() {
    FastRead

    aDevice tmpDevice;
    double anss;

    cin >> n >> p;
    for (i = 0; i < n; ++i) {
        cin >> tmpDevice.a;
        cin >> tmpDevice.b;
        requare += tmpDevice.b;
        devices.phb(tmpDevice);
    }

    if (requare < p) {
        printf("-1\n");
    }
    else {
        anss = binarySearch();
        printf("%0.8f\n", anss);
        cout << anss << endl;
    }

    return (0);
}
