#include <bits/stdc++.h>
#define SIZE 100+5
using namespace std;

int n, source, terminal, c;

int rGraph[SIZE][SIZE];

bool bfs(int parent[SIZE]) {

    //cout << "BFS Called" << endl;
    //cout << "Source: " << source << " Terminal: " << terminal << endl;

    bool visited[SIZE];
    memset(visited, false, sizeof(visited));

    queue < int > q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    int u, v, i;
    while(!q.empty()) {
        u = q.front();
        //cout << "u = " << u << endl;
        q.pop();

        for (v = 0; v <= n; ++v) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    //cout << "Terminal: " << visited[terminal] << endl;
    return (visited[terminal] == true);
}

int fordFulkerson () {
    int maxFlow = 0, pathFlow, v, u;
    int parent[n+5];
    // for (u = 0; u <= n; ++u) {
    //     for (v = 0; v <= n; ++v) {
    //         rGraph[u][v] = graph[u][v];
    //     }
    // }

    while(bfs(parent)) {

        pathFlow = INT_MAX;
        for (v = terminal; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (v = terminal; v != source; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, i, t, u, v, w;
    t = 0;

    while(scanf("%d", &n)) {
        if(n == 0) break;

        // Clear rGraph list
        memset(rGraph, 0, sizeof(rGraph));

        scanf("%d %d %d", &source, &terminal, &c);

        for (i = 0; i < c; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            rGraph[u][v] += w;
            rGraph[v][u] += w;
            //ajlist[u].push_back(make_pair(v, w));
            //ajlist[v].push_back(make_pair(u, w));
        }
        // Find max Flow
        cout << "Network " << ++t << endl;
        cout << "The bandwidth is " << fordFulkerson() << "." << endl << endl;

    }

    return (0);
}
