#include <bits/stdc++.h>

#define SIZE 350+5
using namespace std;

int n, source, terminal;

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

        for (v = 0; v < SIZE; ++v) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == terminal) return true;
            }
        }
    }
    //cout << "Terminal: " << visited[terminal] << endl;
    return visited[terminal];
}

int fordFulkerson () {
    int maxFlow = 0, pathFlow, v, u;
    int parent[SIZE];
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

int getTShirtSize(const string & s) {
    if (s == "XXL") return 1;
    if (s == "XL") return 2;
    if (s == "L") return 3;
    if (s == "M") return 4;
    if (s == "S") return 5;
    return 6;
}

int main() {

    freopen("in.txt", "r", stdin);

    int test, t, i, color, cl, conn, choice1, choice2;
    string s1, s2;
    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {
        source = 0;
        terminal = 1;
        memset(rGraph, 0, sizeof(rGraph));

        cin >> color >> n;
        cin.ignore();
        //cout << "Color: " << color << " Nodes: " << n << endl;

        for (i = 1; i <= n; ++i) {
            cin >> s1 >> s2;
            //cout << s1 << " " << s2 << endl;

            // for source and terminal
            rGraph[source][i + 1] = 1;

            // for different color with different size
            choice1 = getTShirtSize(s1);
            choice2 = getTShirtSize(s2);
            conn = 0;
            for (cl = 0; cl < color; ++cl) {
                rGraph[i + 1][conn + choice1] = 1;
                rGraph[i + 1][conn + choice2] = 1;

                //rGraph[conn + choice1][i + 1] = 1;
                //rGraph[conn + choice2][i + 1] = 1;

                rGraph[conn + choice1][terminal] = 1;
                rGraph[conn + choice2][terminal] = 1;

                conn += color;
            }
        }
        int ans = fordFulkerson();
        cout << "Case " << t << ": ";
        if (ans == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return (0);
}
