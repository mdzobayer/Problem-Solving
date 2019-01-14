#include <bits/stdc++.h>

using namespace std;
#define ll long long int


typedef pair<int, int> P;

struct comp {
    bool operator()(const P& a, const P& b){
        return (a.first > b.first);
    }
};

vector < pair < int, int > > ajlist[200000+5];
ll totalCost, currentCost;
bool visit[200000+5];

//bool operator < (pair < int , int > A, pair < int , int > B) {
//    return A.first < B.first;
//}


void prims(int n) {
    memset(visit, 0, sizeof(visit));
    int x, y, z, sz, i;
    pair < int , int > currNode, newNode;
    currentCost = 0;
    priority_queue < P, vector < P >, comp > pq;

    pq.push({0,0});

    while(!pq.empty()) {

        currNode = pq.top();
        pq.pop();

        z = currNode.first;
        x = currNode.second;

        if (visit[x]) {
            continue;
        }
        visit[x] = true;
        //cout << "Poped " << x << " length " << z << endl;
        currentCost += z;


        if (n == 0) break;
        --n;
        sz = ajlist[x].size();
        for (i = 0; i < sz; ++i) {
            y = ajlist[x][i].first;
            z = ajlist[x][i].second;
            pq.push({z, y});
            //cout << "---Pushed " << z << " " << y << endl;
        }
    }
    //cout << "Total " << totalCost << endl;
    printf("%lld\n", totalCost - currentCost);
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i, m, n, x, y, z;

    while(scanf("%d %d", &m, &n) == 2) {
        if (n == 0 && m == 0) break;
        totalCost = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            ajlist[x].push_back({y, z});
            ajlist[y].push_back({x, z});
            totalCost += z;
        }
        prims(n);
    }


    return (0);
}

