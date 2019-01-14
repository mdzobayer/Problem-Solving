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

int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
                  {0,-1,1,0,-1,1,1,-1}};

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


char s[1000+5][1000+5];
int visit[1000+5][1000+5];

int n, m, k;

int dfs( int x, int y) {
    if (x < 0 || y < 0 || (n - 1) < x || (m - 1) < y)
        return (0);



    if (s[x][y] == '*') {
        //printf("called %d %d\n", x, y);
        return 1;
    }
    if (visit[x][y] >= 0) return (visit[x][y]);

    visit[x][y] = 0;

    int cost = 0, i;

    for (i = 0; i < 4; ++i) {
        cost += dfs(x+dir[0][i], y+dir[1][i]);
    }
    return visit[x][y] = cost;
}

int main() {

    //fRead("in.txt");

    int x, y, i, j, cost = 0;

    scanf("%d %d %d", &n, &m, &k);
    //printf("n m k %d %d %d\n", n, m, k);
    getchar();
    for (i = 0; i < n; ++i) {
        scanf("%s", &s[i]);
        //puts(s[i]);
    }
    //cout << k << endl;
    for (i = 0; i < k; ++i) {
        scanf("%d %d", &x, &y);
        //printf("Debug input %d %d\n", x, y);
        memset(visit, -1, sizeof(visit));
        cost = 0;
        cost = dfs(x-1,y-1);
        printf("%d\n", cost);
    }

    return (0);
}
