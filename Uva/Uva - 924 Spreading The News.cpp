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
struct Node {
    int num, level;
    Node() {
        num = 0;
        level = 0;
    }
    void operator = (Node n) {
        this->num = n.num;
        this->level = n.level;
    }
};

vector < int > ajlist[2500+5];
bool visited[2500+5];
int maximum[2500+5], e, d, m;

void bfs(int s) {

    memset(visited, 0, sizeof(visited));
    memset(maximum, 0, sizeof(maximum));

    visited[s] = true;
    int sz, i, j;
    Node newNode, currNode;
    Node tempNode;
    tempNode.num = s;
    tempNode.level = 0;

    queue < Node > q;
    q.push(tempNode);

    while(!q.empty()) {
        currNode = q.front();
        q.pop();

        //cout << "currNode = " << currNode.num << endl;
        sz = ajlist[currNode.num].size();

        for (i = 0; i < sz; ++i) {
            newNode.num = ajlist[currNode.num][i];
            newNode.level = currNode.level + 1;

            if (visited[newNode.num] == false){
                //cout << "newNode = " << newNode.num << endl;
                ++maximum[newNode.level];
                q.push(newNode);

            }
            visited[newNode.num] = true;
        }
    }
    m = 0, d = 0;
    for (i = 0; i < e; ++i) {
        if (maximum[i] > m) {
            m = maximum[i];
            d = i;
        }
    }
    if (m > 0) printf("%d %d\n", m, d);
    else printf("0\n");
}
int main() {
    //FastRead
    //fRead("in.txt");

    int t, n, i, j, s;

    while(scanf("%d", &e) == 1) {

        for (i = 0; i < 2501; ++i) {
            ajlist[i].clear();
        }
        for (i = 0; i < e; ++i) {
            scanf("%d", &n);
            for (j = 0; j < n; ++j) {
                scanf("%d", &m);
                ajlist[i].phb(m);
            }

        }
        scanf("%d", &t);
        //cout << "Debug 1" << endl;
        while(t--) {
            scanf("%d", &s);
            bfs(s);
            //cout << "Debug 2" << endl;
        }
    }

    return (0);
}
