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


int arr[110][110];
int n, m, s, t;

void floadWharshal() {
    int i, j, k;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            for (k = 1; k <= n; ++k) {
                if (arr[j][k] > max(arr[j][i], arr[i][k])){
                    arr[j][k] = max(arr[j][i], arr[i][k]);
                    //arr[j][i] = max(arr[i][j], arr[j][k]);
                }
            }
        }
    }
}

int main() {
    //FastRead

    //fRead("in.txt");

    int test, cas = 0, e, q, a, b, w, i, j;

    while(scanf("%d %d %d", &n, &e, &q) == 3) {

        if (n == 0 && e == 0 && q == 0) break;


        for (i = 0; i < n+5; ++i) {
            for (j = 0; j < n+5; ++j) {
                arr[i][j] = INT_MAX;
            }
        }
        for (i = 0; i < e; ++i) {
            scanf("%d %d %d", &a, &b, &w);
            arr[a][b] = w;
            arr[b][a] = w;
        }
        floadWharshal();
        if (cas > 0) printf("\n");
        printf("Case #%d\n", ++cas);
        for (i = 0; i < q; ++i) {
            scanf("%d %d", &s, &t);
            if (arr[s][t] == INT_MAX) {
                printf("no path\n");
            }
            else printf("%d\n", arr[s][t]);
        }
    }


    return (0);
}
