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

int main() {
    FastRead
    int test, t, Ox, Oy, Ax, Ay, Bx, By;
    double radius, a, Area, r;
    cin >> test;
    for (t = 1; t <= test; ++t) {
        cin >> Ox >> Oy >> Ax >> Ay >> Bx >> By;
        radius = (Ox - Bx)*(Ox - Bx) + (Oy - By)*(Oy - By);
        radius = sqrt(radius);
        a = (Ax - Bx)*(Ax - Bx) + (Ay - By)*(Ay - By);
        a = sqrt(a);

        r = radius;
        Area = acos((r*r + r*r - a*a) / (2*r*r));

        Area *= r;

        printf("Case %d: %.10f\n", t, Area);
    }

    return (0);
}


/**
        Logic

    r=√(ox−ax)2+(oy−ay)2 &
c=√(ax−bx)2+(ay−by)2

Now, we know all the three distances of △OAB. So, we can calculate the ∠α by applying Cosine Law
α=arccos(b2+c2−a22bc)

Now, we can calculate the arc distance by applying third concept.
Arc Distance=α×r



**/
