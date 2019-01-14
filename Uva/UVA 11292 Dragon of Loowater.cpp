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
vector< int > dragon, knight;
int main() {
    //FastRead

    int n, m, i, x, remain, j, cost;
    bool flag;
    while(scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0) break;
        dragon.clear();
        knight.clear();
        for (i = 0; i < n; ++i) {
            scanf("%d", &x);
            dragon.phb(x);
        }
        for (i = 0; i < m; ++i) {
            scanf("%d", &x);
            knight.phb(x);
        }
        if (n > m) {
            puts("Loowater is doomed!");
            continue;
        }
        sort(dragon.begin(), dragon.end());
        sort(knight.begin(), knight.end());
        remain = m;
        cost = 0;
        for (i = 0, j = 0; i < n; ++i) {
            flag = false;
            for ( ; j < m; ++j) {
                //cout << "--- " << cost << " " << dragon[i] << " " << knight[j] << endl;

                if (dragon[i] <= knight[j]) {
                    cost += knight[j];
                    flag = true;
                    ++j;
                    --remain;
                    break;
                }
            }
            if (flag == false || remain <= 0) {
                flag = false;
                break;
            }
            flag = true;
        }
        if (flag) {
            printf("%d\n", cost);
        }
        else {
            puts("Loowater is doomed!");
        }
    }

    return (0);
}
