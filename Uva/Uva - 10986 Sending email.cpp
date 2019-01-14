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

struct node {

    node() {
        no = 0;
        weight = 0;
    }
    int no, newRoad;
    int weight;
    bool operator < (const node &n) {
        if (weight < n.weight) return true;
        else if (weight > n.weight) return false;
        else {
            if (no < n.no) return true;
            else return false;
        }
    }
    node operator = (const node n) {
        this->no = n.no;
        this->weight = n.weight;
    }
};
bool operator < (const node & x, const node & n) {
    if (x.weight > n.weight) return true;
    else if (x.weight <= n.weight) return false;
}

vector < node > ajlist[20000+5];
int n, m, s, t;
bool visited[20000 + 5], found;

void dijkstra() {
    node newNode, currNode;

    memset(visited, false, sizeof(visited));

    currNode.no = s;
    currNode.weight = 0;

    priority_queue < node > pq;
    pq.push(currNode);

    int sz, i, a;
    while(!pq.empty()) {
        currNode = pq.top();
        visited[currNode.no] = true;
        //printf("\ncurrNode = %d cost = %d pqSize = %d\n", currNode.no, currNode.weight, pq.size());
        pq.pop();
        /// Check for Destination
        if (currNode.no == t) {
            found = true;
            printf("%d\n", currNode.weight);
            return;
        }

        a = currNode.no;
        sz = ajlist[a].size();
        for (i = 0; i < sz; ++i) {

            newNode = ajlist[a][i];

            if (visited[newNode.no] == false) {

                newNode.weight += currNode.weight;
                //printf("Pushed %d cost %d\n", newNode.no, newNode.weight);
                pq.push(newNode);
            }
        }

    }
    found = false;
    return ;
}

int main() {
    //FastRead
    //fRead("in.txt");

    node tmp;

    int test, cas = 1, i, a, b, w;
    scanf("%d", &test);
    for (cas = 1; cas <= test; ++cas) {

        scanf("%d %d %d %d", &n, &m, &s, &t);

        /// Clear adjecency List
        for (i = 0; i <= n + 5; ++i) {
            ajlist[i].clear();
        }


        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &w);
            tmp.no = a;
            tmp.weight = w;
            ajlist[b].phb(tmp);

            tmp.no = b;
            ajlist[a].phb(tmp);
        }

        found = false;
        printf("Case #%d: ", cas);
        dijkstra();
        if (found == false) {
            printf("unreachable\n");
        }
    }

    return (0);
}
