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
#define N 30
bool ajMat[N][N], visited[N];
int conn;
void bfs(int x, const int & n) {
    int curNode, newNode, i;
    queue < int > q;
    q.push(x);
    visited[x] = false;
    while(!q.empty()) {
        curNode = q.front();
        q.pop();
        for (i = 0; i <= n; ++i) {
            if (visited[i] && ajMat[curNode][i]) {
                q.push(i);
                visited[i] = false;
            }
        }
    }
}
//void printVis(const int &n) {
//
//    for (int i = 0; i <= n; ++i) {
//        printf("%d ", visited[i]);
//    }
//    puts("");
//}
int main() {
    //FastRead
    //fRead("in.txt");
    //fWrite("out.txt");
    int test, t, x, y, i, n;
    string s;
    cin >> test;
    cin.ignore();
    getline(cin,s);
    for (t = 0; t < test; ++t) {

        if (t > 0) puts("");

        memset(ajMat, false, sizeof(ajMat));
        memset(visited, false, sizeof(visited));
        conn = 0;
        getline(cin, s);
        x = (s[0] - 'A');
        n = x;
        for (i = 0; i <= n; ++i) {
            visited[i] = true;
        }
        while(getline(cin, s)) {
            if (s == "") break;
            x = s[0] - 'A';
            y = s[1] - 'A';
            ajMat[x][y] = ajMat[y][x] = true;
            visited[x] = visited[y] = true;
        }

        for (i = 0; i <= n; ++i) {
            if (visited[i]) {
                ++conn;
                bfs(i, n);
            }
        }
        printf("%d\n", conn);
    }

    return (0);
}
