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
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

bool isSame(int x, int y) {
    //printf("%d %d\n", x, y);
    bool used[11];
    int rs;
    memset(used, 0, sizeof(used));
    if(y < 9999) used[0] = true;
    while(x > 0) {
        rs = x % 10;
        if (used[rs]) return false;
        used[rs] = true;
        x /= 10;
    }

    while(y > 0) {
        rs = y % 10;
        if (used[rs]) return false;
        used[rs] = true;
        y /= 10;
    }
    return true;
}

int main() {
    FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    bool foundSolution;
    int n, i, r, j;

    while(cin >> n) {
        if (n == 0) break;
        foundSolution = false;
        for (i = 10000; i < 99999; ++i) {
            for (j = 1000; j <= i; ++j) {
                r = i / j;
                if (r == n && (r * j) == i && isSame(i, j)) {
                    //if ()
                    printf("%d / %d = %d\n", i, j, r);
                    foundSolution = true;
                }
            }
        }
        if (!foundSolution) {
            printf("There are no solutions for %d.\n", n);
        }
    }


    return (0);
}
