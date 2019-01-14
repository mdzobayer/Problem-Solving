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

struct job {
    int day, fine, pos;

    bool operator < (const job & b) const {
        double x1 = (double) day * b.fine;
        double x2 = (double) b.day * fine;
        if ( x1 != x2 ) {
            return x1 < x2;
        }
        return pos < b.pos;
    }

}jobs[1000+10];



int main() {
    //FastRead

    int test, t, n, i, d, f;
    scanf("%d", &test);
    for (t = 0; t < test; ++t) {
        if (t > 0) putchar('\n');
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &d, &f);
            jobs[i].day = d;
            jobs[i].fine = f;
            jobs[i].pos = i + 1;
        }

        sort(jobs, jobs + n);
        for (i = 0; i < n; ++i) {
            if (i != 0) putchar(' ');
            printf("%d", jobs[i].pos);
        }
        putchar('\n');
    }

    return (0);
}
