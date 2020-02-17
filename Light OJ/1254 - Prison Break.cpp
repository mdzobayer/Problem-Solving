#include <bits/stdc++.h>

using namespace std;

#define SIZE 105

struct Node {
    int id, capa, cos;

    // bool operator < (const Node & b) {
    //     if (this->cos == b.cos) {
    //         return this->capa > b.capa
    //     }
    //     else return this->cos < b.cos;
    // }
};


bool operator < (const Node & a, const Node & b) {
        if (a.cos == b.cos) return a.capa < b.capa;
        else return a.cos > b.cos;
}


vector < pair < int, int > > ajlist[SIZE];

int n, m, fuelPrice[SIZE], cost[SIZE][SIZE], source, destination;

bool visited[SIZE][SIZE];

void dijkstra(int capacity, int source, int destination) {

    int i, node, w, j, x;
    // for (i = 0; i <= n; ++i) {
    //     for (j = 0; j <= SIZE; ++j)
    //         cost[i][j] = INT_MAX;
    // }

    cost[source][0] = 0;

    memset(visited, 0, sizeof(visited));

    priority_queue < Node > pq;
    Node cNode, nNode;

    cNode.capa = 0;
    cNode.cos = 0;
    cNode.id = source;

    pq.push(cNode);

    while(!pq.empty()) {
        cNode = pq.top();

        //printf("poped Node %d capacity %d\n", cNode.id, cNode.capa);

        pq.pop();

        if (visited[cNode.id][cNode.capa]) {
            continue;
        }
        visited[cNode.id][cNode.capa] = true;

        for (i = 0; i < ajlist[cNode.id].size(); ++i) {
            node = ajlist[cNode.id][i].first;
            w = ajlist[cNode.id][i].second;

            if (capacity < w) continue;

            for (j = cNode.capa, x = 0; j <= capacity; ++j, x += fuelPrice[cNode.id]) {
                if (j >= w) {
                    nNode.capa = (j - w);
                    nNode.cos = cNode.cos + x;
                    nNode.id = node;

                    if (cost[nNode.id][nNode.capa] > nNode.cos) {
                        cost[nNode.id][nNode.capa] = nNode.cos;
                        pq.push(nNode);
                    }


                }
            }
        }

    }

//     for (int x : cost[destination]) {
//         cout << x << " ";
//     }
//     cout << endl;

    int ans = cost[destination][0];
    for (i = 1; i < SIZE; ++i) {
        ans = min(ans, cost[destination][i]);
    }

    if (ans == INT_MAX) {
        printf("impossible\n");
    }
    else {
        printf("%d\n", ans);
    }

}


int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, j, u, v, w, query, capacity;
    scanf("%d", &test);

    for (t = 1; t <= test; ++t) {
        
        scanf("%d %d", &n, &m);

        for (i = 0; i <= n; ++i) {
            ajlist[i].clear();
        }

        for (i = 0; i < n; ++i) {
            scanf("%d", &fuelPrice[i]);
        }

        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);

            ajlist[u].push_back(make_pair(v, w));
            ajlist[v].push_back(make_pair(u, w));
        }

        for (i = 0; i <= n; ++i) {
            for (j = 0; j <= SIZE; ++j)
                cost[i][j] = INT_MAX;
        }

        scanf("%d", &query);
        printf("Case %d:\n", t);
        for (i = 0; i < query; ++i) {
            scanf("%d %d %d", &capacity, &source, &destination);
            dijkstra(capacity, source, destination);
        }

    }

    return (0);
}
