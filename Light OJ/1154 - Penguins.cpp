#include <bits/stdc++.h>
#define SIZE 250
#define INTMAX 100000000

using namespace std;

struct icePiece {
    int x, y, ni, mi, inpost, outpost;
};
vector < int > ajlist [SIZE];
int n, source, terminal, rGraph[SIZE][SIZE], graph[SIZE][SIZE], maxNode;
double d;
icePiece ice[100+5];
vector < int > possibleIces;

double square(const double & x) {
    return x * x;
}
bool iceToIce(const int & i, const int & j) {
    return  (d >= sqrt(square(ice[i].x - ice[j].x) + square(ice[i].y - ice[j].y)));
}

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

        for (v = 0; v < maxNode; ++v) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                //cerr << "cNode = " << u << " nextNode = " << v << endl;
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == terminal) return true;
            }
        }
    }

    return (visited[terminal] == true);
};

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, t, i, j, k, total, len, pathLen;

    int maxFlow, pathFlow, v, u;
    int parent[SIZE];

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %lf", &n, &d);

        //memset(rGraph, 0, sizeof(rGraph));
        memset(graph, 0, sizeof(graph));
        total = 0;
        source = 1;

        int nodeNum = 4;
        for (i = 1; i <= n; ++i) {
            scanf("%d %d %d %d", &ice[i].x, &ice[i].y, &ice[i].ni, &ice[i].mi);
            //cerr << ice[i].x << " " << ice[i].y << " " << ice[i].ni << " " << ice[i].mi << endl;
            ice[i].inpost = ++nodeNum;
            ice[i].outpost = ++nodeNum;

            total += ice[i].ni;

            graph[ice[i].inpost] [ice[i].outpost] = ice[i].mi;
            graph[source][ice[i].inpost] = ice[i].ni;
        }

        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                if (i == j) continue;

                if(iceToIce(i, j)) {
                    //cerr << "iceToIce = " << i << " " << j << endl;
                    graph[ice[i].outpost][ice[j].inpost] = INT_MAX;
                    graph[ice[j].outpost][ice[i].inpost] = INT_MAX;
                }
            }
        }

        possibleIces.clear();
        maxNode = 2 * n + 6;
        for (i = 1; i <= n; ++i) {

            terminal = ice[i].inpost;
            //rGraph[source][terminal] = 0;
            //memset(rGraph, 0, sizeof(rGraph));

            for (j = 0; j < maxNode; ++j) {
                for (k = 0; k < maxNode; ++k) {
                    rGraph[j][k] = graph[j][k];
                }
            }
            maxFlow = 0;
            //cerr << "MaxFlow = " << maxFlow << endl;

            while(bfs(parent)) {
                pathFlow = INT_MAX;
                pathLen = 0;

                for (v = terminal; v != source; v = parent[v]) {
                    u = parent[v];
                    pathFlow = min(pathFlow, rGraph[u][v]);
                    ++pathLen;
                }
                //cerr << "pathFlow = " << pathFlow << endl;
                for (v = terminal; v != source; v = parent[v]) {
                    u = parent[v];
                    rGraph[u][v] -= pathFlow;
                    rGraph[v][u] += pathFlow;
                }

                //if (parent[terminal] == source) continue;

                //pathFlow += ;
                //pathFlow += ;

                maxFlow += pathFlow;

            }

            //printf("Total = %d maxFlow = %d\n", total, maxFlow);
            if(total == maxFlow) {
                possibleIces.push_back(i);
            }

        }

        len = possibleIces.size();
        printf("Case %d:", t);
        if (len == 0) {
            printf(" -1\n");
        }
        else {
            for (i = 0; i < len; ++i) {
                printf(" %d", possibleIces[i] - 1);
            }
            printf("\n");
        }
    }

    return (0);
}
