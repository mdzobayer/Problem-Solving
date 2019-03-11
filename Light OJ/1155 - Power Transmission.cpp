// Input
/*



*/


#include <bits/stdc++.h>

using namespace std;
#define SIZE 250
struct node {
    int capacity, inpost, outpost;
};

int rGraph[SIZE][SIZE], source, terminal;

bool bfs(int parent[SIZE]) {

    bool visited[SIZE];
    memset(visited, false, sizeof(visited));

    //cerr << "BFS - " << "source = " << source << " terminal = " << terminal << endl;

    queue < int > q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    int u, v, i;
    while(!q.empty()) {
        u = q.front();
        q.pop();

        for (v = 0; v < SIZE; ++v) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                //cerr << "cNode = " << u << " nextNode = " << v << endl;
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[terminal] == true);
};

int fordFulkerson() {
    int maxFlow = 0, pathFlow, v, u;
    int parent[SIZE];

    //cerr << "From Ford" << endl;

    while(bfs(parent)) {
        pathFlow = INT_MAX;

        for (v = terminal; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }
        //cerr << "pathFlow = " << pathFlow << endl;
        for (v = terminal; v != source; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;

    }

    return maxFlow;
}
node regulators[100+5];

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, regulator, i, nodeNum, edges, u, v, capa, x, barishal, dhaka;



    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {

        memset(rGraph, 0, sizeof(rGraph));

        scanf("%d", &regulator);

        nodeNum = 4;    // Spliting nodes
        for (i = 0; i < regulator; ++i) {
            scanf("%d", &regulators[i + 1].capacity);
            regulators[i+1].inpost = ++nodeNum;
            regulators[i+1].outpost = ++nodeNum;

            //cerr << "RegulatorNo : " << i + 1 << " inpost : " << nodeNum - 1 << " outpost : " << nodeNum << " Capacity = " << regulators[i + 1].capacity << endl;

            // Node spliting
            rGraph[regulators[i+1].inpost][regulators[i+1].outpost] = regulators[i + 1].capacity;
        }
        scanf("%d", &edges);
        for (i = 0; i < edges; ++i) {
            scanf("%d %d %d", &u, &v, &capa);

            rGraph[regulators[u].outpost][regulators[v].inpost] = capa;
        }
        scanf("%d %d", &barishal, &dhaka);
        source = 1;
        terminal = 2;

        for (i = 0; i < barishal; ++i) {
            scanf("%d", &x);
            rGraph[source][regulators[x].inpost] = INT_MAX;
        }

        for (i = 0; i < dhaka; ++i) {
            scanf("%d", &x);
            rGraph[regulators[x].outpost][terminal] = INT_MAX;
        }


        int ans = fordFulkerson();

        printf("Case %d: %d\n", t, ans);

    }

    return (0);
};
