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
#define N 105
bool matrix[N][N];
bool visited[N];

int n, conn, edge, start, query, source;

void bfs() {
    vector < int > vt;

    queue < int > qt;
    int node, i;
    qt.push(source);
    while(!qt.empty()) {
        node = qt.front();
        qt.pop();
        for (i = 1; i <= n; ++i) {
            if (matrix[node][i] == true && visited[i] == false) {
                visited[i] = true;
                qt.push(i);
            }
        }
    }
    conn = 0;
    for (i = 1; i <= n; ++i) {
        if (visited[i] == false) {
            ++conn;
            vt.push_back(i);
        }
    }
    printf("%d", conn);
    for (i = 0; i < vt.size(); ++i) {
        printf(" %d", vt[i]);
    }
    printf("\n");
}

int main() {
    //FastRead
    //fRead("in.txt");
    int i;

    while(scanf("%d", &n) == 1) {
        if (n == 0) break;
        /// Reset memory
        memset(matrix, false, sizeof(matrix));

        /// Input
        for ( ; scanf("%d", &start) && start; ) {
            while(scanf("%d", &edge) && edge) {
                matrix[start][edge] = true;
            }
        }
        scanf("%d", &query);
        for (i = 0; i < query; ++i) {
            conn = 0;
            memset(visited, false, sizeof(visited));
            scanf("%d", &source);
            /// Play a bfs
            bfs();
        }

    }


    return (0);
}
